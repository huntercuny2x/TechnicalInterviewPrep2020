// Repeated DNA Sequences

vector<string> findRepeatedDnaSequences(string s) {
    vector<string> result;
    if(s.length()<10) return result; // if string too small
    unordered_map<string, int> tracker;
    // add all possiblle repeating characters into a hash map 
    // (this is a sliding window where the window is of size 10 
    // and slides 1 index over each time)
    for(int i = 0, j = i+10; i<s.length()-9; i++){ 
        tracker[s.substr(i,j)]++; // const cause substr is always 10 size
    }
    // based on number of possible combinations which is generally n-9
    for(pair<string, int> count: tracker){ 
        if(count.second>1){
            result.push_back(count.first);
        }
    }
    return result;
}

// Time Complexity: O(N)
// Space Complexity: O(N) 