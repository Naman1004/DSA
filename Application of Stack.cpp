#include <iostream>
#include <stack>
#include <string>

int main() {
    // Create a stack of characters
    std::stack<char> charStack;

    // Input string
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    // Push all characters of the string into the stack
    for (char ch : input) {
        charStack.push(ch);
    }

    // Pop all characters from the stack and append to the result string
    std::string reversed;
    while (!charStack.empty()) {
        reversed += charStack.top();
        charStack.pop();
    }

    // Output the reversed string
    std::cout << "Reversed string: " << reversed << std::endl;

    return 0;
}
