#include "String.h"
#include <iostream>
#include <cstring>

int String::objectCount = 0;

String::String(size_t length)
{
    size = length;
    data = new char[size + 1];
    data[0] = '\0';
    objectCount++;
}

String::String() : String(80) {}

String::String(const char* str) : String(strlen(str))
{
    strcpy_s(data, size + 1, str);
}

String::String(String&& other) noexcept
{
    data = other.data;
    size = other.size;

    other.data = nullptr;
    other.size = 0;

    objectCount++;
}

String& String::operator=(String&& other) noexcept
{
    if (this != &other)
    {
        delete[] data;

        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;
    }

    return *this;
}

char& String::operator[](size_t index)
{
    return data[index];
}

const char& String::operator[](size_t index) const
{
    return data[index];
}

String::~String()
{
    delete[] data;
    objectCount--;
}

void String::input()
{
    std::cin.getline(data, size + 1);
}

void String::output() const
{
    std::cout << data << std::endl;
}

int String::getObjectCount()
{
    return objectCount;
}
