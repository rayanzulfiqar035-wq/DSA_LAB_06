// Name    : Muhammad Rayan Zulfiqar
// CMS     : 543021
// Section : BScs 15-D
// Task 6: Customer service queue (linear array queue, size 5)

// Explanation :
// Limitation: this is a linear , non-circular queue. Once rear reaches index 4,
// insertion stays blocked even if customers were served, until the queue becomes
// completely empty and front/rear reset to -1.
#include <iostream>
using namespace std;

const int SIZE = 5;
int items[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Cannot add customer: queue insertion is blocked (rear is at last index)." << endl;
        return;
    }
    if (front == -1) front = 0;
    items[++rear] = value;
    cout << "Customer token " << value << " added." << endl;
}

void dequeue() {
    if (front == -1) { cout << "No customers to serve: queue is empty." << endl; return; }
    cout << "Serving customer token " << items[front] << endl;
    if (front == rear) front = rear = -1;
    else front++;
}

void peekFront() {
    if (front == -1) { cout << "No customers waiting: queue is empty." << endl; return; }
    cout << "Next customer token: " << items[front] << endl;
}

void display() {
    if (front == -1) { cout << "Queue is empty." << endl; return; }
    cout << "Waiting customers (front to rear): ";
    for (int i = front; i <= rear; i++) cout << items[i] << " ";
    cout << endl;
}

int main() {
    int choice, token;
    do {
        cout << "\nCustomer Service" << endl;
        cout << "1. Add customer" << endl;
        cout << "2. Serve next" << endl;
        cout << "3. View next" << endl;
        cout << "4. Display queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter token number: ";
                cin >> token;
                enqueue(token);
                break;
            case 2: dequeue(); break;
            case 3: peekFront(); break;
            case 4: display(); break;
            case 5: cout << "Exiting program." << endl; break;
            default: cout << "Invalid choice. Please enter 1-5." << endl;
        }
    } while (choice != 5);
    return 0;
}
