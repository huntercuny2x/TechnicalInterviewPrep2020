class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> chars;
        string ret="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                chars.push(i);
            if(s[i]==')'){
              int j = chars.top();
              chars.pop();
              reverse(s.begin()+j,s.begin()+i);
              }
        }

        for(int i =0; i< s.length(); i++){
            if(isalpha(s[i])){
                ret+=s[i];
            }
        }
        return ret;
    }
};
