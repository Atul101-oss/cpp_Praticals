#include <iostream>
#include <stdexcept>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;
    size_t count;

public:
    Queue() : front(nullptr), rear(nullptr), count(0) {}

    void enqueue(int data) {
        Node* newNode = new Node(data);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            throw out_of_range("Queue is Empty!");
        }

        int value = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        count--;

        if (isEmpty()) {
            rear = front;
        }

        return value;
    }

    void display() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << "-";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    bool isEmpty() {
        return count == 0;
    }

    int peek() {
        if (isEmpty()) {
            throw out_of_range("Queue is Empty!");
        }
        return front->data;
    }

    int size() {
        return count;
    }

};

int main() {
    Queue queue;

    int choice, data;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Size\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to enqueue: ";
                cin >> data;
                queue.enqueue(data);
                break;

            case 2:
                try {
                    cout << "Dequeued element: " << queue.dequeue() << endl;
                } catch (const exception& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;

            case 3:
                try {
                    cout << "Front element: " << queue.peek() << endl;
                } catch (const exception& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;

            case 4:
                cout << "Queue: ";
                queue.display();
                break;

            case 5:
                cout << "Size of Queue: " << queue.size() << endl;
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