#include <iostream>
#include <cmath>
using namespace std;

class BinaryTree {
private:
    int* tree; // Pointer to the array representing the tree
    int size;  // Maximum size of the tree
    int lastIndex; // Index of the last inserted element

public:
    // Constructor to initialize the tree with a given size
    BinaryTree(int size) {
        this->size = size;
        tree = new int[size];
        lastIndex = -1; // Tree is initially empty
        for (int i = 0; i < size; ++i) {
            tree[i] = -1; // Initialize all elements to -1 (assuming -1 means empty)
        }
    }

    // Destructor to clean up the allocated memory
    ~BinaryTree() {
        delete[] tree;
    }

    // Function to insert a value into the tree
    void insert(int value) {
        if (lastIndex >= size - 1) {
            cout << "Tree is full" << endl;
            return;
        }
        tree[++lastIndex] = value;
    }

    // Function to get the index of the left child
    int leftChild(int index) {
        int left = 2 * index + 1;
        return (left < size) ? left : -1;
    }

    // Function to get the index of the right child
    int rightChild(int index) {
        int right = 2 * index + 2;
        return (right < size) ? right : -1;
    }

    // Function to get the index of the parent
    int parent(int index) {
        if (index == 0) {
            return -1; // Root node has no parent
        }
        return (index - 1) / 2;
    }

    // Function to display the tree
    void display() {
        for (int i = 0; i <= lastIndex; ++i) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    BinaryTree bt(10); // Create a binary tree with maximum size 10
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);

    cout << "Binary Tree:" << endl;
    bt.display();

    cout << "Left child of node 0: " << bt.leftChild(0) << endl;
    cout << "Right child of node 0: " << bt.rightChild(0) << endl;
    cout << "Parent of node 1: " << bt.parent(1) << endl;

    return 0;
}
