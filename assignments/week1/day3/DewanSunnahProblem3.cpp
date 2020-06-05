int lengthOfLongestSubstring(string s) {
    
    int ans;
    cout << s << endl;
    
    for(int i = 0; i < (int)s.length(); i++){
        int count[128] = {0};
        int j = i;
        for(j = i; j < (int)s.length(); j++){
          if(count[s[j]] == 1)
              break;
            else
               count[s[j]]++;
        }
        
        int len = j-i;
        //cout << i << " "<< j << " "<< len << endl;
        
        if (len > ans)
            ans = len;
        
        //cout << ans << endl;
    }
    
    return ans;
}
