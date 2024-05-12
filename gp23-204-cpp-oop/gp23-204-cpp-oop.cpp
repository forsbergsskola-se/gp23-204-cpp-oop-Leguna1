#include "String.h"
#include <iostream>

int main() {
    try {

        String s1(100);
        s1.print();

        String s2("Hello ", 100);
        std::cout << "s1 : ";
        std::cout << "s2 : ";
        s2.print();

        std::cout << "\n[Appending text..]" << std::endl;
        s1.append("String ");
        std::cout << "s1 : ";
        s1.print();

        s1.appendLine("World!");
        std::cout << "\n[Displaying appendLine]" << std::endl;
        std::cout << "s1 : ";
        s1.print();

        String s3(s2);
        std::cout << "\n[Displaying copy constructor] " << std::endl;
        std::cout << "s3 (copy of s2): ";
        s3.print();

        std::cout << "\n[Displaying assignment operator]" << std::endl;
        String s4(100);
        s4 = s2;
        std::cout << "s4 after assignment: ";
        s4.print();

        String s5(std::move(s4));
        std::cout << "\n[Displaying move constructor:" << std::endl;
        std::cout << "s5 (moved from s4): ";
        s5.print();

        String s6(100);
        s6 = std::move(s5);
        std::cout << "\n[Displaying move assignment operator]" << std::endl;
        std::cout << "s6 after move assignment: ";
        s6.print();

        String s7 = s2 + s1;
        std::cout << "\n[Displaying operator+]" << std::endl;
        std::cout << "s7 (s2 + s1): ";
        s7.print();

        s2 += s1;
        std::cout << "\n[Displaying operator+=]" << std::endl;
        std::cout << "s2 after += s1: ";
        s2.print();

        std::cout << "\n[Displaying operator[] ]" << std::endl;
        char c = s2[0];
        std::cout << "First character of s2: " << c << std::endl;

        bool isEqual = s2 == s3;
        std::cout << "\n[Displaying operator== ]" << std::endl;
        std::cout << "s2 == s3: " << (isEqual ? "true" : "false") << std::endl;

        bool isNotEqual = s2 != s3;
        std::cout << "\n[Displaying operator!= ]" << std::endl;
        std::cout << "s2 != s3: " << (isNotEqual ? "true" : "false") << std::endl;

        std::cout << "\n[Displaying ostream operator ]" << std::endl;
        std::cout << "s2: " << s2 << std::endl;

        bool lessThan = s2 < s3;
        std::cout << "\n[Displaying operator < ]" << std::endl;
        std::cout << "s2 < s3: " << (lessThan ? "true" : "false") << std::endl;

        bool greaterThan = s2 > s3;
        std::cout << "\n[Displaying operator > ]" << std::endl;
        std::cout << "s2 > s3: " << (greaterThan ? "true" : "false") << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
