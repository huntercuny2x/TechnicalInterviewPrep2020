vector<string> findRepeatedDnaSequences(string s) {
    
    
    
    map<string, int> nonrepeat;
    vector<string> repeat;
    
    if (s.length()<10)
        return repeat;
    
    //cout << ("AAAAACCCCC" == "CCCCCAAAAA");
    
    for(int i = 0; i <= s.length()-10; i++){
        if(nonrepeat.find(s.substr(i, 10)) == nonrepeat.end())
            nonrepeat[s.substr(i, 10)]++;
        else{
            if(nonrepeat[s.substr(i, 10)] == 1)
                repeat.push_back(s.substr(i, 10));
            nonrepeat[s.substr(i, 10)]++;

        }
            
    }
   return repeat;
}
