int minAddToMakeValid(string S) {
    int ans = 0, counter = 0;
    for(char c: S) {
        if(c == '(') counter ++;
        else {
            if(counter == 0) ans ++;
            else counter--;
        }
    }
    return ans + counter;
}
