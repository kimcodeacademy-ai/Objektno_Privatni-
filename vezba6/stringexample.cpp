#include <iostream>
#include <string>

using namespace std;

int main() {
    string text = "Hello World 123";
    cout << "Original string: " << text << endl << endl;

    // find
    cout << "find(\"World\"): " << text.find("World") << endl;

    // rfind
    cout << "rfind('o'): " << text.rfind('o') << endl;

    // find_first_of
    cout << "find_first_of(\"aeiou\"): " << text.find_first_of("aeiou") << endl;

    // find_last_of
    cout << "find_last_of(\"aeiou\"): " << text.find_last_of("aeiou") << endl;

    // find_first_not_of
    cout << "find_first_not_of(\"Hello \"): "
         << text.find_first_not_of("Hello ") << endl;

    // find_last_not_of
    cout << "find_last_not_of(\"123\"): "
         << text.find_last_not_of("123") << endl;

    cout << endl;

    // reading the whole string character by character
    cout << "Characters in string:" << endl;
    for (size_t i = 0; i < text.length(); i++) {
        cout << text[i] << " ";
    }
    cout << endl << endl;

    // compare
    string a = "Apple";
    string b = "Banana";

    cout << "compare(\"Apple\", \"Banana\"): " << a.compare(b) << endl;

    // compare with regular expressions
    if (a < b)
        cout << "Apple < Banana" << endl;
    else if (a > b)
        cout << "Apple > Banana" << endl;
    else
        cout << "Apple == Banana" << endl;

    cout << endl;

    // substr
    // Hello  Beautiful world 123
    string sub = text.substr(6, 5);
    cout << "substr(6, 5): " << sub << endl;

    // insert
    text.insert(5, " Beautiful");
    cout << "After insert: " << text << endl;

    // replace
    text.replace(6, 9, "Amazing");
    cout << "After replace: " << text << endl;

    cout << endl;

    // reading with getline
    string input;
    cout << "Enter a full sentence: ";
    getline(cin, input);
    cout << "You entered: " << input << endl;

    return 0;
}
