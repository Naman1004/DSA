#include <iostream>
#include <vector>
using namespace std;

class BinaryTree {
private:
    vector<int> tree;  // Array to store the tree nodes
    int capacity;      // Maximum size of the tree

public:
    // Constructor to initialize the tree with a given capacity
    BinaryTree(int capacity) {
        this->capacity = capacity;
        tree.resize(capacity, -1);  // Initialize tree with -1 indicating empty nodes
    }

    // Function to insert a node at the first available position
    void insert(int value) {
        for (int i = 0; i < capacity; ++i) {
            if (tree[i] == -1) {  // Find the first available spot
                tree[i] = value;
                return;
            }
        }
        cout << "Tree is full. Cannot insert more nodes." << endl;
    }

    // Function to get the left child of a node at index i
    int leftChild(int i) {
        int left = 2 * i + 1;
        if (left < capacity && tree[left] != -1)
            return tree[left];
        return -1;  // No left child
    }

    // Function to get the right child of a node at index i
    int rightChild(int i) {
        int right = 2 * i + 2;
        if (right < capacity && tree[right] != -1)
            return tree[right];
        return -1;  // No right child
    }

    // Function to get the parent of a node at index i
    int parent(int i) {
        if (i == 0) return -1;  // Root node has no parent
        int parentIndex = (i - 1) / 2;
        return tree[parentIndex];
    }

    // Function to print the tree
    void printTree() {
        for (int i = 0; i < capacity; ++i) {
            if (tree[i] != -1)
                cout << tree[i] << " ";
            else
                cout << "x ";  // x denotes an empty spot
        }
        cout << endl;
    }
};

int main() {
    int capacity = 15;  // Setting the capacity of the tree
    BinaryTree bt(capacity);

    // Inserting nodes into the tree
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);

    // Printing the tree
    cout << "Tree: ";
    bt.printTree();

    // Testing the left and right child functions
    int index = 0;
    cout << "Left child of node at index " << index << ": " << bt.leftChild(index) << endl;
    cout << "Right child of node at index " << index << ": " << bt.rightChild(index) << endl;

    // Testing the parent function
    index = 2;
    cout << "Parent of node at index " << index << ": " << bt.parent(index) << endl;

    return 0;
}
