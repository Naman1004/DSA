#include <iostream>
#define MAX_SIZE 100 // Maximum size of the stack

using namespace std;

class Stack {
private:
    int arr[MAX_SIZE];
    int top; // Index of the top element of the stack
public:
    // Constructor
    Stack() {
        top = -1; // Stack is initially empty
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack Overflow! Cannot push more elements.\n";
            return;
        }
        arr[++top] = value;
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from an empty stack.\n";
            return;
        }
        top--;
    }

    // Function to return the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[top];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack myStack;
    
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);
    
    cout << "Top element: " << myStack.peek() << endl;
    
    myStack.pop();
    cout << "Top element after pop: " << myStack.peek() << endl;
    
    myStack.pop();
    myStack.pop(); // Trying to pop from an empty stack
    
    return 0;
}
