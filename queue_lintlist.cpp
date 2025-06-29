#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (!front) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
    }

    void display() {
        if (!front) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* current = front;
        cout << "Queue: ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Update (first node with target value)
    void update(int oldValue, int newValue) {
        Node* current = front;
        while (current) {
            if (current->data == oldValue) {
                current->data = newValue;
                cout << "Updated " << oldValue << " to " << newValue << endl;
                return;
            }
            current = current->next;
        }
        cout << "Value " << oldValue << " not found in queue." << endl;
    }

    ~Queue() {
        while (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

// Test
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.update(20, 25);
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}
