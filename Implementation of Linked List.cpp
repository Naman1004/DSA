#include <iostream>

// Node class for the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the beginning of the linked list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Function to delete the entire linked list to prevent memory leaks
    void deleteLinkedList() {
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    ~LinkedList() {
        deleteLinkedList();
    }
};

int main() {
    LinkedList myList;

    // Insert some elements into the linked list
    myList.insertAtBeginning(5);
    myList.insertAtBeginning(10);
    myList.insertAtBeginning(15);

    // Display the linked list
    std::cout << "Linked List: ";
    myList.display();

    return 0;
}
