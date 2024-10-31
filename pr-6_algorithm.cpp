// Write a program to implement the Tree Data structure, which supports the following  
// operations:   
// a. Insert  
// b. Search

#include <iostream>
using namespace std;

class Node {
public:
    int keys[3];      // Stores up to 3 keys
    Node* children[4]; // Stores up to 4 child pointers
    int numKeys;       // Current number of keys
    bool isLeaf;       // True if node is a leaf

    Node(bool leaf);
    void traverse();
    Node* search(int key);
    void insertNonFull(int key);
    void splitChild(int i, Node* y);
};

class Tree24 {
    Node* root;

public:
    Tree24() { root = nullptr; }

    void traverse() {
        if (root != nullptr) root->traverse();
    }

    Node* search(int key) {
        return (root == nullptr) ? nullptr : root->search(key);
    }

    void insert(int key);
};

// Constructor for Node class
Node::Node(bool leaf) {
    isLeaf = leaf;
    numKeys = 0;
    for (int i = 0; i < 4; i++)
        children[i] = nullptr;
}

// Traverse the tree and print all keys in sorted order
void Node::traverse() {
    int i;
    for (i = 0; i < numKeys; i++) {
        if (!isLeaf)
            children[i]->traverse();
        cout << " " << keys[i];
    }
    if (!isLeaf)
        children[i]->traverse();
}

// Search a key in the 2-4 Tree
Node* Node::search(int key) {
    int i = 0;
    while (i < numKeys && key > keys[i])
        i++;

    if (i < numKeys && keys[i] == key)
        return this;

    if (isLeaf)
        return nullptr;

    return children[i]->search(key);
}

// Insert a key into the 2-4 Tree
void Tree24::insert(int key) {
    if (root == nullptr) {
        root = new Node(true);
        root->keys[0] = key;
        root->numKeys = 1;
    } else {
        if (root->numKeys == 3) {
            Node* s = new Node(false);
            s->children[0] = root;
            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < key)
                i++;
            s->children[i]->insertNonFull(key);

            root = s;
        } else {
            root->insertNonFull(key);
        }
    }
}

// Insert a key into a non-full node
void Node::insertNonFull(int key) {
    int i = numKeys - 1;

    if (isLeaf) {
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
        numKeys++;
    } else {
        while (i >= 0 && keys[i] > key)
            i--;

        if (children[i + 1]->numKeys == 3) {
            splitChild(i + 1, children[i + 1]);

            if (keys[i + 1] < key)
                i++;
        }
        children[i + 1]->insertNonFull(key);
    }
}

// Split the child of a node
void Node::splitChild(int i, Node* y) {
    Node* z = new Node(y->isLeaf);
    z->numKeys = 1;

    z->keys[0] = y->keys[2];

    if (!y->isLeaf) {
        for (int j = 0; j < 2; j++)
            z->children[j] = y->children[j + 2];
    }

    y->numKeys = 1;

    for (int j = numKeys; j >= i + 1; j--)
        children[j + 1] = children[j];

    children[i + 1] = z;

    for (int j = numKeys - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[1];
    numKeys++;
}

int main() {
    Tree24 tree;
    int option, key;

    while (true) {
        cout << "\n1. Insert in 2-4 Tree \n2. Search in 2-4 Tree \n3. Traverse 2-4 Tree \n0. Exit" << endl;
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                tree.insert(key);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                if (tree.search(key) != nullptr)
                    cout << "Key " << key << " found in the tree." << endl;
                else
                    cout << "Key " << key << " not found in the tree." << endl;
                break;
            case 3:
                cout << "Traversal of the 2-4 Tree: ";
                tree.traverse();
                cout << endl;
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid option!" << endl;
                break;
        }
    }
}
