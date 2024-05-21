#include <iostream>

// Node class to represent each element in the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Queue class using a linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to add an element to the queue
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (front == nullptr) {
            std::cout << "Queue is empty, cannot dequeue." << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;

        // If front becomes null, then change rear to null as well
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    // Function to get the front element of the queue
    int getFront() {
        if (front == nullptr) {
            std::cout << "Queue is empty." << std::endl;
            return -1; // Return an invalid value or throw an exception
        }
        return front->data;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to print the elements of the queue
    void printQueue() {
        if (front == nullptr) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        Node* temp = front;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Queue elements: ";
    q.printQueue();

    std::cout << "Front element: " << q.getFront() << std::endl;

    q.dequeue();
    std::cout << "Queue elements after dequeue: ";
    q.printQueue();

    std::cout << "Front element after dequeue: " << q.getFront() << std::endl;

    q.dequeue();
    q.dequeue();
    std::cout << "Queue elements after multiple dequeues: ";
    q.printQueue();

    std::cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
