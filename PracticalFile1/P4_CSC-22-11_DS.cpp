#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int performPostFix(char operator1, int operand1, int operand2){
    switch(operator1){
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0)
                return operand1/operand2;
            else
                throw runtime_error("Division by 0");
        
        default :
            throw runtime_error("invalid operator");
    }
}

int evaluatePostFix(string expration){
    stack<int> stackPF;
    
    istringstream iss(expration);
    string term;
    
    while(iss >> term){
        if (isdigit(term[0]) || (term[0] == '-' && isdigit(term[1]))) {
            stackPF.push(stoi(term));
        }else{
            int operand1 = stackPF.top();
            stackPF.pop();
            int operand2 = stackPF.top();
            stackPF.pop();
            int result = performPostFix(term[0],operand1,operand2);
            stackPF.push(result);
        }
    }
    if (stackPF.size() <= 1)
        return stackPF.top();
}

int main (){
    string expration;
    cout << "Enter an postfix : ";
    cin >> expration;
    
    evaluatePostFix(expration);
}