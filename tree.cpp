#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);
        return node;
    }

    bool search(Node* node, int val) {
        if (!node) return false;
        if (val == node->data) return true;
        return val < node->data ? search(node->left, val) : search(node->right, val);
    }

    // Inorder Traversal
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Preorder Traversal
    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Postorder Traversal
    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    int findMin(Node* node) {
        if (!node) return -1;
        while (node->left) node = node->left;
        return node->data;
    }

    // Find maximum
    int findMax(Node* node) {
        if (!node) return -1;
        while (node->right) node = node->right;
        return node->data;
    }

    // Count total nodes
    int countNodes(Node* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    // Find height of tree
    int height(Node* node) {
        if (!node) return -1;
        return 1 + max(height(node->left), height(node->right));
    }
};

// ---------- Test Code ----------
int main() {
    BinaryTree bt;

    int values[] = {50, 30, 20, 40, 70, 60, 80};
    for (int v : values)
        bt.root = bt.insert(bt.root, v);

    cout << "Inorder: ";
    bt.inorder(bt.root);     // 20 30 40 50 60 70 80
    cout << "\nPreorder: ";
    bt.preorder(bt.root);    // 50 30 20 40 70 60 80
    cout << "\nPostorder: ";
    bt.postorder(bt.root);   // 20 40 30 60 80 70 50

    cout << "\n\nSearch 40: " << (bt.search(bt.root, 40) ? "Found" : "Not found");
    cout << "\nMinimum: " << bt.findMin(bt.root);
    cout << "\nMaximum: " << bt.findMax(bt.root);
    cout << "\nTotal Nodes: " << bt.countNodes(bt.root);
    cout << "\nHeight: " << bt.height(bt.root) << endl;

    return 0;
}
