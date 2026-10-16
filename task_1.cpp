// Name    : Muhammad Rayan Zulfiqar
// CMS     : 543021
// Section : BScs 15-D
// Task 1: Stack using an array
#include <iostream>
using namespace std;

const int SIZE = 5;
int items[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1) { cout << "Stack Overflow: cannot push " << value << endl; return; }
    items[++top] = value;
    cout << "Pushed " << value << endl;
}

void pop() {
    if (top == -1) { cout << "Stack Underflow: stack is empty" << endl; return; }
    cout << "Popped " << items[top--] << endl;
}

void peek() {
    if (top == -1) { cout << "Stack is empty, nothing to peek" << endl; return; }
    cout << "Top element: " << items[top] << endl;
}

void display() {
    if (top == -1) { cout << "Stack is empty" << endl; return; }
    cout << "Stack (top to bottom): ";
    for (int i = top; i >= 0; i--) cout << items[i] << " ";
    cout << endl;
}

int main() {
    push(10); push(20); push(30);
    display();
    pop();
    peek();
    display();
    cout << "--- Fill the stack and test a sixth insertion ---" << endl;
    push(40); push(50); push(60);   // stack becomes full (5 items)
    push(70);                       // sixth insertion -> blocked
    display();
    cout << "--- Remove all values, then pop again ---" << endl;
    while (top != -1) pop();
    pop();
    peek();
    return 0;
}
