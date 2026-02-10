#include "String.h"
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

String::String(const String& other)
{
    size = other.size;
    data = new char[size + 1];
    strcpy_s(data, size + 1, other.data);
    objectCount++;
}

String& String::operator=(const String& other)
{
    if (this == &other)
        return *this;

    delete[] data;

    size = other.size;
    data = new char[size + 1];
    strcpy_s(data, size + 1, other.data);

    return *this;
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

size_t String::getSize() const
{
    return size;
}

const char* String::getData() const
{
    return data;
}

String String::operator+(const String& other) const
{
    String result(size + other.size);

    strcpy_s(result.data, result.size + 1, data);
    strcat_s(result.data, result.size + 1, other.data);

    return result;
}

bool String::operator==(const String& other) const
{
    return strcmp(data, other.data) == 0;
}

bool String::operator!=(const String& other) const
{
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
    os << str.data;
    return os;
}

std::istream& operator>>(std::istream& is, String& str)
{
    is.getline(str.data, str.size + 1);
    return is;
}

int String::getObjectCount()
{
    return objectCount;
}
