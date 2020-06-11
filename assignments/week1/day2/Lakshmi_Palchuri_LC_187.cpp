#include <iostream>
#include <unordered_map>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) 
{
    unordered_map<string, int> repeatedSequences;
    vector<string> ans;

    int len = s.length();
    
    if (len >= 10)
    {
        for (int i = 0; i <= len - 10; i++)
        {
            repeatedSequences[s.substr(i, 10)]++;
        }
    }

    for (auto i : repeatedSequences)
    {
        if (i.second > 1)
        {
            ans.push_back(i.first);
        }
    }

    return ans;    
}