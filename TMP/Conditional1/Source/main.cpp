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

#include <type_traits>
#include <iostream>

int main(int argc, char* argv[])
{
    // The std::conditional takes 3 arguments and produces a type
    // The first argument is a bool and the 2 other ones are types.
    // - If the first argument is true then the produced type is the second argument
    // - If the first argument is false then the produced type is the thrid argument.
    // You can see this is similar to an if/else statement. The first argument
    // is the condition, the second one the if clause and the third one the else clause.

    std::conditional<true, std::true_type, std::false_type>::type type1;
    std::cout << std::boolalpha << "type1 is " << type1.value << std::endl;

    std::conditional<false, std::true_type, std::false_type>::type type2;
    std::cout << std::boolalpha << "type2 is " << type2.value << std::endl;

    return 0;
}
