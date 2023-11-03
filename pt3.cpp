#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Insert an element in the list
    void insert(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
            new_node->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = head;
        }
    }

    // Remove an element from the list
    void remove(int data) {
        if (!head) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        if (head->data == data) {
            if (head->next == head) {
                delete head;
                head = nullptr;
            } else {
                Node* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = head->next;
                Node* temp2 = head;
                head = head->next;
                delete temp2;
            }
        } else {
            Node* current = head;
            Node* prev = nullptr;
            while (current->data != data && current->next != head) {
                prev = current;
                current = current->next;
            }
            if (current->data == data) {
                prev->next = current->next;
                delete current;
            } else {
                std::cout << data << " not found in the list" << std::endl;
            }
        }
    }

    // Search for an element x in the list and return its pointer
    Node* search(int data) {
        if (!head) {
            return nullptr;
        }
        Node* current = head;
        do {
            if (current->data == data) {
                return current;
            }
            current = current->next;
        } while (current != head);
        return nullptr;
    }

    void display() {
        if (!head) {
            std::cout << "List is empty" << std::endl;
        } else {
            Node* temp = head;
            do {
                std::cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
            std::cout << std::endl;
        }
    }
};

int main() {
    CircularLinkedList cll;
    cll.insert(1);
    cll.insert(2);
    cll.insert(3);
    cll.display();

    Node* node_to_remove = cll.search(2);
    if (node_to_remove) {
        cll.remove(2);
        std::cout << "After removing 2:" << std::endl;
        cll.display();
    } else {
        std::cout << "Element not found in the list" << std::endl;
    }

    return 0;
}