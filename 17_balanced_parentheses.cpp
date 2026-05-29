// balanced_parentheses.cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string expression) {
    stack<char> s;

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;

            char top = s.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                s.pop();
            } else {
                return false;
            }
        }
    }

    return s.empty();
}

int main() {
    string expr1 = "{[()]}";
    string expr2 = "{[(])}";
    string expr3 = "((())";

    cout << "Expression: " << expr1 << " -> "
         << (isBalanced(expr1) ? "Balanced" : "Not Balanced") << endl;
    cout << "Expression: " << expr2 << " -> "
         << (isBalanced(expr2) ? "Balanced" : "Not Balanced") << endl;
    cout << "Expression: " << expr3 << " -> "
         << (isBalanced(expr3) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}
