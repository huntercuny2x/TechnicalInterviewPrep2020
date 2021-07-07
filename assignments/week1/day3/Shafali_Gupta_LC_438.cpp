//Gave Time Limit Exceeded Error
//This code goes through every substriing in s that is size p and sorts it. It the compares the sorted string to a sorted p to check if they are aagrams. 
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret; 
        string sub = ""; 
        sort(p.begin(), p.end());
        if(p.length()>s.length()){
            return ret; 
        }
        for(int i =0; i<s.length()-p.length()+1; i++){
            sub = s.substr(i, p.length());
            sort((sub).begin(), (sub).end()); 
            if(sub ==p){
                ret.push_back(i); 
            }
        }
        return ret; 
    }
};
