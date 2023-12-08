#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int performPostFix(char operator1, int operand1, int operand2) {
    switch (operator1) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0)
                return operand1 / operand2;
            else
                throw runtime_error("Division by 0");
        default:
            throw runtime_error("Invalid operator");
    }
}

int evaluatePostFix(string expression) {
    stack<int> stackPF;

    istringstream iss(expression);
    string term;

    while (iss >> term) {
        if (isdigit(term[0]) || (term[0] == '-' && isdigit(term[1]))) {
            stackPF.push(stoi(term));
        } else {
            int operand1 = stackPF.top();
            stackPF.pop();
            int operand2 = stackPF.top();
            stackPF.pop();
            int result = performPostFix(term[0], operand1, operand2);
            stackPF.push(result);
        }
    }
    if (stackPF.size() == 1)
        return stackPF.top();
    else
        throw runtime_error("Invalid expression");
}

int main() {
    string expression;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Enter a PostFix expression\n";
        cout << "2. Evaluate the last entered expression\n";
        cout << "3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a PostFix expression: ";
                cin.ignore(); // Clear the newline character from the buffer
                getline(cin, expression);
                break;

            case 2:
                if (expression.empty()) {
                    cout << "No expression entered yet. Please enter a PostFix expression first.\n";
                } else {
                    cout << "PostFix expression: " << expression << endl;
                    try {
                        cout << "Result: " << evaluatePostFix(expression) << endl;
                    } catch (const exception& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                }
                break;

            case 3:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}