#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    // Function to insert node in binary tree
    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (root == nullptr) {
            root = newNode;
        }
        else {
            insertNode(root, newNode);
        }
    }

    // Function to insert node recursively
    void insertNode(Node* currentNode, Node* newNode) {
        if (newNode->data < currentNode->data) {
            if (currentNode->left == nullptr) {
                currentNode->left = newNode;
            }
            else {
                insertNode(currentNode->left, newNode);
            }
        }
        else {
            if (currentNode->right == nullptr) {
                currentNode->right = newNode;
            }
            else {
                insertNode(currentNode->right, newNode);
            }
        }
    }

    // Function to delete node from binary tree
    void deleteNode(int data) {
        root = deleteNodeRecursive(root, data);
    }

    // Function to delete node recursively
    Node* deleteNodeRecursive(Node* currentNode, int data) {
        if (currentNode == nullptr) {
            return currentNode;
        }

        if (data < currentNode->data) {
            currentNode->left = deleteNodeRecursive(currentNode->left, data);
        }
        else if (data > currentNode->data) {
            currentNode->right = deleteNodeRecursive(currentNode->right, data);
        }
        else {
            // Node has no child or one child
            if (currentNode->left == nullptr && currentNode->right == nullptr) {
                delete currentNode;
                currentNode = nullptr;
            }
            else if (currentNode->left == nullptr) {
                Node* temp = currentNode;
                currentNode = currentNode->right;
                delete temp;
            }
            else if (currentNode->right == nullptr) {
                Node* temp = currentNode;
                currentNode = currentNode->left;
                delete temp;
            }
            else {
                // Node has two children
                Node* temp = findMinNode(currentNode->right);
                currentNode->data = temp->data;
                currentNode->right = deleteNodeRecursive(currentNode->right, temp->data);
            }
        }

        return currentNode;
    }

    // Function to find minimum node in binary tree
    Node* findMinNode(Node* currentNode) {
        while (currentNode->left != nullptr) {
            currentNode = currentNode->left;
        }

        return currentNode;
    }

    // Function to search for node in binary tree
    bool search(int data) {
        return searchNodeRecursive(root, data);
    }

    // Function to search for node recursively
    bool searchNodeRecursive(Node* currentNode, int data) {
        if (currentNode == nullptr) {
            return false;
        }

        if (data < currentNode->data) {
            return searchNodeRecursive(currentNode->left, data);
        }
        else if (data > currentNode->data) {
            return searchNodeRecursive(currentNode->right, data);
        }
        else {
            return true;
        }
    }

    // Function to print binary tree in inorder traversal
    void printInorder() {
        printInorderRecursive(root);
    }

    // Function to print binary tree in inorder traversal recursively
    void printInorderRecursive(Node* currentNode) {
        if (currentNode != nullptr) {
            printInorderRecursive(currentNode->left);
            cout << currentNode->data << " ";
            printInorderRecursive(currentNode->right);
        }
    }

    // Function to print binary tree in preorder traversal
    void printPreorder() {
        printPreorderRecursive(root);
    }

    // Function to print binary tree in preorder traversal recursively
    void printPreorderRecursive(Node* currentNode) {
        if (currentNode != nullptr) {
            cout << currentNode->data << " ";
            printPreorderRecursive(currentNode->left);
            printPreorderRecursive(currentNode->right);
        }
    }

    // Function to print binary tree in postorder traversal
    void printPostorder() {
        printPostorderRecursive(root);
    }

    // Function to print binary tree in postorder traversal recursively
    void printPostorderRecursive(Node* currentNode) {
        if (currentNode != nullptr) {
            printPostorderRecursive(currentNode->left);
            printPostorderRecursive(currentNode->right);
            cout << currentNode->data << " ";
        }
    }
};

int main() {
    BinaryTree binaryTree;

    int choice;
    do {
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Node" << endl;
        cout << "4. Print Inorder" << endl;
        cout << "5. Print Preorder" << endl;
        cout << "6. Print Postorder" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int data;
            cout << "Enter node value: ";
            cin >> data;
            binaryTree.insert(data);
            break;
        }
        case 2: {
            int data;
            cout << "Enter node value to delete: ";
            cin >> data;
            binaryTree.deleteNode(data);
            break;
        }
        case 3: {
            int data;
            cout << "Enter node value to search: ";
            cin >> data;
            if (binaryTree.search(data)) {
                cout << "Node found!" << endl;
            }
            else {
                cout << "Node not found!" << endl;
            }
            break;
        }
        case 4:
            cout << "Inorder traversal: ";
            binaryTree.printInorder();
            cout << endl;
            break;
        case 5:
            cout << "Preorder traversal: ";
            binaryTree.printPreorder();
            cout << endl;
            break;
        case 6:
            cout << "Postorder traversal: ";
            binaryTree.printPostorder();
            cout << endl;
            break;
        case 7:
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}
