#include <stack>
#include <string>
#include <iostream>
using namespace std;

string removeKdigits(string num, int k)
{
    if (k == num.length()) //edge gaurd
        return "0";

    stack<char> digits;
    for (int i = 0; i < num.length(); i++) //loop through each digit
    {
        //find if there is a digit smaller than stack top
        for (; k > 0 && !digits.empty() && digits.top() > num[i]; k--)
        {
            digits.pop(); //pop the stack
        }
        digits.push(num[i]); //push the ith digit
    }

    for (; k > 0; k--) //if k is still not 0
    {
        digits.pop(); //pop the rest of the digits
    }

    string ans = "";
    while (!digits.empty()) //used to get answer that is in the stack
    {
        ans = digits.top() + ans; //appends digits to ans
        digits.pop();
    }

    int leading_zero = 0;
    if (ans[0] == '0' && ans.length() > 1) //if there are leading zeros
    {
        while (num[leading_zero] != '0')
        {
            leading_zero++; //count all zeros
        }
        ans.erase(0, leading_zero); //remove all leading zeros
    }

    return ans;
}

int main(int argc, char** argv)
{
    string str = argv[1];
    int k = stoi(argv[2]);
    cout << removeKdigits(str, k) << endl;
}