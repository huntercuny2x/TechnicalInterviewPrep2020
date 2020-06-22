class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:

        def dfs(pos, seen):
            if pos in seen:
                return

            seen.add(pos)

            room = rooms[pos]
            for key in room:
                dfs(key, seen)

        seen = set()
        dfs(0, seen)
        return len(seen) == len(rooms)
