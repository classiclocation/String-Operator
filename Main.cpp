#include <iostream>
#include "String.h"

int main()
{
    String s1;
    String s2(50);
    String s3("Hello");

    std::cout << "Enter s1: ";
    std::cin >> s1;

    std::cout << "Enter s2: ";
    std::cin >> s2;

    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;
    std::cout << "s3 = " << s3 << std::endl;

    String s4 = s1 + s3;
    std::cout << "s1 + s3 = " << s4 << std::endl;

    if (s1 != s2)
        std::cout << "s1 and s2 are different\n";

    std::cout << "Number of objects: "
        << String::getObjectCount()
        << std::endl;
}
