#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    unordered_set<int> visited;
    queue<int> to_visit;
    to_visit.push(0);
    
    while(!to_visit.empty()) {
        int room_num = to_visit.front(); to_visit.pop();
        
        // go through all keys and put any new ones into queue
        for(int& key : rooms[room_num]) {
            if (visited.count(key) == 0) {
                to_visit.push(key);
                if (visited.size() == rooms.size()) return true;
            }
        }
        visited.insert(room_num);
    }
    
    return visited.size() == rooms.size();
}
