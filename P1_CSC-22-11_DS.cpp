/*
Write a program to implement singly linked list as an ADT that supports the following operations:
i.Insert an element x at the beginning of the singly linked list
ii.Insert an element x at ithposition in the singly linked list
iii.Remove an element from the beginning of the doubly linked listiv.
    Remove an element from ithposition in the singly linked list.
vi.Search for an element x in the singly linked list and return its pointe
*/

#include <iostream>
#include <vector>
using namespace std;

class node {
    public:
    int data;
    node *next;

    node(int d) {
        data = d;
        next = NULL;
    }
};
void test() {
    vector <int> V;
    cout << V.size()<<endl;
    for (int i = 0; i < 5; i++)
    {
        V.push_back(i);
    };
    cout << V.size();
};

int main(){
    // node *head;
    test();
  
}

