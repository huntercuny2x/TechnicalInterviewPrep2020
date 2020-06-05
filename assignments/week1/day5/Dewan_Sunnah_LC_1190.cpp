/*
Name: Dewan Sunnah
Date: 6/5/20
Problem: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
 
 */

#include <stack>
#include <iostream>
using namespace std;


string reverse_string(string s){
    string ans = "";
    for (int i = s.length()-1; i >= 0; i--)
        ans+= s[i];
    
    return ans;
   
}

string reverseParentheses(string s) {
              
    //use a stack to keep track of the last '(' index since i can't use hashmap
    stack<int> open_indices;
        
    for (int i = 0; i < (int)s.length(); i++){
        
        if (s[i] == '(')
            open_indices.push(i);
                
        if (s[i] == ')'){

            int left_index = open_indices.top();
            open_indices.pop();
            //cout << left_index << " " << i << endl;
            
            //part of the string that needs to be flipped
            string flip = s.substr((left_index+1), ((i - left_index) - 1));
            //cout << flip << endl;
            
            flip = reverse_string(flip);
            //cout << s.substr(0, left_index+1) << " " << flip << " " <<s.substr(i + 1, s.length() - i) << endl;

            //puts the string back together
            s = s.substr(0, left_index+1) + flip + s.substr(i, (int)s.length() - i);
                
        }
        
    }
        
    //removes the '(' and ')' from the string, need to do this last so theres no errors caused by changing the lenght of s.
    string ans = "";
    for(int i = 0; i < (int)s.length(); i++){
        if(s[i] != '(' && s[i] != ')')
            ans+=s[i];
        
    }
        
    return ans;
        
}

int main(){
    
    return 0;
    
}
    
