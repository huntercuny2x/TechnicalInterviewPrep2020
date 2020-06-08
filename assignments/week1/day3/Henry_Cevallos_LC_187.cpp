#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    if(s.length() <= 9) //edge case gaurd. invalid string
        return {};
        
    vector<string> ans; 
    unordered_map<string, int> map; //maps string to int counters
        
    for(int i = 0; i <= s.length() - 10; i++)   //loops through strings possible sequences
    {
        string dna = s.substr(i,10);    //get sequence starting from i
        if(map[dna] == 1)  //if it exists in the map and only accounted once
            ans.push_back(dna); // add it to ans beacuse that means its repeated
            
        map[dna] += 1;   //increment the counter in map at key dna
    }
        
    return ans; 
        
}

int main()
{
    string str;
    cin >> str;
    vector<string> test = findRepeatedDnaSequences(str);
    for(string s: test)
        cout << s << " ";
    cout << endl;
}