#include <iostream>
using namespace std;

class Queue {
    int size, rear, front, *arr;

public:
    Queue(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enQueue(int value) {
        if (rear == size - 1) {
            cout << "Queue is Full!!!!\n";
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = value;
        cout << value << " enqueued into the queue.\n";
    }

    void deQueue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }
        cout << arr[front] << " is deleted!!\n";
        front++;
    }

    void peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    int size, choice, value;

    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size);

    do {
        cout << "\n----- Queue Operations -----\n";
        cout << "1. Enqueue (Push)\n";
        cout << "2. Dequeue (Pop)\n";
        cout << "3. Peek (Front Element)\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enQueue(value);
                break;

            case 2:
                q.deQueue();
                break;

            case 3:
                q.peek();
                break;

            case 4:
                q.display();
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
