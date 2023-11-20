#include <iostream>
using namespace std;

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        key = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    TreeNode* root;


//  i. Insert an element x

    TreeNode* insert(TreeNode* root, int key) {
        if (root == nullptr)
            return new TreeNode(key);

        if (key < root->key){
            root->left = insert(root->left, key);
        }
        else if (key > root->key){
            root->right = insert(root->right, key);
        }
        return root;
    }


//  ii. Delete an element x     

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            root->key = minValue(root->right);
            root->right = deleteNode(root->right, root->key);
        }

        return root;
    }

    int minValue(TreeNode* root) {
        int minValue = root->key;
        while (root->left != nullptr) {
            minValue = root->left->key;
            root = root->left;
        }
        return minValue;
    }

//  iii. Search for an element x in the BST  

    TreeNode* search(TreeNode* root, int key) {
        if (root == nullptr || root->key == key)
            return root;

        if (key < root->key)
            return search(root->left, key);

        return search(root->right, key);
    }


//  iv. Display the elements of the BST in preorder, inorder, and postorder traversal

    void inorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->key << " ";
            inorderTraversal(root->right);
        }
    }

    void preorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            cout << root->key << " ";
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }

    void postorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            cout << root->key << " ";
        }
    }




public:
    BinarySearchTree(){
        root = nullptr;
    }

    void insert(int key) {
        root = insert(root, key);

    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
        cout << "After deleting 6:" << endl;
        displayPreorder();
    }

    void search(int key) {
        if (search(root, key))
            cout << "Yes " <<key<< " is present in BST!" << endl;
        else
            cout << key << " Not find in BST!" << endl;
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
    int elements[] = {8, 3, 10, 1, 6, 9, 12};

    for (int i=0; i < size(elements); i++) {
        bst.insert(elements[i]);
    }


    bst.search(10);

    bst.displayInorder();
    bst.displayPreorder();
    bst.displayPostorder();

    bst.deleteNode(6);

    return 0;
}