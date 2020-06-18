class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> things;
        set<int> r;
        for(int i=0; i<rooms[0].size(); i++){
            things.push(rooms[0][i]);
            r.insert(rooms[0][i]);
        }
        while(!things.empty()){
            int a = things.top();
            things.pop();
            for(int i =0; i<rooms[a].size(); i++){
                if(r.count(rooms[a][i])==0){
                    things.push(rooms[a][i]);
                    r.insert(rooms[a][i]);
                }
            }
        }
        for(int i =1; i<rooms.size(); i++){
            if(r.count(i) ==0){
                return false;
            }
        }
        return true;
    }
};
