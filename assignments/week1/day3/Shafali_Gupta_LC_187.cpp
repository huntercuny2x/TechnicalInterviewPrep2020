class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> sequences; 
        vector<string> ret; 
        if(s.length()<11){
            return ret; 
        }
        for(int i =0; i<=s.length()-10; i++){

            if(sequences.find(s.substr(i, 10))!= sequences.end()){
                sequences[s.substr(i, 10)] +=1; 
            }
            else{
                sequences[s.substr(i, 10)] = 1; 
            }
        }
        for(map<string,int>::iterator it=sequences.begin(); it!=sequences.end(); it++){
            if(it->second>1){
                ret.push_back(it->first); 
            }
        }
        return ret; 
    }
};
