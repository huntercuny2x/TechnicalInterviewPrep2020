#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk; 
        string result;
        for(char& ch: s){
            if(ch == ')'){
                string tmp;
                char chr_tmp = stk.top();
                stk.pop();
                while(chr_tmp != '(' && !stk.empty()){
                    tmp += chr_tmp;
                    chr_tmp = stk.top();
                    stk.pop();
                }
                for(char& c: tmp)
                    stk.push(c);
            } else 
                stk.push(ch);
        }
        
        while(stk.size()){
            result += stk.top();
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result; 
    }
};
