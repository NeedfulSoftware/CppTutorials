/*
    Copyright (c) 2019 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include <iostream>

// A simple class that encapsulates an int.
// Each function prints a message when called so that we can confirm which ones
// are called and which ones aren't.
class A
{
public:
    // Converting constructor
    A(int n);

    // Copy constructor
    A(const A& other);

    // Move constructor
    A(A&& other);

    // Assignment operator
    A& operator=(const A& other);

    // User-defined conversion function
    operator int() const;

private:
    int m_data;
};

A::A(int n)
    : m_data(n)
{
    std::cout << "A::A(int n) called with n=" << n << std::endl;
}

A::A(const A& other)
    : m_data(other.m_data)
{
    std::cout << "A::A(const A& other) called with other.m_data=" << other.m_data << std::endl;
}

A::A(A&& other)
    : m_data(other.m_data)
{
    std::cout << "A::A(A&& other) called with other.m_data=" << other.m_data << std::endl;
}

A& A::operator=(const A& other)
{
    std::cout << "A::operator=(const A& other) called with other.m_data=: " << other.m_data << std::endl;
    return *this;
}

A::operator int() const
{
    std::cout << "A::operator int() const called with m_data=" << m_data << std::endl;
    return m_data;
}

int main(int argc, char* argv[])
{
    // The 3 expressions below are equivalent and will call the A::A(int n) constructor

    std::cout << "A(1): " << std::endl;
    // Explicit type conversion (functional notation)
    A(1);
    std::cout << std::endl;

    std::cout << "(A)2: " << std::endl;
    // Explicit type conversion (cast notation)
    (A)2;
    std::cout << std::endl;

    std::cout << "static_cast<A>(3): " << std::endl;
    // Explicit type conversion (static_cast)
    static_cast<A>(3);
    std::cout << std::endl;


    // The 3 expressions below are equivalent and will call the A::int() function
    // (after a call to A::A(int n) to construct the instance of A)

    std::cout << "(int)A(4): " << std::endl;
    // Explicit type conversion (functional notation)
    (int)A(4);
    std::cout << std::endl;

    std::cout << "int(A(5)): " << std::endl;
    // Explicit type conversion (cast notation)
    int(A(5));
    std::cout << std::endl;

    std::cout << "static_cast<int>(A(6)): " << std::endl;
    // Explicit type conversion (static_cast)
    static_cast<int>(A(6));
    std::cout << std::endl;

    return 0;
}
