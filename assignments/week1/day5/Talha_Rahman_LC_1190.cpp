#include <string>
#include <stack>
#include <algorithm>

// my strategy is adding the characters to a new string and then
// reversing the characters in that string. When I see a '(' I will
// put that position into the stack and then just add the characters after
// it into the string. Then when I find the ')'. I will remove the position
// from the stack and use it as an offset in the original string, to start 
// reversing from there to the end of the string. 
std::string reverseParentheses(std::string s) {
    std::stack<int> stk;
    std::string reversed = "";
    
    for(int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            stk.push(reversed.size());
        } else if (s[i] == ')') {
            int offset = stk.top();
            stk.pop();
            reverse(reversed.begin() + offset, reversed.end());
        } else
            reversed += s[i];
    }
    return reversed;
}