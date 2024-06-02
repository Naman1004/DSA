#include <iostream>
using namespace std;

// Node structure for the BST
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Class for the BST
class BST {
private:
    Node* root;

    // Helper function to insert a node
    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }

        if (val < node->data) {
            node->left = insert(node->left, val);
        } else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        
        return node;
    }

    // Helper function for inorder traversal
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    // Helper function to search for a value
    Node* search(Node* node, int val) {
        if (node == nullptr || node->data == val) {
            return node;
        }

        if (val < node->data) {
            return search(node->left, val);
        } else {
            return search(node->right, val);
        }
    }

    // Helper function to find the minimum value node
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function to delete a node
    Node* deleteNode(Node* node, int val) {
        if (node == nullptr) {
            return node;
        }

        if (val < node->data) {
            node->left = deleteNode(node->left, val);
        } else if (val > node->data) {
            node->right = deleteNode(node->right, val);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        
        return node;
    }

public:
    BST() : root(nullptr) {}

    // Function to insert a value into the BST
    void insert(int val) {
        root = insert(root, val);
    }

    // Function for inorder traversal
    void inorder() {
        inorder(root);
        cout << endl;
    }

    // Function to search for a value in the BST
    bool search(int val) {
        return search(root, val) != nullptr;
    }

    // Function to delete a value from the BST
    void deleteValue(int val) {
        root = deleteNode(root, val);
    }
};

int main() {
    BST bst;

    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Search for 4: " << (bst.search(4) ? "Found" : "Not Found") << endl;
    cout << "Search for 9: " << (bst.search(9) ? "Found" : "Not Found") << endl;

    bst.deleteValue(3);
    cout << "Inorder traversal after deleting 3: ";
    bst.inorder();

    return 0;
}
