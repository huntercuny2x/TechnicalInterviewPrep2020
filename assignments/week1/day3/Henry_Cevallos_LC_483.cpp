#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> findAnagrams(string s, string p) {
    if(s.length() < p.length()) //edgecase gaurd. invalid string
        return {};
        
    sort(p.begin(), p.end()); //sort p
    vector<int> ans;
    for(int i = 0; i <= s.length() - p.length(); i++) //increment by intervals of p length
    {
        string tmp = s.substr(i,p.length());    //get substr that should be p
        sort(tmp.begin(), tmp.end());   //sort the substr
        if(tmp == p)    //they are anagram
            ans.push_back(i);   //push back index
    }
        
    return ans;
}

int main()
{
    string s, p;
    cin >> s >> p;
    vector<int>  ans = findAnagrams(s, p);
    for(int i: ans)
        cout << i << " ";
    cout << endl;
}