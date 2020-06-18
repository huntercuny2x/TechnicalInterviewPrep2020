 bool canVisitAllRooms(vector<vector<int>>& rooms) 
{
    if(rooms.empty())
    {
        return true;
    }

    unordered_set<int> rooms_visited;
    
    queue<int> have_to_visit;
    
    have_to_visit.push(0);
    
    while(!have_to_visit.empty())
    {
        int current = have_to_visit.front();
        have_to_visit.pop();
        
        if(rooms_visited.find(current) == rooms_visited.end())
        {
            rooms_visited.insert(current);
        }
        
        for(const auto k : rooms[current])
        {
            if(rooms_visited.find(k) == rooms_visited.end())
            {
                have_to_visit.push(k);
            }
        }
    }
    
    if (rooms_visited.size() == rooms.size()) 
    {
        return true;
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    if(matrix.size() == 0)
    {
        return false;
    }
    
    int i = 0;
    int j = matrix[0].size()-1;

    while(j >= 0 && i <= matrix.size()-1)
    {
        if(target == matrix[i][j])
        {
                return true;
        }
        else if(target > matrix[i][j])
        {
            i++;
        }
        else if (target < matrix[i][j])
        {
            j--;
        }
    }
    return false;    
}