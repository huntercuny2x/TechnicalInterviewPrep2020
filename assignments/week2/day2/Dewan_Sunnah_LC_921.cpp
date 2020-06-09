class Solution {
public:
    int minAddToMakeValid(string S) {
        int ans = 0;
        int count = 0;
        for(int i = 0; i < (int)S.length(); i++){
            if(S[i] == '(')
                count++;
            else
                count--;
            
            if(count == -1){
                ans++;
                count = 0;
            }
            
            
        }
        
        return ans + count;
    }
};
