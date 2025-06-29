#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node{value, top};
        top = newNode;
        cout << "Pushed: " << value << endl;
    }

    void pop() {
        if (!top) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Popped: " << temp->data << endl;
        delete temp;
    }

    void display() {
        if (!top) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* current = top;
        cout << "Stack (top -> bottom): ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void update(int oldValue, int newValue) {
        Node* current = top;
        while (current) {
            if (current->data == oldValue) {
                current->data = newValue;
                cout << "Updated " << oldValue << " to " << newValue << endl;
                return;
            }
            current = current->next;
        }
        cout << "Value " << oldValue << " not found in stack." << endl;
    }

    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;

    s.push(5);
    s.push(10);
    s.push(15);
    s.display();

    s.update(10, 12);
    s.display();

    s.pop();
    s.display();

    s.pop();
    s.pop();
    s.pop();

    return 0;
}
