#include <iostream>
#include <stdexcept>
#include "String.h"
using namespace std;

int main() {
    try {
        String helloWorld("Hello");
        helloWorld.appendLine(", String!");
        helloWorld.appendLine("This is for Marc.");
        helloWorld.print();
        cout << endl;

        String a("Hello");
        String b("Mellow");
        String c("String");
        cout << "a == b: " << (a == b) << endl;
        cout << "c == b: " << (c == b) << endl;
        cout << endl;

        String testString("Hello, String");
        cout << "Index of 'ello' in testString: " << testString.indexOf("ello") << endl;
        cout << "Index of 'World' in testString: " << testString.indexOf("World") << endl;
        cout << "Index of 'Marc' in testString: " << testString.indexOf("Marc") << endl;
        cout << endl;

        String replaceTest("Hello World");
        cout << "Original string: ";
        replaceTest.print();
        cout << "After replacing 'l' with 'T': ";
        replaceTest.replace("l", "T");
        replaceTest.print();
        cout << "After replacing 'HeTTo' with 'Bye': ";
        replaceTest.replace("HeTTo", "Bye");
        replaceTest.print();
    }
    catch (const exception& ex) {
        cerr << "Exception: " << ex.what() << endl;
    }

    return 0;
}
