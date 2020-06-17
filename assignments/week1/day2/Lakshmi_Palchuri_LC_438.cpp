#include <iostream>
#include <vector>
using namespace std;

vector<int> findAnagrams(string s, string p) 
{
    vector<int> ans; //create a vector and empty str var
    string str = "";
    int slength = s.length();
    int plength = p.length();
    sort(p.begin(),p.end());    //sorts p

    if(plength > slength)   
    {
        return ans;
    }   

    for(int i = 0; i < slength-plength+1; i++)
    {
        str = s.substr(i, plength);
        sort(str.begin(), str.end()); //sorts string str

        if(str == p)  //now at this point if the first sort p equals the second one it should be an anagram so its added to the vector ans
        {
            ans.push_back(i);
        }
    }
    return ans;
}
