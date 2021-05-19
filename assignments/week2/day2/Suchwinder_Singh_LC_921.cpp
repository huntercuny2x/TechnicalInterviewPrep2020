//  Minimum Add to Make Parentheses Valid

int minAddToMakeValid(string S) {
    int open = 0, close = 0;
    for(char ch: S){
        if(ch=='(') open++;
        else {
            if (open) open--;
            else close++;
        }
    }
    return open+close;
}