#include <iostream>

using namespace std;

// Node class for a doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    
    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly linked list class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    // Function to insert a node at the end of the list
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    // Function to display the list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertEnd(1);
    dll.insertEnd(2);
    dll.insertEnd(3);
    dll.insertEnd(4);
    
    cout << "Doubly linked list: ";
    dll.display();
    
    return 0;
}
