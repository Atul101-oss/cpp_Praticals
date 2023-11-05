/*
Write a program to implement doubly linked list as an ADT that supports the following op-
erations:
i. Insert an element x at the beginning of the doubly linked list
ii. Insert an element x at the end of the doubly linked list
iii. Remove an element from the beginning of the doubly linked list
iv. Remove an element from the end of the doubly linked list
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert an element at the beginning of the doubly linked list
    void insert_at_beginning(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    // Insert an element at the end of the doubly linked list
    void insert_at_end(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }

    // Remove an element from the beginning of the doubly linked list
    void remove_from_beginning() {
        if (!head) {
            cout << "List is empty" << endl;
        } else {
            if (head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
                delete head->prev;
                head->prev = nullptr;
            }
        }
    }

    // Remove an element from the end of the doubly linked list
    void remove_from_end() {
        if (!head) {
            cout << "List is empty" << endl;
        } else {
            if (head == tail) {
                delete tail;
                head = nullptr;
                tail = nullptr;
            } else {
                tail = tail->prev;
                delete tail->next;
                tail->next = nullptr;
            }
        }
    }

    void display() {
        if (!head) {
            cout << "List is empty" << endl;
        } else {
            Node* current = head;
            while (current) {
                cout << current->data << "->";
                current = current->next;
            }
            cout <<"NULL"<< endl;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insert_at_beginning(1);
    dll.insert_at_end(2);
    dll.insert_at_end(3);
    dll.display();

    dll.remove_from_beginning();
    cout << "After removing from the beginning:" << endl;
    dll.display();

    dll.remove_from_end();
    cout << "After removing from the end:" << endl;
    dll.display();

    return 0;
}