#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class linklist{
    Node *head;
public:
    linklist(){
        head = nullptr;
    }
    
    void addNode(int val){
        Node *newNode = new Node(val);
        
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node *temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    void deleteNode(int val){
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        } 
        if(head->data == val){
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        
        Node *pre = nullptr;
        Node *temp = head;
        while(temp != nullptr && temp->data != val){
            pre = temp;
            temp = temp->next;
        }
        pre->next = temp->next;
        delete temp;
        
        if(temp == nullptr){
            cout << "Value not found \n";
        }
    }
    
    void updateNode(int oldValue, int newValue){
        if(head == nullptr){
            cout << "list is empty!!!!!\n";
        }
        Node *temp = head;
        while(temp != nullptr){
            if (temp->data == oldValue){
                temp->data = newValue;
                return;
            }
            temp = temp->next;
    }
    cout << oldValue <<  "Value not Found!!!!";
    }
    
    void display(){
        Node *temp = head;
        if(temp->next != nullptr){
            while(temp->next != nullptr){
                cout << temp->data << "  ";
                temp = temp->next;
            }
            cout << temp->data;
        }
    }
};

int main() {
    linklist list;
     int choice, value, oldValue, newValue;
    do {
        cout << "\n----- Linked List Operations -----\n";
        cout << "1. Add Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Update Node\n";
        cout << "4. Display List\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
         switch (choice) {
            case 1:
                cout << "Enter value to add: ";
                cin >> value;
                list.addNode(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;
            case 3:
                cout << "Enter value to update: ";
                cin >> oldValue;
                cout << "Enter new value: ";
                cin >> newValue;
                list.updateNode(oldValue, newValue);
                break;
            case 4:
                list.display();
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }while(choice != 4);
    
    return 0;
}