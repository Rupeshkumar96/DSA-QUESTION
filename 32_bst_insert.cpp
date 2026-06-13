// bst_insertion.cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insertRecursive(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
        cout << "Inserted " << value << " into BST" << endl;
    }

    void inorder() {
        inorderRecursive(root);
        cout << endl;
    }

    void inorderRecursive(Node* node) {
        if (node != NULL) {
            cout << node->data << " ";
            inorderRecursive(node->left);
            inorderRecursive(node->right);
        }
    }
};

int main() {
    BST tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    cout << "Inorder traversal: ";
    tree.inorder();

    return 0;
}
