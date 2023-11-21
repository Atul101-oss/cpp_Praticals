#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

class Stack {
public:
    bool isEmpty() const {
        return items.empty();
    }

    void push(int item) {
        items.push(item);
    }

    int pop() {
        if (!isEmpty()) {
            int top = items.top();
            items.pop();
            return top;
        } else {
            throw runtime_error("pop from empty stack");
        }
    }

    int peek() const {
        if (!isEmpty()) {
            return items.top();
        } else {
            throw runtime_error("peek from empty stack");
        }
    }

    int size() const {
        return items.size();
    }

private:
    stack<int> items;
};

int performOperation(char op, int operand1, int operand2) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                throw runtime_error("Division by zero");
            }
        default:
            throw runtime_error("Invalid operator");
    }
}

int evaluatePostfix(const string& expression) {
    Stack stack;
    istringstream iss(expression);

    string token;
    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            stack.push(stoi(token));
        } else {
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            int result = performOperation(token[0], operand1, operand2);
            stack.push(result);
        }
    }

    if (stack.size() == 1) {
        return stack.pop();
    } else {
        throw runtime_error("Invalid postfix expression");
    }
}

int main() {
    string postfixExpression = "3 4 + 5 *";
    int result = evaluatePostfix(postfixExpression);
    cout << "Result of postfix expression " << postfixExpression << ": " << result << endl;

    return 0;
}

