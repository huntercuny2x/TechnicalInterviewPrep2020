#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool uniqueCharacters(string s) 
{ //checks that all chars of str are unique
    if(s.size() == 1)
    {
        return false;
    }
    for (int i = 0; i < s.length() - 1; i++) 
    { 
        for (int j = i + 1; j < s.length(); j++) 
        { 
            if (s[i] == s[j]) 
            { 
                return false; 
            } 
        } 
    } 
    return true; 
} 
int lengthOfLongestSubstring(string s) 
{  
    //adds any unique strs lengths to a vector of ints and find max of ints in vector
    if(s.size() == 0 || s.size() ==1)
    { 
        return s.size();
    }
    vector<int> result ; 
    int ans = 1;
    for (int i = 0; i <= s.length(); i++) 
    { 
        for (int j = 1; j <= s.length()-i; j++) 
        { 
          if(uniqueCharacters(s.substr(i, j)))
          {
              //cout << s.substr(i, j).length() << endl;
              result.push_back(s.substr(i, j).length()); 
          }
        } 
    } 
    return *max_element(result.begin(), result.end());
    
}
int main()
{
  cout << "ANS: " <<lengthOfLongestSubstring("aaaaaa");
  return 0;
}