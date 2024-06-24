#include <iostream>
#include <stack>
#include <string>
#include <cctype>

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

bool isLeftAssociative(char op) {
    return op != '^';
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isOperand(char c) {
    return std::isalnum(c);
}

std::string infixToPostfix(const std::string &infix) {
    std::stack<char> stack;
    std::string postfix;
    
    for (char token : infix) {
        if (isOperand(token)) {
            postfix += token;
        } else if (isOperator(token)) {
            while (!stack.empty() && stack.top() != '(' &&
                   ((isLeftAssociative(token) && precedence(token) <= precedence(stack.top())) ||
                    (!isLeftAssociative(token) && precedence(token) < precedence(stack.top())))) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(token);
        } else if (token == '(') {
            stack.push(token);
        } else if (token == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();  // Remove '(' from stack
        }
    }
    
    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }
    
    return postfix;
}

int main() {
    std::string infix;
    std::cout << "Input Infix: ";
    std::cin >> infix;
    
    std::string postfix = infixToPostfix(infix);
    std::cout << "Output Postfix : " << postfix << std::endl;
    
    return 0;
}