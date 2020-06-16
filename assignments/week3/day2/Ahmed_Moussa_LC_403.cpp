bool canCross(vector<int>& input) {
  unordered_set<int> stones;
  for(int x : input) stones.insert(x);

  queue<pair<int,int>> units;
  unordered_map<int, unordered_set<int>> vis;

  units.push({0, 0});
  vis[0].insert(0);

  while(!units.empty()) {
      auto cur = units.front();
      units.pop();
      int curUnit = cur.first;
      int curJump = cur.second;

      if(stones.count(curUnit + curJump + 1) && !vis[curUnit + curJump + 1].count(curJump + 1)) {
          units.push({curUnit + curJump + 1, curJump + 1});
          vis[curUnit + curJump + 1].insert(curJump + 1);
      }

      if(curJump > 0 && stones.count(curUnit + curJump) && !vis[curUnit + curJump].count(curJump)) {
          units.push({curUnit + curJump, curJump});
          vis[curUnit + curJump].insert(curJump);
      }

      if(curJump > 1 && stones.count(curUnit + curJump - 1) && !vis[curUnit + curJump - 1].count(curJump - 1)) {
          units.push({curUnit + curJump - 1, curJump - 1});
          vis[curUnit + curJump - 1].insert(curJump - 1);
      }
  }

  if(vis[input.back()].size() == 0) return false;
  return true;

}
