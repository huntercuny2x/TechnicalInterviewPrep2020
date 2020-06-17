#include <iostream>
using namespace std;
#include <vector>
#include <string>

/*
Notes:
A sentence s is given w words separate by spaces

each word has lower + upper case letters

convert sentence to goat latin 
1. if word starts w vowel + "ma" to end
    apple = applema
2. begins w constanant remove first letter and append to end + "ma"
    goat = oatgma
3. add a to end of each word per word index
    apple -> applemaa
    
    return string sentence 

    I speak Goat Latin -> Imaa peaksmaaa oatGmaaaa atinLmaaaaa

    happy birthday ale -> appyhmaa irthdaybmaaa alemaaaa

Psuedocode

    array stores aeiouAEIOU
    find a way to convert words string into an array
    take the first letter of each word and see if its in aeiou 
        if it is add to str
        else
        //its a constanant 
            remove the first letter and add to the end
        + ma + number of a's (same as index)
    return result string


*/

string toGoatLatin(string S)
{
    vector<string> words;
    string ans = "";
    string s = S;
    s += " ";
    string answer = "";
    int index = 0;
    for(int i = 0; i < s.length(); i++)
    {   
        if(s[i] == ' ')
        {
            string temp = "";
            temp = s.substr(index, i-index);
            words.push_back(temp);
            index = i+1;

        }
    }

    //separates words into strings and pushes into vector
    
    for(int i = 0; i < words.size(); i++)
    { 
        char l1 = words[i][0];//if vowel
        if(l1 == 'a' || l1 == 'e' || l1 == 'i' || l1 == 'o' || l1 == 'u' || l1 == 'A' || l1 == 'E' || l1 == 'I' || l1 == 'O' || l1 == 'U') 
        {            
            ans += words[i];
        } 
        else//constanat
        {
            char letter1 = words[i][0];
            ans += words[i].substr(1,words[i].length()-1) + letter1;
        }
            
        ans += "ma";
        int adding_a = i+1;
        while(adding_a--) 
            ans += 'a';
        ans += ' ';
    }
    return ans.substr(0,ans.length()-1);
}

int main()
{
    cout << "ans: "<< toGoatLatin("I speak Goat Latin");
    return 0;
}