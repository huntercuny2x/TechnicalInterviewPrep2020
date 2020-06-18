#include <iostream>
using namespace std;

/*______________________________________________________________________________
Project Euler Problem 3:

The prime factors of 13195 are 5, 7, 13 and 29. What is the largest 
prime factor of the number 600851475143
________________________________________________________________________________
*/

int LargestPrimeFactor(long long n)
{
    long long largest = 1;   
    for(long long i = 2; i <= n; i++)  //going through all numbers up to n
    {
        if(n % i == 0)                 //if n is divisible by i
        {
            n = n/i;                   //divide it by i
            if( i > largest)           //if its larger than value in largest var
            {
               largest = i;            //set largest to i
            }                          //keeps replacing until comes across largest prime factor
        }
    }
    return largest; 
}


int main()
{
    cout << LargestPrimeFactor(600851475143) << endl;   //returns 6857 <-- ans
    return 0;
}