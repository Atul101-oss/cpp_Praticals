class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.head = None

    # Insert an element at the end of the list
    def insert(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            new_node.next = self.head
        else:
            temp = self.head
            while temp.next != self.head:
                temp = temp.next
            temp.next = new_node
            new_node.next = self.head

    # Remove an element from the list
    def remove(self, data):
        if not self.head:
            return
        if self.head.data == data:
            if self.head.next == self.head:
                self.head = None
            else:
                temp = self.head
                while temp.next != self.head:
                    temp = temp.next
                temp.next = self.head.next
                self.head = self.head.next
        else:
            current = self.head
            prev = None
            while current.data != data and current.next != self.head:
                prev = current
                current = current.next
            if current.data == data:
                prev.next = current.next
            else:
                print(f"{data} not found in the list")

    # Search for an element x in the list and return its pointer
    def search(self, data):
        if not self.head:
            return None
        current = self.head
        while current.data != data and current.next != self.head:
            current = current.next
        if current.data == data:
            return current
        else:
            return None

    def display(self):
        if not self.head:
            print("List is empty")
        else:
            temp = self.head
            while True:
                print(temp.data, end=' ')
                temp = temp.next
                if temp == self.head:
                    break
            print()

# Example usage
cll = CircularLinkedList()
cll.insert(1)
cll.insert(2)
cll.insert(3)
cll.display()

node_to_remove = cll.search(2)
if node_to_remove:
    cll.remove(2)
    print("After removing 2:")
    cll.display()
else:
    print("Element not found in the list")