class Solution {
public:
    int minAddToMakeValid(string S) {
        //we have a stack that holds chars ( & pops off when we see )
        //we have a string NEED 
            //if we see ( push onto stack mark ) into need
            //if we next see that we get ) pop ( off stack and take away ) from need string 
        
        stack<char> holdOpenOnly;
        string need = "";
       
        for(int i = 0; i < S.length(); i++)
        {
            if(S[i] == '(')
            {
                holdOpenOnly.push(S[0]);
                need = need + ')';
            }
            if(S[i] == ')')
            {
                if(!holdOpenOnly.empty())
                {
                    holdOpenOnly.pop();
                    need = need.substr(0, need.length()-1);;
                }
                else
                {
                    need = need + '(';
                }
            }
            
        }
        
        //need should hold what is needed so return siz
        return need.length();
    }
};
