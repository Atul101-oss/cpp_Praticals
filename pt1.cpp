class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None

    def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def insert_at_position(self, data, position):
        if position < 1:
            print("Invalid position")
            return
        new_node = Node(data)
        if position == 1:
            new_node.next = self.head
            self.head = new_node
            return
        current = self.head
        count = 1
        while current and count < position - 1:
            current = current.next
            count += 1
        if current is None:
            print("Position out of range")
        else:
            new_node.next = current.next
            current.next = new_node

    def remove_from_beginning(self):
        if self.head:
            self.head = self.head.next
        else:
            print("List is empty")

    def remove_from_position(self, position):
        if position < 1 or not self.head:
            print("Invalid position or empty list")
            return
        if position == 1:
            self.head = self.head.next
            return
        current = self.head
        count = 1
        while current and count < position - 1:
            current = current.next
            count += 1
        if current is None or current.next is None:
            print("Position out of range")
        else:
            current.next = current.next.next

    def search(self, target):
        current = self.head
        while current:
            if current.data == target:
                return current
            current = current.next
        return None

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")


# Example usage:
linked_list = SinglyLinkedList()
linked_list.insert_at_beginning(3)
linked_list.insert_at_beginning(2)
linked_list.insert_at_beginning(1)
linked_list.insert_at_position(4, 2)
linked_list.display()  # Output: 1 -> 4 -> 2 -> 3 -> None

linked_list.remove_from_beginning()
linked_list.remove_from_position(2)
linked_list.display()  # Output: 4 -> 3 -> None

search_result = linked_list.search(2)
if search_result:
    print("Found:", search_result.data)
else:
    print("Not Found")