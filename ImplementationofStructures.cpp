#include <iostream>
#include <string>
using namespace std;

// Define a structure named 'Person'
struct Person {
    string name;
    int age;
    float height;
};

int main() {
    // Declare a variable of type 'Person'
    Person person1;

    // Assign values to the members of the structure
    person1.name = "John";
    person1.age = 30;
    person1.height = 6.0;

    // Print out the values
    cout << "Person 1:" << endl;
    cout << "Name: " << person1.name << endl;
    cout << "Age: " << person1.age << endl;
    cout << "Height: " << person1.height << " feet" << endl;

    return 0;
}
