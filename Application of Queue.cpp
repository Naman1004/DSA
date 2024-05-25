#include <iostream>
#include <string>

// Define a class for the queue node
class Node {
public:
    std::string data;
    Node* next;

    Node(const std::string& d) : data(d), next(nullptr) {}
};

// Define a class for the queue
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Enqueue operation
    void enqueue(const std::string& value) {
        Node* newNode = new Node(value);

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        std::cout << "Document \"" << value << "\" added to the print queue.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            std::cout << "Print queue is empty, no document to print.\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        std::cout << "Printing document \"" << temp->data << "\".\n";
        delete temp;
    }

    // Display operation
    void display() const {
        if (front == nullptr) {
            std::cout << "Print queue is empty.\n";
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
    Queue printQueue;

    printQueue.enqueue("Document1.pdf");
    printQueue.enqueue("Document2.docx");
    printQueue.enqueue("Document3.pptx");

    std::cout << "Current print queue: ";
    printQueue.display();

    printQueue.dequeue();
    printQueue.dequeue();

    std::cout << "Current print queue after printing two documents: ";
    printQueue.display();

    printQueue.dequeue();
    printQueue.dequeue(); // Attempt to dequeue from an empty queue

    return 0;
}
