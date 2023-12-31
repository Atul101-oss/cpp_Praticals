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
            cout << "NULL" << endl;
        }
    }
};

int main() {
    DoublyLinkedList dll;

    int choice, data;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Remove from beginning\n";
        cout << "4. Remove from end\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                dll.insert_at_beginning(data);
                break;

            case 2:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                dll.insert_at_end(data);
                break;

            case 3:
                dll.remove_from_beginning();
                break;

            case 4:
                dll.remove_from_end();
                break;

            case 5:
                cout << "Doubly Linked List: ";
                dll.display();
                break;

            case 6:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}