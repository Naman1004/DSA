#include <iostream>
#define MAX_SIZE 100 // Define the maximum size of the queue

class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;

public:
    Queue() {
        front = -1;
        rear = -1;
        size = 0;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (size == 0);
    }

    // Check if the queue is full
    bool isFull() {
        return (size == MAX_SIZE);
    }

    // Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue " << value << std::endl;
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
        size++;
        if (front == -1) { // If the queue was empty, set front to 0
            front = rear;
        }
        std::cout << value << " enqueued to queue." << std::endl;
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % MAX_SIZE;
        size--;
        if (size == 0) { // Reset front and rear when the queue is empty
            front = -1;
            rear = -1;
        }
        return value;
    }

    // Get the front of the queue
    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty. No front element." << std::endl;
            return -1;
        }
        return arr[front];
    }

    // Get the size of the queue
    int getSize() {
        return size;
    }

    // Display the queue elements
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        std::cout << "Queue elements are: ";
        for (int i = 0; i < size; i++) {
            std::cout << arr[(front + i) % MAX_SIZE] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    std::cout << "Dequeued element: " << q.dequeue() << std::endl;
    q.display();

    std::cout << "Front element: " << q.getFront() << std::endl;

    return 0;
}
