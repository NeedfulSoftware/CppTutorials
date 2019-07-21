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
#include <vector>
#include <utility>

// A simple class with a move constructor declared as noexcept
class ItemWithNoExceptMove
{
public:
    ItemWithNoExceptMove() = default;
    ItemWithNoExceptMove(const ItemWithNoExceptMove& other) = default;
    ItemWithNoExceptMove(ItemWithNoExceptMove&& other) noexcept;

    ItemWithNoExceptMove& operator=(const ItemWithNoExceptMove& other);
};

ItemWithNoExceptMove::ItemWithNoExceptMove(ItemWithNoExceptMove&& other) noexcept
{
    std::cout << "Move constructor called" << std::endl;
}

ItemWithNoExceptMove& ItemWithNoExceptMove::operator=(const ItemWithNoExceptMove& other)
{
    return *this;
}

// A simple class with a move constructor but it is not declared as noexcept
class ItemWithoutNoExceptMove
{
public:
    ItemWithoutNoExceptMove() = default;
    ItemWithoutNoExceptMove(const ItemWithoutNoExceptMove& other) = default;
    ItemWithoutNoExceptMove(ItemWithoutNoExceptMove&& other);

    ItemWithoutNoExceptMove& operator=(const ItemWithoutNoExceptMove& other);
};

ItemWithoutNoExceptMove::ItemWithoutNoExceptMove(ItemWithoutNoExceptMove&& other)
{
    std::cout << "Move constructor called" << std::endl;
}

ItemWithoutNoExceptMove& ItemWithoutNoExceptMove::operator=(const ItemWithoutNoExceptMove& other)
{
    return *this;
}

int main(int argc, char* argv[])
{   
    // Create a vector of 3 elements that have a noexcept move constructor and resize it
    std::cout << "1a) Create a vector of 3 elements that have a noexcept move constructor" << std::endl;
    std::vector<ItemWithNoExceptMove> v1 = { ItemWithNoExceptMove(), ItemWithNoExceptMove(), ItemWithNoExceptMove() };
    std::cout << "1b) Resize the vector" << std::endl;
    v1.resize(100);

    std::cout << std::endl;

    // Create a vector of 3 elements that don't have a noexcept move constructor and resize it
    std::cout << "2a) Create a vector of 3 elements that do not have a noexcept move constructor" << std::endl;
    std::vector<ItemWithoutNoExceptMove> v2 = { ItemWithoutNoExceptMove(), ItemWithoutNoExceptMove(),
        ItemWithoutNoExceptMove() };
    std::cout << "2b) Resize the vector" << std::endl;
    v2.resize(100);

    return 0;
}
