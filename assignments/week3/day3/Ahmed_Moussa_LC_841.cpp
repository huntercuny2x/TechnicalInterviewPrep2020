bool canVisitAllRooms(vector<vector<int>>& rooms) {
    if(rooms.size() == 0) return true;

    queue<int> reached;
    reached.push(0);

   vector<bool> vis(rooms.size());
    vis[0] = true;

    while(!reached.empty()) {
        int cur = reached.front();
        reached.pop();

        for(int adj: rooms[cur]) {
            if(vis[adj]) continue;
            vis[adj] = true;
            reached.push(adj);
        }
    }

    for(bool flg: vis) {
        if(!flg) return false;
    }
    return true;
}
