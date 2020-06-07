 #include <stack>
 #include <string>
 using namespace std;
 
 string reverseParentheses(string s) {
    stack<int> indexes; //used to store indexes
    string ans="";
    for(int i = 0; i < s.length(); i++) //loop though s's chars
    {
        if(s[i] == '(')   //we found '('
            indexes.push(i+1);  //We care about the index after the '(' push it to stack
        else if(s[i] == ')')  //found ')'
        {
            reverse(s.begin() + indexes.top(), s.begin() + i);  //we reverse betweeen the most recent '()' pair
            indexes.pop();  //pop to move onto next pair of '()'
        }
            
    }
        
    //we reversed the enire string passed so now we must append that to ans
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == ')' || s[i] == '(')  //avoid these chars
            continue;
        ans.push_back(s[i]);    //add to answer
    }        
    return ans;
        
}