#include <iostream>
#include <fstream>
using namespace std;

// check if keyword
bool isKeyword(string s) {
    return (s == "int" || s == "float" || s == "char" || s == "return" || s == "void");
}

// check if identifier
bool isIdentifier(string s) {
    if (!((s[0] >= 'a' && s[0] <= 'z') ||(s[0] >= 'A' && s[0] <= 'Z') ||s[0] == '_'))
        return false;

    for (int i = 1; i < s.length(); i++) {
        if (!((s[i] >= 'a' && s[i] <= 'z') ||(s[i] >= 'A' && s[i] <= 'Z') ||(s[i] >= '0' && s[i] <= '9') ||s[i] == '_'))
            return false;
    }

    return true;
}

// punctuation check
bool isPunctuation(char c) {
    return (c == ';' || c == ',' || c == '(' || c == ')' ||c == '{' || c == '}' || c == '=');
}

int main() {
    ifstream file("input.txt");
    char c;
    string word = "";

    while (file.get(c)) {

        // build word
        if ((c >= 'a' && c <= 'z') ||(c >= 'A' && c <= 'Z') ||(c >= '0' && c <= '9') ||c == '_')
        {
            word = word+c;
        }
        else {
            // if word is complete, classify it
            if (word != "") {
                if (isKeyword(word))
                    cout << word << " -> KEYWORD\n";
                else if (isIdentifier(word))
                    cout << word << " -> IDENTIFIER\n";
                else
                    cout << word << " -> INVALID\n";

                word = "";
            }

            // check punctuation
            if (isPunctuation(c)) {
                cout << c << " -> PUNCTUATION\n";
            }
        }
    }

    // last word if file ends
    if (word != "") {
        if (isKeyword(word))
            cout << word << " -> KEYWORD\n";
        else if (isIdentifier(word))
            cout << word << " -> IDENTIFIER\n";
        else
            cout << word << " -> INVALID\n";
    }

    return 0;
}
