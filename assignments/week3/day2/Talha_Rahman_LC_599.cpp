#include <vector>
#include <unordered_map>
#include <string>
using std::vector;
using std::string;

/**
 * Go through first list and map each string to it's position in the list.
 * Go through second list and if you find the element in the map, then push
 * it into the res vector if map[elem] + i == lowest_index or if it's less 
 * than the lowest index then we have to clear the res vector and push our 
 * new elem into the vector
 */
vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    vector<string> res{};
    std::unordered_map<string, int> map;
    
    for(int i = 0; i < list1.size(); ++i) {
        map[list1[i]] = i;
    }
    
    int lowest = INT32_MAX;
    for(int i = 0; i < list2.size(); ++i) {
        if (map.find(list2[i]) != map.end()) {
            if (map[list2[i]] + i < lowest) {
                res.clear();
                res.push_back(list2[i]);
                lowest = map[list2[i]] + i;
            } else if (map[list2[i]] + i == lowest) {
                res.push_back(list2[i]);
            }
        }
    }
    
    return res;
}