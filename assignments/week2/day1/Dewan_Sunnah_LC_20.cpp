#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
        
        if (s == "")
            return true;
        
        stack<char> container;
        
        container.push(s[0]);
        
        for(int i = 1; i < (int)s.length(); i++){
            
            if(container.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}'))
               return false;
            
            else if(s[i] ==')'){
                if(container.top() != '(')
                    return false;
                container.pop();
            }
               
            else if(s[i] ==']'){
                if(container.top() != '[')
                    return false;
                container.pop();
            }
            
            else if(s[i] =='}'){
                if(container.top() != '{')
                    return false;
                container.pop();
            }
            
            else
                container.push(s[i]);
            
        }
        
        return container.empty();
        
    }

int main(){
    return 0;
}
