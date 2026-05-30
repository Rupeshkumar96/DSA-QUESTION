// evaluate_postfix.cpp
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(string expression) {
    stack<int> s;

    for (char ch : expression) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        else {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();

            switch(ch) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
                default: cout << "Invalid operator!" << endl; return -1;
            }
        }
    }

    return s.top();
}

int main() {
    string postfix = "23+54*+";
    int result = evaluatePostfix(postfix);

    cout << "Postfix Expression: " << postfix << endl;
    cout << "Result: " << result << endl;

    return 0;
}
