// Name    : Muhammad Rayan Zulfiqar
// CMS     : 543021
// Section : BScs 15-D
// Task 5: Removing values from a (linear) queue
#include <iostream>
using namespace std;

const int SIZE = 5;
int items[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) { cout << "Queue is full: cannot insert " << value << endl; return; }
    if (front == -1) front = 0;
    items[++rear] = value;
    cout << "Inserted " << value << endl;
}

void dequeue() {
    if (front == -1) { cout << "Queue is empty: nothing to remove" << endl; return; }
    cout << "Removed " << items[front] << endl;
    if (front == rear) front = rear = -1;   // last item removed -> reset
    else front++;
}

void peekFront() {
    if (front == -1) { cout << "Queue is empty: no front element" << endl; return; }
    cout << "Front element: " << items[front] << endl;
}

void display() {
    if (front == -1) { cout << "Queue is empty" << endl; return; }
    cout << "Queue (front to rear): ";
    for (int i = front; i <= rear; i++) cout << items[i] << " ";
    cout << endl;
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    dequeue();
    peekFront();
    display();
    cout << "Remove all remaining items" << endl;
    dequeue(); dequeue();
    dequeue();                      // removal on empty queue
    cout << "Insert 40 after reset" << endl;
    enqueue(40);
    peekFront();
    display();
    return 0;
}
