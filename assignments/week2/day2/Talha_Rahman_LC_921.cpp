#include <string>
#include <stack>

/**
 * My approach is to go through each element in the string S and push them onto 
 * a stack. However, if you find a closing parenthese, check if the top of the 
 * stack is an opening parenthese and if so then pop that off else just push onto stack.
 * By the end the size of the stack will be the number of missing parentheses to make valid.
 */
int minAddToMakeValid(std::string S) {
    std::stack<char> stk;
    
    for(char& c : S) {
        if (stk.empty() || c == '(') {
            stk.push(c);
            continue;
        }
        if (c == ')') {
            if (stk.top() == '(') stk.pop();
            else stk.push(c);
        }
    }
    
    return stk.size();
}