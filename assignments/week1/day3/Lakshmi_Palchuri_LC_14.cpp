#include <iostream>
using namespace std;

/*
Notes:

write a fx to fin longest common prefix string in array of strs
if no common prefix return empty str

ex.
vector: {"flower","flow","flight"}
out: fl

all given inputs are lowercase

ex.
{"night", "nine", "nimble"}
out : "'ni"

*/

string longestCommonPrefix(vector<string>& strs)
{
    
    if (strs.length() == 0)
    {
        return "";
    }
    
    if (strs.length() == 1)
    {
        return strs[0];
    }

    // "flower","flow","flight"
    string first_element = strs[0];
    string result = "";
    
    for(int i = 0; i < strs.size(); i++)
    {
        if(strs[i] == first_element)
        {
            continue;
        }
        int j = 0;
        while (i < str[i].length())
        {
            if(str[j] == first_element[j])
            {
                result += str[j];
            }
            else
            {
                break;
            }
            j++;
        }
    }

    return result;
    /*int index = 0;
    int index_other_elements = 0;
    
    while(index < first_element.length()) //0<6  1<6 2<6
    {
        if(first_element[index] == strs[index][index_other_elements]) //f== f o == o
        {
            result += first_element[index]; //result += fl
            continue;   
        }
        else
        {
            break;
        }
        index++;
        index_other_elements++; //index = 2, index_other_elements = 2
    }
    return result;*/
}


int main()
{
    return 0;
}