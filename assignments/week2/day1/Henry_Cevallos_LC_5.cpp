 #include <iostream>
 #include <string>
 #include <algorithm>
 using namespace std;

//This function does not work, it is what i could do within the hour
//This will only find if there is a palindrome with respect to the first char
//It finds this in O(N) time and O(1) space. If I could have figured out how to cycle
//this to other chars I think I could have gotten O(N^2) time
 string longestPalindrome(string s) {        
    bool palindrome[1001];  //constant space array        
    string original = s;
    reverse(s.begin(), s.end());    //reverse string passed
       
    for(int i = 0; i < original.length(); i++)  //loop through all chars in s
    {            
        if(original[i] == s[i]) //if they equal each other then it can be a palindrome
            palindrome[i] = true;
            
        else palindrome[i] = false; 

    }
    palindrome[s.length()] = false; //accounts for final spot in the array
        
    int start_max = 0;  
    int max = 0;
    int start = 0; 
    int count = 0;

    for(int i = 0; i <= original.length(); i++) //loop through the possible chars with starting point at 0
    {            
        if(palindrome[i])   //if it is a palindrome
        {
            count++;    //increment a counter of string size
        }
            
        else    //not a palindrome
        {
            if(count > max)     //we found a larger palindrome
            {
                max = count;    //note size of string
                start_max = start;  //note starting index
            }
                
            start = i + 1;  //increment our starting position. new palindrome starting
            count = 0;  //reset count
        }
    }        

    if(palindrome[start_max] == false)  //if there was no palindrome return a char
         return s.substr(start_max,1);
        
    return s.substr(start_max, max);    //palindrome found      
}