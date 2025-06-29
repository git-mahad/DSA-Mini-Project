#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *pre;
    Node *next;

    Node(int val) {
        data = val;
        pre = nullptr;
        next = nullptr;
    }
};

class doublelist {
    Node *head;

public:
    doublelist() {
        head = nullptr;
    }

    void addNode(int val) {
        Node *newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->pre = temp;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void deleteNode(int val) {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;

        // Case: Head node is to be deleted
        if (head->data == val) {
            head = head->next;
            if (head != nullptr) { // Prevent null dereferencing
                head->pre = nullptr;
            }
            delete temp;
            cout << "Node with value " << val << " deleted.\n";
            return;
        }

        // Traverse to find node to delete
        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Value " << val << " not found.\n";
            return;
        }

        // Adjust pointers
        if (temp->next != nullptr) {
            temp->next->pre = temp->pre;
        }
        if (temp->pre != nullptr) {
            temp->pre->next = temp->next;
        }

        delete temp;
        cout << "Node with value " << val << " deleted.\n";
    }

    void updateNode(int oldValue, int newValue) {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != oldValue) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << oldValue << " value is not found!\n";
            return;
        }

        temp->data = newValue;
        cout << "Updated value: " << oldValue << " -> " << newValue << endl;
    }

    void displayForward() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        // Move to last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Traverse backward
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->pre;
        }
        cout << endl;
    }
};


int main() {
    doublelist dl;
    int choice, value, oldValue, newValue;

    do {
        cout << "\n----- Doubly Linked List Operations -----\n";
        cout << "1. Add Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Update Node\n";
        cout << "4. Display List (Forward)\n";
        cout << "5. Display List (Reverse)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add: ";
                cin >> value;
                dl.addNode(value);
                cout << "Node added successfully!\n";
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                dl.deleteNode(value);
                break;

            case 3:
                cout << "Enter value to update: ";
                cin >> oldValue;
                cout << "Enter new value: ";
                cin >> newValue;
                dl.updateNode(oldValue, newValue);
                break;

            case 4:
                cout << "Doubly Linked List (Forward): ";
                dl.displayForward();
                break;

            case 5:
                cout << "Doubly Linked List (Reverse): ";
                dl.displayBackward();
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}