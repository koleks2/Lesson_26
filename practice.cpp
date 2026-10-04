#include <iostream>
#include <utility>
#include "String.h"

int main() {
    String text1("Hello");
    String text2(" World");

    String text3 = text1 + text2;
    std::cout << "text3: " << text3 << std::endl;

    String text4 = std::move(text1);
    std::cout << "text4: " << text4 << std::endl;

    String text5;
    text5 = std::move(text2);
    std::cout << "text5: " << text5 << std::endl;
}