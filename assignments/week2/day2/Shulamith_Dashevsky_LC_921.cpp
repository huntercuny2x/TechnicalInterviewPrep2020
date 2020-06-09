class Solution {
public:
    int minAddToMakeValid(string S) {
       stack<char> pStack;
        //check if empty return 0 if yes
        int answer = 0;
       for(int i=0; i<S.length(); i++){
          if(S[i] == '('){
              pStack.push('(');
          }
          else{
              if(pStack.empty()){
                  answer++;
              }
              else{
                  pStack.pop();
              }

          }
       }
        answer += pStack.size();
        return answer;
    }
};
