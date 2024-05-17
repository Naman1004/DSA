#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };
    
    Node* topNode;
    int size;

public:
    Stack() : topNode(nullptr), size(0) {}
    
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
    
    void push(T value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        size++;
    }
    
    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        size--;
    }
    
    T top() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return topNode->data;
    }
    
    bool isEmpty() const {
        return topNode == nullptr;
    }
    
    int getSize() const {
        return size;
    }
};

int main() {
    Stack<int> stack;

    // Pushing elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Displaying top element
    std::cout << "Top element: " << stack.top() << std::endl;

    // Popping elements from the stack
    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl;

    // Displaying size of the stack
    std::cout << "Stack size: " << stack.getSize() << std::endl;

    return 0;
}
