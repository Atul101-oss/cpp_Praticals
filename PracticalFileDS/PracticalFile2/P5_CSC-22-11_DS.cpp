#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next; 
    Node(int value){
        data = value;
        next = nullptr;
    }
};

class Queue{
private:
    Node* front;
    Node* rear;
    size_t count;

public:
    Queue(): front(nullptr), rear(nullptr), count(0) {}

    void enqueue(int data){
        Node* newNode = new Node(data);

        if (isEmpty()){
            front = rear = newNode;
        }else{
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    int dequeue(){
        if (isEmpty()){
            throw out_of_range("Queue id Empty!");
        }

        int value = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        count--;

        if(isEmpty()){
            rear = front;
        }

        return value;
    }

    // int search(int searchElement){
    //     if (isEmpty){
    //         throw out_of_range("Queue is Empty!");
    //     }
    //     int temp = front;
    //     while (temp != nullptr && temp->data != searchElement){
    //         temp = temp->next;
    //     }
        

    // }

    void display(){
        Node* temp = front;
        while (temp != nullptr){
            cout << temp->data <<"-";
            temp = temp->next;
        }
        cout << nullptr <<endl;
    }

    bool isEmpty(){
        return count == 0;
    }

    int peek(){
        if (isEmpty()){
            throw out_of_range("Queue is Empty!");
        }
        return front->data;
    }

    int size(){
        return count;
    }

};

int main(){
    Queue queue;

    queue.enqueue(4);
    queue.enqueue(3);
    queue.enqueue(5);


    cout <<"size of Queue : " <<queue.size() <<endl;
    cout <<"front element : " <<queue.peek() <<endl;
    cout <<"Queue         : ";  queue.display();
    while(!queue.isEmpty()){
        cout << queue.dequeue() <<endl;
    }
    cout <<"size of Queue : " <<queue.size() <<endl;
    cout <<"front element : " <<queue.peek() <<endl;
}
