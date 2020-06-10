#include <stack>
#include <iostream>
#include <string>
using namespace std;

//O(N) time O(N) space approach
int minAddToMakeValid(string S) {
    
    stack<char> parenthesis;
    for(char& ch : S)   //loop through chars in S   
    {
        //removes top if ch's complement is on top of stack
        if (!parenthesis.empty() && ch == ')' && parenthesis.top() == '(')
            parenthesis.pop();

        else
            parenthesis.push(ch); //add everything else to stack
    }
    //stack now contains all unbalanced parenthesis
    int count = 0;
    while (!parenthesis.empty()) //loop through stack
    {
        count++;           //count all unbalnced paranthesis
        parenthesis.pop(); //move onto next char
    }
    return count;
}

int main(int argc, char**argv) 
{
    cout << minAddToMakeValid(argv[1]) << endl;
}