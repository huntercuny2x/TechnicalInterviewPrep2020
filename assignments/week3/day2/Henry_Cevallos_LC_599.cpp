#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
{
    vector<string> ans;
    unordered_map<string, int> map;

    for (int i = 0; i < list1.size(); i++) //loop through all strings in l2
    {
        map[list1[i]] = i; //maps each string its index
    }

    int min_sum = INT_MAX;
    int curr_sum = 0;
    for (int i = 0; i < list2.size(); i++) //loop through all strings in l2
    {
        if (map.count(list2[i])) //check if string is in the map
        {
            curr_sum = map[list2[i]] + i; //gets the sum of the indexes
            if (min_sum > curr_sum)       //if there is new min
            {
                min_sum = curr_sum;      //set new min
                ans.clear();             //remove all previous answers
                ans.push_back(list2[i]); //push new min sum string
            }
            else if (min_sum == curr_sum) //if they share min
            {
                ans.push_back(list2[i]); //push the string
            }
        }
    }
    return ans;
}