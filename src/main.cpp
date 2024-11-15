#include <iostream>
#include "../include/twelve.h"
int main() {
    try {
        Twelve a("123");
        Twelve b("123");

        Twelve sum = a.add(b);
        Twelve sub = a.subtract(b);
        std::cout << "a + b = " << sum.toString() << std::endl;
        std::cout << "a - b = " << sub.toString() << std::endl;
        bool eq = a.isEqual(b);
        std::cout << "a == b? " << (eq == 1 ? "Yes" : "No") << std::endl;
        Twelve str;
        std::cout << "len(str) == " << str.getSize() << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}