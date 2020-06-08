#include <stack>
#include <string>
#include <iostream>
using namespace std;

//will check if string passed has balanced parenthesis
bool isValid(string s) {
    
    stack<char> parenthesis;
    for(char ch : s)    //loop through all chars in s
    {
        if(!parenthesis.empty() && 
            (ch == '}' && parenthesis.top() == '{'
            || ch == ')' && parenthesis.top() =='('
            || ch == ']' && parenthesis.top() == '['))  //when we encounter a close and its complement mathches top 
                parenthesis.pop();  //pop top
            
        else parenthesis.push(ch);  //everything else we push
            
    }
    return parenthesis.empty(); //if balanced the stack should be empty
}

//used to test
int main(int argc, char** argv)
{
    string str = argv[1];
    cout << isValid(str) << endl;
}