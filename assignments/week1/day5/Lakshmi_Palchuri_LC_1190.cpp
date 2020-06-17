#include<iostream>
#include<string>
#include <vector>
using namespace std;

string reverseParentheses(string s) 
{   
    vector<int> index_of_brackets;                  //stores index's of brackets
    string str = s;
    for(int i = 0; i < str.length(); i++)           //Goes through each element char in str
    {
        if(str[i] == ')')                           //if str is close parenthesis
        {
            int last = index_of_brackets.back();    //store the index of last )
            //cout << last;
            index_of_brackets.pop_back();           //deletes from list of brackets
            //cout << str.begin()+last+1 << str.begin()+i;
            reverse(str.begin()+last+1, str.begin()+i);     //reverses section of ()
        }
        else if(str[i] == '(')                      //if str is open parenthesis
        {
            index_of_brackets.push_back(i);         //push the index into vector
        }
    }

    str.erase(remove(str.begin(), str.end(), '('), str.end());  //removes open and closed parentheses
    str.erase(remove(str.begin(), str.end(), ')'), str.end());

    return str;
}
int main()
{
    cout << reverseParentheses("(u(love)i)");
    return 0;
}