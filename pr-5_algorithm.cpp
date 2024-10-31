#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class BNode {
    int *keys;      // Array of keys
    int t;          // Minimum degree (defines the range for the number of keys)
    BNode **children; // Array of child pointers
    int n;          // Current number of keys
    bool leaf;      // True if leaf node

public:
    BNode(int t, bool leaf);
    
    void insertNonFull(int key);
    void splitChild(int i, BNode *y);
    void traverse();
    BNode *search(int key);
    void deleteKey(int key);
    void merge(int idx); // Declare the merge function
    friend class BTree;
};

class BTree {
    BNode *root;
    int t;

public:
    BTree(int _t) {
        root = nullptr;
        t = _t;
    }

    void traverse() {
        if (root != nullptr) root->traverse();
    }

    BNode* search(int key) {
        return (root == nullptr) ? nullptr : root->search(key);
    }

    void deleteKey(int key) {
        if (!root) {
            cout << "The tree is empty. Key not found." << endl;
            return;
        }

        root->deleteKey(key); // Call delete on root

        // If the root node has no keys, make the first child the new root
        if (root->n == 0) {
            BNode *temp = root;
            if (root->leaf) {
                delete root; // Free memory if the root is a leaf
                root = nullptr; // Tree is now empty
            } else {
                root = root->children[0]; // Make the first child the new root
                delete temp; // Free old root
            }
        }
    }

    void insert(int key);
};

BNode::BNode(int t, bool leaf) {
    this->t = t;
    this->leaf = leaf;
    keys = new int[2 * t - 1];
    children = new BNode *[2 * t];
    n = 0;
}

void BNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (!leaf)
            children[i]->traverse();
        cout << " " << keys[i];
    }
    if (!leaf)
        children[i]->traverse();
}

BNode *BNode::search(int key) {
    int i = 0;
    while (i < n && key > keys[i])
        i++;

    if (i < n && keys[i] == key)
        return this;

    if (leaf)
        return nullptr;

    return children[i]->search(key);
}

