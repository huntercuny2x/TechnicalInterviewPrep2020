class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> s;
        int counter =0;
        for(int i =0; i < S.length(); i++){
            if(S[i] == '('){
                s.push(S[i]);
            }
            else{
                if(s.empty()){
                    counter++;
                }
                else if(s.top() == '('){
                    s.pop();
                }
                else if(s.top() != '('){
                    counter ++;
                    s.pop();
                }
            }
        }
        if(!s.empty()){
            while(!s.empty()){
                counter ++;
                s.pop();
            }
        }
        return counter;
    }
};
