#include <string>
#include <iostream>
using namespace std;
//This will calculate the Nth fibonacci number using dp
int fib(int N) {
    if(N <= 0)
        return 0;
        
    int num1 = 0;
    int num2 = 1;
    int sum;
    for(int i = 2; i <= N; i++)
    {
        sum = num1 + num2;
        num1 = num2;
        num2 = sum;
    }
    return num2;        
}

//used to test
int main(int argc, char **argv)
{
    string n = argv[1];
    int num = stoi(n);
    cout << fib(num) << endl;
}