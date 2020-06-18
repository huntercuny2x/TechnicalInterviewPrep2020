def canVisitAllRooms(rooms):
  # numbers inside represents the keys to the rooms
  # rooms[0] has keys to rooms[1] and rooms[3], so we can access room 1 and 3
  # rooms[1] has keys to rooms[3], rooms[0], and rooms[1]
  # rooms[2] cant be accessed so we return false
  
  # 0 is always unlocked
  seen = {0}

  stack = [0]
  
  while stack:
    key = stack.pop()
    for i in rooms[key]:
      if i not in seen:
        seen.add(i)
        stack.append(i)

        if len(seen) == len(rooms):
          return True
  
  return len(seen) == len(rooms)

print(canVisitAllRooms([[1],[2],[3],[]]))