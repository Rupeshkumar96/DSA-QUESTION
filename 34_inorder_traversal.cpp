// bst_inorder.cpp
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

    void inorderRecursive(Node* node) {
        if (node != NULL) {
            inorderRecursive(node->left);
            cout << node->data << " ";
            inorderRecursive(node->right);
        }
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void inorder() {
        cout << "Inorder traversal: ";
        inorderRecursive(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.inorder();

    return 0;
}
