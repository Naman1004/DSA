#include <iostream>
#include <string>

using namespace std;

// Define a structure
struct Person {
    string name;
    int age;
};

int main() {
    // Declare a pointer to a structure
    Person *personPtr;

    // Allocate memory for a structure using new keyword
    personPtr = new Person;

    // Access and modify structure members using arrow operator (->)
    personPtr->name = "John";
    personPtr->age = 30;

    // Access structure members using pointer
    cout << "Name: " << personPtr->name << endl;
    cout << "Age: " << personPtr->age << endl;

    // Deallocate memory using delete keyword
    delete personPtr;

    return 0;
}
