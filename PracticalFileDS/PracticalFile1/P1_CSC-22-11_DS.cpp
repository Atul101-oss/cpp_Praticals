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
    linked_list.insert_at_beginning(3);
    linked_list.insert_at_beginning(2);
    linked_list.insert_at_beginning(1);
    linked_list.insert_at_position(4, 2);
    linked_list.display();

    linked_list.remove_from_beginning();
    linked_list.remove_from_position(2);
    linked_list.display();

    Node* search_result = linked_list.search(2);
    if (search_result) {
        cout << "Found: " << search_result->data << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}