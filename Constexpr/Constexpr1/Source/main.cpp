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

// Straightforward constexpr function: we return a constant literal
constexpr int ConstantNumberV1()
{
    return 1;
}

// This constexpr function takes an argument so it can only be executed at
// compile time if the argument is itself known at compile time. 
constexpr int ConstantNumberV2(int n)
{
    return n;
}

// This constexpr function calls another constexpr function as part of its
// execution
constexpr int ConstantNumberV3(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return (1 + ConstantNumberV2(n-1));
    }
}

int main(int argc, char* argv[])
{
    // Use the various constexpr functions to declare an array to show they
    // can be computed at compile time

    char array1[ConstantNumberV1()];
    std::cout << "Size of array1: " << sizeof(array1) << std::endl;

    char array2[ConstantNumberV2(2)];
    std::cout << "Size of array2: " << sizeof(array2) << std::endl;

    const int n = 3;
    char array3[ConstantNumberV2(n)];
    std::cout << "Size of array3: " << sizeof(array3) << std::endl;

    // This would not compile because the variable is not const
    /*
    int m = 4;
    char array4[ConstantNumberV2(m)];
    */

    char array5[ConstantNumberV3(5)];
    std::cout << "Size of array5: " << sizeof(array5) << std::endl;

    return 0;
}
