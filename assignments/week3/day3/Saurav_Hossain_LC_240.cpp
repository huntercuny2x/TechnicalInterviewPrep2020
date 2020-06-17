class Solution {
public:
   bool binarySearch(vector<int> looking, int left, int right, int target) 
   {
       if (right >= left) 
       { 
           int middle = left + (right - left) / 2; 
           
           if (looking[middle] == target)
           {
               return true; 
           }
           if (looking[middle] > target) 
           {
               return binarySearch(looking, left, middle - 1, target);
           } 
           else
           {
               return binarySearch(looking, middle + 1, right, target);
           }
       } 
       return false; 
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        //can do brute force of searching thru entire thing 
        
        //better way
            //binary search on the inside vectors since its sorted
            //only search up to the vector that starts with less than or equal to target
            //only search from vector that ends with less than or equal to target 
        
        //first check the target agaisnt first elements and determine which part we need to search up to, store val
        //check the target against last elements and determine which parts we need to start search from, store val
        //this narrows search range
        
        //next between the narrowed range of vectors we will call binary search on each vector
            //if we find target break out and return true
            //if we dont find target return false
        if(matrix.size() == 0)
        {
            return false;
        }
        
        int searchStart = 0; //start searching from 0 vector by default 
        
        //go thru vector and try to narrow range
        for(int i = 0; i < matrix.size(); i++)
        {
            //we start search at next index cause this i will be the last vector that doesnt have our target
            if(matrix[i][matrix[i].size() - 1] < target)
            {
                searchStart = i + 1;
            }
            
        }
        
        //no need to cut off end cause if worse case scenario and we approaching end area we were gonna have to go therre anyways
        for(int i = searchStart; i < matrix.size(); i++)
        {
            if(binarySearch(matrix[i], 0, matrix[i].size()-1, target))
            {
                return true;
            }
        }
        return false;
    }
};
