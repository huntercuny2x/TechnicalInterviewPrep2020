class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        //base cases
        //empty string so palindrome size is 0, return empty string
        //string length 1 or string is all unique, so palindrome size is 1, return any char
        
        //if we have a string that isnt all unique we can pick a point or pivot, and check left and right
            //if left or right or both are same as pivot that is our new palindrome
                //we can attempt to build this palindrome up by adding to it by checking left and right again 
        
            //if left and right are same as each other we can call that a palindrome as well and build that the same way
        
        //one big whole in this is if we find a palindrome we are building and returning it, but if a bigger one exists, and the smaller one is found first then we still return the small one and dont even consider the bigger one 
        //so like abagfdddaddd <- if our pivot is picked as 2 then we get aba and thats it
        
    }
};
