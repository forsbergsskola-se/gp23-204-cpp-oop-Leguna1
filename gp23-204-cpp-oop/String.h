#pragma once
#include <stdexcept>
#include <iostream>

class String {
private:
    char* buffer;
    size_t length;
    size_t maxSize;

public:
    String() : buffer(nullptr), length(0), maxSize(0) {}

    String(const char* text) : buffer(nullptr), length(0), maxSize(0) {
        if (text == nullptr)
            throw std::invalid_argument("Null pointer passed to String constructor");

        length = customStrlen(text);
        maxSize = length + 1;
        buffer = new char[maxSize];
        customStrcpy(buffer, text);
    }

    ~String() { delete[] buffer; }

    void append(const char* text) {
        if (text == nullptr)
            throw std::invalid_argument("Null pointer passed to append");

        size_t newTextLength = customStrlen(text);
        if (length + newTextLength >= maxSize)
            resizeBuffer(length + newTextLength + 1);

        customStrcat(buffer, text);
        length += newTextLength;
    }

    void appendLine(const char* text) {
        append(text);
        append("\n");
    }

    void print() const { std::cout << buffer; }

    const char* getString() const { return buffer; }

    bool operator==(const String& other) const {
        return customStrcmp(buffer, other.buffer) == 0;
    }

    int indexOf(const char* substring) const {
        if (substring == nullptr)
            throw std::invalid_argument("Null pointer passed to indexOf");

        char* found = customStrstr(buffer, substring);
        return found != nullptr ? found - buffer : -1;
    }

    void replace(const char* oldSubstring, const char* newSubstring) {
        if (oldSubstring == nullptr || newSubstring == nullptr)
            throw std::invalid_argument("Null pointer passed to replace");

        int pos = indexOf(oldSubstring);
        if (pos != -1) {
            size_t oldLen = customStrlen(oldSubstring);
            size_t newLen = customStrlen(newSubstring);

            if (newLen > oldLen)
                resizeBuffer(length + newLen - oldLen);

            char* startPos = buffer + pos;
            char* endPos = startPos + oldLen;
            size_t moveSize = customStrlen(endPos) + 1;

            customMemmove(startPos + newLen, endPos, moveSize);
            customMemcpy(startPos, newSubstring, newLen);
            length = length + newLen - oldLen;
        }
    }

private:
    size_t customStrlen(const char* str) const {
        size_t len = 0;
        while (str[len] != '\0') {
            len++;
        }
        return len;
    }

    void customStrcpy(char* dest, const char* src) {
        while (*src != '\0') {
            *dest++ = *src++;
        }
        *dest = '\0';
    }

    void customStrcat(char* dest, const char* src) {
        while (*dest != '\0') {
            dest++;
        }
        while (*src != '\0') {
            *dest++ = *src++;
        }
        *dest = '\0';
    }

    int customStrcmp(const char* str1, const char* str2) const {
        while (*str1 == *str2) {
            if (*str1 == '\0') {
                return 0;
            }
            str1++;
            str2++;
        }
        return *str1 - *str2;
    }

    char* customStrstr(const char* str, const char* substr) const {
        while (*str != '\0') {
            const char* strStart = str;
            const char* subStart = substr;
            while (*str != '\0' && *substr != '\0' && *str == *substr) {
                str++;
                substr++;
            }
            if (*substr == '\0') {
                return const_cast<char*>(strStart);
            }
            str = strStart + 1;
            substr = subStart;
        }
        return nullptr;
    }

    void customMemmove(char* dest, const char* src, size_t n) {
        if (dest < src) {
            while (n--) {
                *dest++ = *src++;
            }
        }
        else if (dest > src) {
            dest += n;
            src += n;
            while (n--) {
                *--dest = *--src;
            }
        }
    }

    void customMemcpy(char* dest, const char* src, size_t n) {
        while (n--) {
            *dest++ = *src++;
        }
    }

    void resizeBuffer(size_t newSize) {
        maxSize = newSize;
        char* newBuffer = new char[maxSize];
        customMemcpy(newBuffer, buffer, length + 1);
        delete[] buffer;
        buffer = newBuffer;
    }
};

