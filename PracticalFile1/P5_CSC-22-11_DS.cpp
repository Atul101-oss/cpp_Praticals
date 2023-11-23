#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    size_t count;

public:
    Queue() : front(nullptr), rear(nullptr), count(0) {}

    ~Queue() {
        clear();
    }

    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }

        T value = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        count--;

        if (isEmpty()) {
            rear = nullptr;
        }

        return value;
    }

    T peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return front->data;
    }

    bool isEmpty() const {
        return count == 0;
    }

    size_t size() const {
        return count;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue<int> myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    std::cout << "Front of the queue: " << myQueue.peek() << std::endl;
    std::cout << "Queue size: " << myQueue.size() << std::endl;

    while (!myQueue.isEmpty()) {
        std::cout << "Dequeued: " << myQueue.dequeue() << std::endl;
    }

    std::cout << "Queue size after dequeue operations: " << myQueue.size() << std::endl;

    return 0;
}
