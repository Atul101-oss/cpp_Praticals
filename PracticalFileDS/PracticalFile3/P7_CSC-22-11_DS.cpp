#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class AVLNode {
public:
    int key;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    AVLNode* root;

    int getHeight(AVLNode* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalance(AVLNode* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    AVLNode* insertNode(AVLNode* node, int key) {
        if (node == nullptr)
            return new AVLNode(key);

        if (key < node->key)
            node->left = insertNode(node->left, key);
        else if (key > node->key)
            node->right = insertNode(node->right, key);
        else
            return node; // Duplicate keys are not allowed

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // Left Heavy
        if (balance > 1) {
            if (key < node->left->key) {
                // Left-Left case
                return rotateRight(node);
            } else {
                // Left-Right case
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        // Right Heavy
        if (balance < -1) {
            if (key > node->right->key) {
                // Right-Right case
                return rotateLeft(node);
            } else {
                // Right-Left case
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    void inOrderTraversal(AVLNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            std::cout << node->key << " ";
            inOrderTraversal(node->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insertNode(root, key);
    }

    void inOrder() {
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    AVLTree avl;
    int choice, key;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. In-order Traversal\n";
        cout << "3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                avl.insert(key);
                break;

            case 2:
                cout << "In-order Traversal: ";
                avl.inOrder();
                break;

            case 3:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}