void BTree::insert(int key) {
    if (root == nullptr) {
        root = new BNode(t, true);
        root->keys[0] = key;
        root->n = 1;
    } else {
        if (root->n == 2 * t - 1) {
            BNode *s = new BNode(t, false);
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

void BNode::insertNonFull(int key) {
    int i = n - 1;

    if (leaf) {
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = key;
        n = n + 1;
    } else {
        while (i >= 0 && keys[i] > key)
            i--;

        if (children[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, children[i + 1]);
            if (keys[i + 1] < key)
                i++;
        }
        children[i + 1]->insertNonFull(key);
    }
}

void BNode::splitChild(int i, BNode *y) {
    BNode *z = new BNode(y->t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (!y->leaf) {
        for (int j = 0; j < t; j++)
            z->children[j] = y->children[j + t];
    }

    y->n = t - 1;

    for (int j = n; j >= i + 1; j--)
        children[j + 1] = children[j];

    children[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];
    n = n + 1;
}

void BNode::merge(int idx) {
    BNode *child = children[idx];
    BNode *sibling = children[idx + 1];

    child->keys[t - 1] = keys[idx];

    for (int i = 0; i < sibling->n; i++) {
        child->keys[i + t] = sibling->keys[i];
    }

    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; i++) {
            child->children[i + t] = sibling->children[i];
        }
    }

    child->n += sibling->n + 1;

    for (int i = idx + 1; i < n; i++) {
        keys[i - 1] = keys[i];
    }

    for (int i = idx + 1; i <= n; i++) {
        children[i - 1] = children[i];
    }

    n--;

    delete sibling; // Free memory of the sibling
}

void BNode::deleteKey(int key) {
    int idx = 0;
    while (idx < n && keys[idx] < key) {
        idx++;
    }

    if (idx < n && keys[idx] == key) {
        // Key is found in this node
        if (leaf) {
            // If this is a leaf node, simply remove the key
            for (int i = idx + 1; i < n; i++) {
                keys[i - 1] = keys[i];
            }
            n--;
        } else {
            // If this node is not a leaf
            // Find the predecessor key (largest key in the left subtree)
            int predecessorKey = keys[idx];
            BNode *leftChild = children[idx];
            while (!leftChild->leaf) {
                leftChild = leftChild->children[leftChild->n];
            }
            predecessorKey = leftChild->keys[leftChild->n - 1];

            // Recursively delete the predecessor key
            keys[idx] = predecessorKey;
            children[idx]->deleteKey(predecessorKey);
        }
    } else {
        // If this node is a leaf, then the key is not present
        if (leaf) {
            cout << "The key " << key << " is not found in the tree." << endl;
            return;
        }

        // Go to the appropriate child
        bool shouldMerge = (idx == n); // True if key is not found
        if (children[idx]->n < t) {
            // Fill child if it has less than t keys
            if (idx != 0 && children[idx - 1]->n >= t) {
                // Borrow a key from the left sibling
                BNode *leftChild = children[idx - 1];
                for (int i = n; i >= idx + 1; i--) {
                    children[i + 1] = children[i];
                }
                children[idx + 1] = children[idx]->children[0];
                for (int i = 0; i < children[idx]->n; i++) {
                    children[idx]->keys[i + 1] = children[idx]->keys[i];
                }
                children[idx]->keys[0] = keys[idx - 1];
                if (!children[idx]->leaf) {
                    children[idx]->children[0] = leftChild->children[leftChild->n];
                }
                keys[idx - 1] = leftChild->keys[leftChild->n - 1];
                leftChild->n--;
                children[idx]->n++;
            } else if (idx != n && children[idx + 1]->n >= t) {
                // Borrow a key from the right sibling
                BNode *rightChild = children[idx + 1];
                children[idx]->keys[children[idx]->n] = keys[idx];
                if (!children[idx]->leaf) {
                    children[idx]->children[children[idx]->n + 1] = rightChild->children[0];
                }
                keys[idx] = rightChild->keys[0];
                for (int i = 1; i < rightChild->n; i++) {
                    rightChild->keys[i - 1] = rightChild->keys[i];
                }
                if (!rightChild->leaf) {
                    for (int i = 1; i <= rightChild->n; i++) {
                        rightChild->children[i - 1] = rightChild->children[i];
                    }
                }
                rightChild->n--;
                children[idx]->n++;
            } else {
                // Merge with a sibling
                if (idx != n) {
                    merge(idx);
                } else {
                    merge(idx - 1);
                }
            }
        }

        // After ensuring the child has enough keys, proceed to the appropriate child
        if (shouldMerge && idx > n) {
            children[idx - 1]->deleteKey(key);
        } else {
            children[idx]->deleteKey(key);
        }
    }
}

int main() {
    int d;
    cout << "Enter degree of B-Tree for init Tree: ";
    cin >> d;
    BTree tree(d);

    while (true) {
        int op;
        cout << "1. Insert in B-Tree \n2. Search an element \n3. Delete an element \n4. Display B-Tree \n0. For Exit!" << endl;
        cout << "Enter an option: ";
        cin >> op;

        switch (op) {
            case 1: {
                string input;
                cout << "Enter numbers to insert in B-Tree (separated by space): ";
                cin.ignore(); // Clear the input buffer
                getline(cin, input);
                stringstream ss(input);
                int elem;
                while (ss >> elem) {
                    tree.insert(elem);
                }
                break;
            }
            case 2: {
                int key;
                cout << "Enter key to search: ";
                cin >> key;
                BNode *result = tree.search(key);
                (result != nullptr) ? cout << "Key " << key << " found." << endl : cout << "Key " << key << " not found." << endl;
                break;
            }
            case 3: {
                int key;
                cout << "Enter key to delete: ";
                cin >> key;
                tree.deleteKey(key);
                break;
            }
            case 4:
                cout << "Traversal of the B-tree: ";
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

    return 0;
}
