bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    vector<bool> seen_rooms(rooms.size(), false);
    seen_rooms[0] = true;

    stack<int> keys;
    keys.push(0); //first key is to first room

    while (!keys.empty())
    {
        int room = keys.top(); //get the room we can access
        keys.pop();
        for (int key : rooms[room]) //look at all the keys in that room
        {
            if (!seen_rooms[key]) //if we have not seen that room
            {
                seen_rooms[key] = true; //set to true
                keys.push(key);         //push key to stack to look at later
            }
        }
    }

    for (bool room : seen_rooms)
    {
        if (room == false) //there is an unvisitied room
            return false;
    }

    return true;
}