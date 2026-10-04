#pragma once

class String {
private:
    char* text = nullptr;
    int lenght = 0;

public:
    String();
    String(const char* text);
    String(const String& other);
    String(String&& other) noexcept;
    ~String();

    String& operator=(const String& other);
    String& operator=(String&& other) noexcept;

    char& operator[](int index);
    const char& operator[](int index) const;

    String operator+(const String& other) const;

    void copyFrom(const String& other);

    int GetStringLenght() const {
        return lenght - 1;
    }

    const char* c_str() const {
        return text;
    }

    friend std::ostream& operator<<(std::ostream& os, const String& str);
};