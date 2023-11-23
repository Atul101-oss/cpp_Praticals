#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    string userInput;

    // Prompt the user for input
    cout << "Enter a line of text: " << argc << argv[0] << argv[1];

    // // Use getline to read a whole line of text from the user
    getline(std::cin, userInput);

    // // Display the entered text
    cout << "You entered: " << userInput << std::endl;

    return 0;
}
