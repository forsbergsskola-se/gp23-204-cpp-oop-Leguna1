#include "String.h"

int main() {
    
    String str1(10); 
    String str2(10); 
    if (str1 == str2) {
        cout << "Test 1: str1 is equal to str2 (both empty)" << endl;
    }
    else {
        cout << "Test 1: str1 is NOT equal to str2 (both empty)" << endl;
    }

    
    String str3("Hello", 10);
    String str4("Hello", 10);
    if (str3 == str4) {
        cout << "Test 2: str3 is equal to str4 (both 'Hello')" << endl;
    }
    else {
        cout << "Test 2: str3 is NOT equal to str4 (both 'Hello')" << endl;
    }

    
    String str5("Hello", 10);
    String str6("World", 10);
    if (str5 != str6) {
        cout << "Test 3: str5 is NOT equal to str6 ('Hello' != 'World')" << endl;
    }
    else {
        cout << "Test 3: str5 is equal to str6 ('Hello' == 'World')" << endl;
    }

    
    String str7("Hello", 10);
    String str8("Hell", 10);
    if (str7 != str8) {
        cout << "Test 4: str7 is NOT equal to str8 ('Hello' != 'Hell')" << endl;
    }
    else {
        cout << "Test 4: str7 is equal to str8 ('Hello' == 'Hell')" << endl;
    }

    
    if (str3 == str3) {
        cout << "Test 5: str3 is equal to itself" << endl;
    }
    else {
        cout << "Test 5: str3 is NOT equal to itself" << endl;
    }

    return 0;
}
