#include <stack>
#include <string>

/**
 * Go through each char in s. Push any "open" parentheses onto stack
 * if there is a closing parenthese, the top of stack, must be the opening
 * version of that parenthese otherwise this isn't a valid string. If the
 * top is the associated opening version then we can just pop it off and continue.
 */
bool isValid(std::string s) {
    std::stack<char> parenStack;
    
    for(char& c : s) {
        if (c == '(' || c == '{' || c == '[') {
            parenStack.push(c);
        } else {
            if (parenStack.empty()) return false;
            if (c == ')' && parenStack.top() != '(') return false;
            if (c == '}' && parenStack.top() != '{') return false;
            if (c == ']' && parenStack.top() != '[') return false;
            parenStack.pop();
        }
    }
    
    return parenStack.empty();
}