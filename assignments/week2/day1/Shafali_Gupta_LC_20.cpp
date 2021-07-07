class Solution {
public:
    bool isValid(string s) {
        stack<char> pars;
        if(s.length() %2 != 0){
            return false;
        }
        for(int i =0; i< s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                pars.push(s[i]);
            }
            else if(s[i] == ')'){
                // cout << "ifie";
                // cout << pars.top();
                if(!pars.empty() && pars.top() == '('){
                     pars.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i] == '}'){
                if(!pars.empty() && pars.top() == '{'){
                    pars.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i] == ']'){
                if(!pars.empty() && pars.top() == '['){
                    pars.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(!pars.empty()){
            return false;
        }
        return true;
    }
};
