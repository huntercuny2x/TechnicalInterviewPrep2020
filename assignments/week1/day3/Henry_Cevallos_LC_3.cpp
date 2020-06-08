#include <string>
#include <set>
#include <iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {
        set<char> sub_str;
        int max = 0;
        int j = 0;
        
        for(int i = 0; i < s.length() && j < s.length();)   //loop while we are in bounds of s
        {
            if(!sub_str.count(s[j]))    //new char not in set
            {
                sub_str.insert(s[j]);   //add to set
                j++;    //move on to look at next char
                if(max < (j - i))   //check max size   
                    max = j - i;    //j = end index i = start index so this gives us length
                
                 //move onto next char
            }
            else //char already in set so remove first item
            {   
                sub_str.erase(s[i]);    //erase the starting char
                i++; //move onto next char to start from
            }
        }
        
        return max; 
        
        /*
        This was my initial attempt at a brute force approach which should have been O(n^3) but did not finish
        After a bit I realized that we could do a hash set and coded what is above. I left this hear
        so that I can see my initial thought process and be able to see my improvements

        string sub = s; 
        string maxSub = "";
        int max = 0;
        bool invalid = false;
        for(int i = 0; i < s.length(); i++) //loop through chars of s
        {
            sub = s.substr(i, s.length() - 1 - i);  //look at each possible subtring of s starting from i to end
            for(int j = 0; j < sub.length(); j++)
            {
                if(j != sub.find_last_of(sub[j]))   //if there is a repeat character
                {
                    invalid = true; //invalid substr
                    break;  //no need to check this substr further
                }
            }
                   
            if(!invalid && max < sub.length())  //If it was a valid substr and its max is greater
            {
                max = sub.length(); //set max substring length
                maxSub = sub;   //test
            }
            
            invalid = false; //reset invalid               
        }
        cout << maxSub << endl; //test    
        return max;
        */
    }

    int main()
    {
        string str;
        cin >> str;

        cout << lengthOfLongestSubstring(str) << endl;
    }