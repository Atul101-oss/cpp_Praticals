/*
Write a program to implement singly linked list as an ADT that supports the following operations:
i.Insert an element x at the beginning of the singly linked list
ii.Insert an element x at ithposition in the singly linked list
iii.Remove an element from the beginning of the doubly linked listiv.
    Remove an element from ithposition in the singly linked list.
vi.Search for an element x in the singly linked list and return its pointe
*/

// #include <iostream>
// using namespace std;

#include <iostream>  
using namespace std;  
class Node {  
   public:  
    int data;    
    Node *next;
    Node (int d=5){
        data = d;

    }
};  

void InsertAtHead(Node* &head, int value){
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    cout <<head->data<<"Insertion complete";
}

void display(Node* head){
    Node *current = head;
    while (current != NULL){
        cout << current <<" -> ";
        current = current->next;
        
    }
    cout <<"NULL";
    cout << "Cout complete";
}

int main() {
    Node *head = NULL;

    InsertAtHead(head,16);
    display(head);
    return 0;
}  
