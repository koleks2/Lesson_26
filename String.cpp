#include "String.h"
#include <iostream>

String::String() {
    this->lenght = 1;
    this->text = new char[1];
    this->text[0] = '\0';
}

String::String(const char* text) {
    if (text == nullptr) {
        text = "";
    }
    this->lenght = static_cast<int>(strlen(text)) + 1;
    this->text = new char[this->lenght];
    strcpy_s(this->text, this->lenght, text);
}

String::String(const String& other) {
    this->lenght = other.lenght;
    this->text = new char[this->lenght];
    strcpy_s(this->text, this->lenght, other.text);
}

String::String(String&& other) noexcept {
    std::cout << "[Move Constructor]\n";
    this->lenght = other.lenght;
    this->text = other.text;

    other.lenght = 1;
    other.text = new char[1];
    other.text[0] = '\0';
}

String::~String() {
    if (text != nullptr) {
        delete[] text;
    }
}

void String::copyFrom(const String& other) {
    if (this != &other) {
        if (this->text != nullptr) {
            delete[] this->text;
        }
        this->lenght = other.lenght;
        this->text = new char[this->lenght];
        strcpy_s(this->text, this->lenght, other.text);
    }
}

String& String::operator=(const String& other) {
    this->copyFrom(other);
    return *this;
}

String& String::operator=(String&& other) noexcept {
    std::cout << "[Move Assignment]\n";
    if (this != &other) {
        if (this->text != nullptr) {
            delete[] this->text;
        }

        this->lenght = other.lenght;
        this->text = other.text;

        other.lenght = 1;
        other.text = new char[1];
        other.text[0] = '\0';
    }
    return *this;
}

char& String::operator[](int index) {
    if (index < 0 || index >= this->GetStringLenght()) {
        throw std::out_of_range("Index out of bounds!");
    }
    return this->text[index];
}

const char& String::operator[](int index) const {
    if (index < 0 || index >= this->GetStringLenght()) {
        throw std::out_of_range("Index out of bounds!");
    }
    return this->text[index];
}

String String::operator+(const String& other) const {
    int newLenght = this->GetStringLenght() + other.GetStringLenght() + 1;
    char* temp = new char[newLenght];
    strcpy_s(temp, newLenght, this->text);
    strcat_s(temp, newLenght, other.text);

    String result(temp);
    delete[] temp;
    return result;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.text;
    return os;
}