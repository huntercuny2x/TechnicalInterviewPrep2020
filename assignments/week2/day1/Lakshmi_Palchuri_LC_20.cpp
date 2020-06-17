bool isValid(string s) 
{
    stack<char> paren;
    for (int i = 0; i < s.length(); i++) 
    {
        if (s[i] == '(') 
        {
            paren.push(')');
        } 
        else if (s[i] == '[') 
        {
            paren.push(']');
        } 
        else if (s[i] == '{') 
        {
            paren.push('}');
        } 
        else 
        {
            if (paren.empty() || paren.top() != s[i]) 
            {
                return false;
            }
            paren.pop();
        }
    }
    if (paren.empty())
    {
        return true;
    }
    return false;
}