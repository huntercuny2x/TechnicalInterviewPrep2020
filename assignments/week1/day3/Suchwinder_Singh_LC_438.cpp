// Find all Anagrams in a String

vector<int> findAnagrams(string s, string p) {
    int s_length = s.size(), p_length = p.size();
    cout << p_length << endl;
    if(p_length>s_length){ //if the anagram key is too big then return nothing
        return {};
    }
    // track which letters are present and compare later (this is going to be used as our window as well)
    vector<int> result, p_tracker(26, 0), s_tracker(26,0); 
    // fill in our anagram keys that we will use to search for matching characters in string
    // in addition check the first p_length characters in s since we are already populating the p_tracker
    for(int i = 0; i < p_length; i++){
        p_tracker[p[i]-'a']++;
        s_tracker[s[i]-'a']++;
    }
    // Here we are checking to see if the first p_length characters in s match the anagram key
    if(p_tracker==s_tracker) result.push_back(0); // we do this cause we already populat the s_tracker in first for loop
    
    // Here we check remaining characters in the string
    for(int end = p_length; end < s_length; end++){
        int begin = end-p_length;
        
        s_tracker[s[end]-'a']++; // move window to the right by adding next character into array
        s_tracker[s[begin]-'a']--; // delete left window value 
        
        if(s_tracker == p_tracker) result.push_back(begin+1); // check if after moving window if the ectors match
    }
    return result;
}

//Time Complexity: O(N)
//Space Complexity: O(N)

// map code too slow

// unordered_map<char, int> key_word; // not using set cause p may have duplicate letters
// for(char ch: p){ // track the letters in the p string
//     key_word[ch]++;
// }
// int s_length = s.size();
// int p_length = p.size();
// for(int i = 0, j=i+p_length; i < s_length; i++, j++){
//     // unordered_map<char, int> window;  // track the letters in the window
//     bool valid = true;
//     // for(int k = i;k<j; k++){
//     //     window[s[k]]++;
//     // }
//     // for(pair<char, int> letter_count: window){
//     //     if(letter_count.second!=key_word[letter_count.first]){
//     //         valid = false;; // go to the next iteration of the loop
//     //     }
//     // }
//     for(int k = i; k < j; k++){
//         if(key_word[s[k]] == 0){
//             valid = false;
//         }
//     }
//     if(valid) result.push_back(i);
// }