//  Reverse Only Letters

string reverseOnlyLetters(string S) {
    int begin = 0, end = S.length()-1;
    while(end>begin){ 
        if(!isalpha(S[end])){
            end--;
        }
        if(!isalpha(S[begin])){
            begin++;
        }
        if(isalpha(S[begin]) && isalpha(S[end])){
            swap(S[begin], S[end]);
            begin++;
            end--;
        }
    }
    return S;
}

// Time Complexity: O(N)
// Space Complexity: O(1)