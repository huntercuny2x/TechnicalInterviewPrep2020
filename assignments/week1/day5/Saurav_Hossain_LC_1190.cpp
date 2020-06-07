class Solution 
{
public:
    string reverseParentheses(string s) 
    {
        //loop thru entire string
            //if we open then push onto stack the index
            //if we close then 
                //store where we close
                //pop stack
                //call reverse from where top was to front 
        
        stack<int> indexOfPara;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                indexOfPara.push(i);
            }
            else if(s[i] == ')')
            {
                int closing = indexOfPara.top();
                indexOfPara.pop();
                reverse(s.begin() + closing + 1, s.begin() + i); //account for missing an index in logic 
            }
        }
        
        //the mutation was made to the string so we just loop thru string and take out all '(' & ')'
        string b = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != '(' && s[i] != ')')
            {
                b = b + s[i];
            }
        }
        return b;
    }
};
