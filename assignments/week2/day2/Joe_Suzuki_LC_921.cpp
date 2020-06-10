class Solution {
public:
    int minAddToMakeValid(string S) {
        int count = 0, result = 0;
        for(char& ch: S){
            if(ch == '(') count++;
            if(ch == ')') count--;
            if(count < 0){
                result++;
                count++;
            }
        }
        return count + result;
    }
};
