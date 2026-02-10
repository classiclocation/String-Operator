#ifndef STRING_H
#define STRING_H

#include <cstddef>
#include <iostream>

class String
{
private:
    char* data;
    size_t size;
    static int objectCount;

public:
    explicit String(size_t length);
    String();
    explicit String(const char* str);

    String(const String& other);

    String& operator=(const String& other);

    ~String();

    void input();
    void output() const;

    size_t getSize() const;
    const char* getData() const;

    String operator+(const String& other) const;
    bool operator==(const String& other) const;
    bool operator!=(const String& other) const;

    static int getObjectCount();

    friend std::ostream& operator<<(std::ostream& os, const String& str);
    friend std::istream& operator>>(std::istream& is, String& str);
};

#endif
