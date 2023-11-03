Write a program to implement doubly linked list as an ADT that supports the following op-
erations:
i. Insert an element x at the beginning of the doubly linked list
ii. Insert an element x at the end of the doubly linked list
iii. Remove an element from the beginning of the doubly linked list
iv. Remove an element from the end of the doubly linked list




class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    # Insert an element at the beginning of the doubly linked list
    def insert_at_beginning(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node

    # Insert an element at the end of the doubly linked list
    def insert_at_end(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node

    # Remove an element from the beginning of the doubly linked list
    def remove_from_beginning(self):
        if not self.head:
            print("List is empty")
        else:
            if self.head == self.tail:
                self.head = None
                self.tail = None
            else:
                self.head = self.head.next
                self.head.prev = None

    # Remove an element from the end of the doubly linked list
    def remove_from_end(self):
        if not self.head:
            print("List is empty")
        else:
            if self.head == self.tail:
                self.head = None
                self.tail = None
            else:
                self.tail = self.tail.prev
                self.tail.next = None

    def display(self):
        if not self.head:
            print("List is empty")
        else:
            current = self.head
            while current:
                print(current.data, end=' ')
                current = current.next
            print()

# Example usage
dll = DoublyLinkedList()
dll.insert_at_beginning(1)
dll.insert_at_end(2)
dll.insert_at_end(3)
dll.display()

dll.remove_from_beginning()
print("After removing from the beginning:")
dll.display()

dll.remove_from_end()
print("After removing from the end:")
dll.display()


