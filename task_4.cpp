// Name    : Muhammad Rayan Zulfiqar
// CMS     : 543021
// Section : BScs 15-D
// Task 4: Inserting values into a (linear) queue
#include <iostream>
using namespace std;

const int SIZE = 5;
int items[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) { cout << "Queue is full: cannot insert " << value << endl; return; }
    if (front == -1) front = 0;     // first insertion
    items[++rear] = value;
    cout << "Inserted " << value << endl;
}

void display() {
    if (front == -1) { cout << "Queue is empty" << endl; return; }
    cout << "Queue (front to rear): ";
    for (int i = front; i <= rear; i++) cout << items[i] << " ";
    cout << endl;
}

int main() {
    display();                      // empty display test
    enqueue(10); enqueue(20); enqueue(30);
    display();
    cout << "Fill the queue and try one more insertion" << endl;
    enqueue(40); enqueue(50);
    display();
    enqueue(60);                    // blocked
    return 0;
}
