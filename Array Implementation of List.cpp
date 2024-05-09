#include <iostream>
using namespace std;

#define MAX_SIZE 100 // Maximum size of the list

class ArrayList {
private:
    int arr[MAX_SIZE];
    int size;

public:
    ArrayList() {
        size = 0;
    }

    void insert(int val) {
        if (size >= MAX_SIZE) {
            cout << "List is full. Cannot insert more elements.\n";
            return;
        }
        arr[size++] = val;
    }

    void remove(int val) {
        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (arr[i] == val) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Element not found in the list.\n";
            return;
        }
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void display() {
        if (size == 0) {
            cout << "List is empty.\n";
            return;
        }
        cout << "List elements: ";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayList list;
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.display();

    list.remove(10);
    list.display();

    return 0;
}
