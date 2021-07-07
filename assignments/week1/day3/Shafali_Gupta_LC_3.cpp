//This passed all the test cases, but it takes too much time. I'm not sure how to make it faster. 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0; 
        int max_len = 0; 
        for(int i =0; i<s.length(); i++){
             map<char,int> letters;
            len=1; 
            letters[s[i]] = 1; 
            for(int j =i+1; j<s.length(); j++){
                if(letters.find(s[j])!= letters.end()){ // if it's in the map 
                    j = s.length(); 
            }
            else{
                letters[s[j]] = j;
                len+= 1; 
            }
            }
            max_len = max(len, max_len); 
        }
        return max_len; 
        
    }
};
