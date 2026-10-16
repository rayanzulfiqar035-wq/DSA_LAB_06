// Name    : Muhammad Rayan Zulfiqar
// CMS     : 543021
// Section : BScs 15-D
//Task 3: Reversing a word using a stack
#include <iostream>
#include <string>
using namespace std;

const int MAXLEN = 20;
char stackArr[MAXLEN];
int top = -1;

void push(char c) {
    if (top == MAXLEN - 1) { cout << "Stack Overflow" << endl; return; }
    stackArr[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stackArr[top--];
}

int main() {
    string word;
    cout << "Enter a word (max " << MAXLEN << " characters): ";
    cin >> word;

    if ((int)word.length() > MAXLEN) {
        cout << "Error: word is longer than " << MAXLEN << " characters." << endl;
        return 1;
    }

    for (size_t i = 0; i < word.length(); i++) push(word[i]);

    cout << "Reversed word: ";
    while (top != -1) cout << pop();
    cout << endl;
    return 0;
}
