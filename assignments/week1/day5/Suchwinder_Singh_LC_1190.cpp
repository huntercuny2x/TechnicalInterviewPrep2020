// Reverse Substrings Between Each Pair of Parentheses

string reverseParentheses(string s) {
    // I will store the index of the parenthesis in
    // in respect to the length of the result string into
    // a stack and then each time I encounter a closing 
    // parenthesis I will reverse the beginning of  where
    // the parenthesis was encountered in the result, and 
    // the end of the result 
    stack<int> open_brace_tracker;
    string result = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i]=='(') open_brace_tracker.push(result.size());
        else if(s[i]==')') {
            reverse(result.begin()+open_brace_tracker.top(), result.end());
            open_brace_tracker.pop();
        }
        else {
            result+=s[i];
        }
        cout << "Result: " << result;
    }
    return result;
}

// Time Complexity: O(N*(M/2)) -> roughly evaluate to O(N^2)
// Space Complexity: O(N-M+M/2) // we dont know if there are more parenthesis or not
// in space complexity m = number of parenthesis, and n is length of string. -->     
// actually evaluates to just O(N)