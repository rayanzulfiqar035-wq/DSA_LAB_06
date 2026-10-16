// Name    : Muhammad Rayan Zulfiqar
// CMS     : 543021
// Section : BScs 15-D
// Task 2: Stack using a linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int value) {
    Node* n = new Node;
    n->data = value;
    n->next = top;
    top = n;
    cout << "Pushed " << value << endl;
}

void pop() {
    if (top == nullptr) { cout << "Stack Underflow: stack is empty" << endl; return; }
    Node* temp = top;
    cout << "Popped " << temp->data << endl;
    top = top->next;
    delete temp;
}

void peek() {
    if (top == nullptr) { cout << "Stack is empty, nothing to peek" << endl; return; }
    cout << "Top element: " << top->data << endl;
}

void display() {
    if (top == nullptr) { cout << "Stack is empty" << endl; return; }
    cout << "Stack (top to bottom): ";
    for (Node* cur = top; cur != nullptr; cur = cur->next) cout << cur->data << " ";
    cout << endl;
}

int main() {
    push(5); push(15); push(25);
    display();
    pop();
    peek();
    display();
    cout << "Empty the stack, then pop on empty" << endl;
    pop(); pop();
    pop();   // empty pop test
    peek();

    // Push a few more and release all remaining nodes before exit
    push(1); push(2);
    cout << "Releasing remaining nodes" << endl;
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    display();
    return 0;
}
