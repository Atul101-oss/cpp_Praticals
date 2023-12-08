#include <iostream>
using namespace std;

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    // ... (Other functions remain the same)

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    bool search(int key) {
        return search(root, key);
    }

    void displayInorder() {
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }

    void displayPreorder() {
        cout << "Preorder Traversal: ";
        preorderTraversal(root);
        cout << endl;
    }

    void displayPostorder() {
        cout << "Postorder Traversal: ";
        postorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    int choice, key;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display Inorder\n";
        cout << "5. Display Preorder\n";
        cout << "6. Display Postorder\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                bst.insert(key);
                break;

            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                bst.deleteNode(key);
                break;

            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                if (bst.search(key))
                    cout << key << " is present in BST!" << endl;
                else
                    cout << key << " not found in BST!" << endl;
                break;

            case 4:
                bst.displayInorder();
                break;

            case 5:
                bst.displayPreorder();
                break;

            case 6:
                bst.displayPostorder();
                break;

            case 7:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}