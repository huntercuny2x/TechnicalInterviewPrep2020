class Solution 
{
public:
    int fibn(int given, int sumasgo)
    {
        if(given == 0)
            return 0;
        if(given == 1)
            return 1;
        else
            return fibn(given - 1, sumasgo) + fibn(given - 2, sumasgo);
    }
    
    int fib(int N) 
    {
        //intial idea is recursion just do 
        //base case if n = 0 return 
        //else call n - 1
        return fibn(N, 0);
        
    }
    
    
};
