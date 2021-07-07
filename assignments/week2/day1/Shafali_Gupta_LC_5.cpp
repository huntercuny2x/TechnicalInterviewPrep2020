/*
I couldn't figure out how to optimize this. This takes too long, I think it is either O(n^2) or O(n^3).
*/

class Solution {
public:
    string longestPalindrome(string s) {
        string longest = "";
        for(int i = 0; i< s.length(); i++){
            for(int j =1; j<s.length()+1; j++){
                string temp = s.substr(i,j);
                reverse(temp.begin(), temp.end());
                if(s.substr(i,j) == temp){
                    if(longest.length() < temp.length()){
                        longest = temp;
                    }
                }
            }
        }
        return longest;
    }
};
