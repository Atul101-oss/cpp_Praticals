#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insert_at_beginning(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    void insert_at_position(int data, int position) {
        if (position < 1) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* new_node = new Node(data);
        if (position == 1) {
            new_node->next = head;
            head = new_node;
            return;
        }

        Node* current = head;
        int count = 1;
        while (current && count < position - 1) {
            current = current->next;
            count++;
        }

        if (!current) {
            cout << "Position out of range" << endl;
        } else {
            new_node->next = current->next;
            current->next = new_node;
        }
    }

    void remove_from_beginning() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            cout << "List is empty" << std::endl;
        }
    }

    void remove_from_position(int position) {
        if (position < 1 || !head) {
            cout << "Invalid position or empty list" << endl;
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        int count = 1;
        while (current && count < position - 1) {
            current = current->next;
            count++;
        }

        if (!current || !current->next) {
            cout << "Position out of range" << endl;
        } else {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    Node* search(int target) {
        Node* current = head;
        while (current) {
            if (current->data == target) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    ~SinglyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList linked_list;

    int choice, data, position;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at position\n";
        cout << "3. Remove from beginning\n";
        cout << "4. Remove from position\n";
        cout << "5. Search\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                linked_list.insert_at_beginning(data);
                break;

            case 2:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert at: ";
                cin >> position;
                linked_list.insert_at_position(data, position);
                break;

            case 3:
                linked_list.remove_from_beginning();
                break;

            case 4:
                cout << "Enter position to remove: ";
                cin >> position;
                linked_list.remove_from_position(position);
                break;

            case 5:
                cout << "Enter data to search: ";
                cin >> data;
                Node* search_result = linked_list.search(data);
                if (search_result) {
                    cout << "Found: " << search_result->data << endl;
                } else {
                    cout << "Not Found" << endl;
                }
                break;

            case 6:
                linked_list.display();
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