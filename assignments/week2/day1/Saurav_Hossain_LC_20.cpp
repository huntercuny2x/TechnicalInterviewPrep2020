class Solution {
public:
    bool isValid(string s) 
    {
        //cover some edge cases
        if(s.length() % 2 != 0)
        {
            return false;
        }
        
        if(s[0] == ')' || s[0] == '}' || s[0] == ']')
        {
            return false;
        }
        
        //go thru string
            //as long as its not a close add it to stack
            //if its a close check with top of stack if its a right one, if not then return false
       stack<char> opens;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                opens.push(s[i]);
            }
            if(s[i] == ')')
            {
                //if not right top false if right top pop
                if(opens.top() == '(')
                {
                    opens.pop();
                }
                else
                {
                    return false;
                }
            }
            if(s[i] == '}')
            {
                //if not right top false
                if(opens.top() == '{')
                {
                    opens.pop();
                }
                else
                {
                    return false;
                }
            }
            if(s[i] == ']')
            {
                //if not right top false
                if(opens.top() == '[')
                {
                    opens.pop();
                }
                else
                {
                    return false;
                }
            }
    
        }
        
        if(!opens.empty())
        {
            return false;
        }
        
        return true;
    }
};
