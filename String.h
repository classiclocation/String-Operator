#pragma once

#ifndef STRING_H
#define STRING_H

#include <cstddef>

class String
{
private:
    char* data;
    size_t size;
    static int objectCount;

public:
    String(size_t length);
    String();
    String(const char* str);

    String(String&& other) noexcept;
    String& operator=(String&& other) noexcept;

    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    ~String();

    void input();
    void output() const;

    static int getObjectCount();
};

#endif
