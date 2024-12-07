#pragma once
#include <iostream>
#include <stdexcept>
#include <cstring>

using namespace std;

class String {
public:
    int maxSize;
    int length;
    char* buffer;

    String(int maxSize) : maxSize(maxSize), length(0), buffer(new char[maxSize + 1]) {
        cout << "Empty buffer gets constructed" << endl;
        buffer[0] = '\0';
    }

    String(const char* defaultText, int maxSize) : maxSize(maxSize), length(0), buffer(new char[maxSize + 1]) {
        cout << "Non-Empty string gets constructed" << endl;
        length = customStrlen(defaultText);
        for (int i = 0; i < length; i++) {
            buffer[i] = defaultText[i];
        }
        buffer[length] = '\0';
    }

    ~String() {
        cout << "String gets destructed" << endl;
        delete[] buffer;
    }

    void append(const char* text) {
        int newLength = customStrlen(text);
        if (length + newLength >= maxSize) {
            throw runtime_error("Appended text exceeds buffer size");
        }

        for (int i = 0; i < newLength; ++i) {
            buffer[length + i] = text[i];
        }
        length += newLength;
        buffer[length] = '\0';
    }

    void appendLine(const char* text) {
        if (length + customStrlen(text) + 1 >= maxSize) {
            throw runtime_error("The text is greater than buffer size");
        }
        append(text);

        buffer[length++] = '\n';
        buffer[length] = '\0';
    }

    void print() const {
        cout << buffer;
    }

    const char* getString()
    {
        return buffer;
    }

    String(const String& other) : maxSize(other.maxSize), length(other.length), buffer(new char[other.maxSize + 1]) {
        cout << "String copy constructor" << endl;
        memcpy(buffer, other.buffer, length + 1);
    }

    String& operator =(const String& other) {
        if (this != &other) {
            delete[] buffer;
            maxSize = other.maxSize;
            length = other.length;
            buffer = new char[maxSize + 1];
            memcpy(buffer, other.buffer, length + 1);
        }
        return *this;
    }

    String(String&& other) noexcept : maxSize(other.maxSize), length(other.length), buffer(other.buffer) {
        cout << "String move constructor" << endl;
        other.maxSize = 0;
        other.length = 0;
        other.buffer = nullptr;
    }

    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] buffer;
            maxSize = other.maxSize;
            length = other.length;
            buffer = other.buffer;
            other.maxSize = 0;
            other.length = 0;
            other.buffer = nullptr;
        }
        return *this;
    }
    String operator+(const String& other)
    {
        const size_t newLength = length + other.length;
        if (newLength > maxSize)
        {
            throw runtime_error("Combined strings exceed buffer size");
        }
        String result(*this);
        memcpy(result.buffer + length, other.buffer, other.length + 1);
        result.length = newLength;
        return result;
    }
    String& operator+=(const String& other) {
        const size_t new_length = length + other.length;
        if (new_length >= maxSize) {
            throw runtime_error("Strings exceeds buffer size");
        }
        memcpy(buffer + length, other.buffer, other.length + 1);
        length = new_length;
        return *this;

    }

    char& operator[] (const size_t& pos)
    {
        if (pos >= length) {
            throw out_of_range("Index out of range");
        }
        return buffer[pos];
    }

    friend ostream& operator<<(ostream& os, const String& text) {
        for (size_t i = 0; i < text.length; ++i) {
            os << text.buffer[i];
        }
        return os;
    }

    bool operator==(const String& other)
    {
        if (length == 0 && other.length == 0) {
            return true; 
        }
        if (length != other.length)
        {
            return false;
        }

        for (int i = 0; i < length; i++)
        {
            if (buffer[i] != other.buffer[i])
            {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const String& other)
    {
        if (length == 0 && other.length == 0) {
            return false; 
        }

        if (length != other.length)
        {
            return true;
        }

        for (int i = 0; i < length; i++)
        {
            if (buffer[i] != other.buffer[i])
            {
                return true;
            }
        }

        return false;
    }

    bool operator<(const String& other) const {
        int len = customMinOrMax(*this, other);

        for (int i = 0; i < len; ++i) {
            if (buffer[i] < other.buffer[i]) {
                return true;
            }
            else if (buffer[i] > other.buffer[i]) {
                return false;
            }
        }

        return length < other.length;
    }

    bool operator>(const String& other) const {
        int len = customMinOrMax(*this, other);

        for (int i = 0; i < len; ++i) {
            if (buffer[i] > other.buffer[i]) {
                return true;
            }
            else if (buffer[i] < other.buffer[i]) {
                return false;
            }
        }

        return length > other.length;
    }
private:
    int customStrlen(const char* str) const {
        int len = 0;
        while (str[len] != '\0') {
            len++;
        }
        return len;
    }
    static int customMinOrMax(const String& a, const String& b)
    {
        if (a.length < b.length) {
            return a.length;
        }
        else {
            return b.length;
        }
    }
};
