class Solution 
{
public:
    
    bool isInt(double non)
    {
        if(non - (int)non == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int numSquares(int n) 
    {
        //starting at n check if n is perf return 1
        //check if n-1 is perf 
        if(isInt(sqrt(n)))
        {
            return 1;
        }
        
        int counter = 0;
        int numLeft = n;
        int bigSq = n;
        while(numLeft > 3)
        {
            //if the bigSq is a sq then subtract from numLeft & increment counter
            if(isInt(sqrt(bigSq)))
            {
                numLeft = numLeft - bigSq;
                counter++;
                bigSq = numLeft;
            }
            
            //if its not a sq then lower it by 1 
            if(!isInt(sqrt(bigSq)))
            {
                bigSq--;
            }    
        }
         //if numLeft is 1,2,3 then we just add that amount of 1s so increment counter by that amount
        counter = counter + numLeft;
        
        return counter; 
    }
    //i kinda understood this wrong, i did find largest perf sq and then tag left overs so: 12 gives me 9 + 1 + 1 + 1 not 4 + 4 + 4, so i miss a chunk of test cases
};
