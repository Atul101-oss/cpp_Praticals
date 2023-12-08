#include <iostream>
using namespace std;

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

    void remove(int data) {
        if (!head) {
            cout << "List is empty" << endl;
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
            do {
                if (current->data == data) {
                    prev->next = current->next;
                    delete current;
                    return;
                }
                prev = current;
                current = current->next;
            } while (current != head);
            cout << data << " not found in the list" << endl;
        }
    }

    Node* search(int data) {
        if (!head) {
            return nullptr;
        }
        Node* current = head;
        do {
            if (current->data == data) {
                cout << data << " found at address: " << current << endl;
                return current;
            }
            current = current->next;
        } while (current != head);
        cout << data << " not found!" << endl;
        return nullptr;
    }

    void display() {
        if (!head) {
            cout << "List is empty" << endl;
        } else {
            Node* temp = head;
            do {
                cout << temp->data << "->";
                temp = temp->next;
            } while (temp != head);
            cout << "[head]" << endl;
        }
    }
};

int main() {
    CircularLinkedList cll;

    int choice, data;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Remove\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                cll.insert(data);
                break;

            case 2:
                cout << "Enter data to remove: ";
                cin >> data;
                cll.remove(data);
                break;

            case 3:
                cout << "Enter data to search: ";
                cin >> data;
                cll.search(data);
                break;

            case 4:
                cout << "Circular Linked List: ";
                cll.display();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}