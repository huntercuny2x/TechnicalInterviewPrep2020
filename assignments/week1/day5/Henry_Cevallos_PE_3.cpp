#include <iostream>
#include <cmath>
using namespace std;

//checks if number passed is prime
//will return bool value if prime or not
bool isPrime(int n) 
{
    for(int i = 2; i < sqrt(n); i++)
    {
        if(n % i == 0)  //divisible by another number so not prime
            return false;
    }
    return true;
}

//returns the greatest prime factor
//My approach is to start searching from the greatest possible numbers to avoid looking at smaller prime factors
//The worst case is that the prime factor is 1 or 2 since we cycle through sqrt(n) numbers
//A bottleneck in my program that I could improve on is checking if a number is prime or not 
int greatestPrimeFactor(long n)
{
    if(n == 1 || n == 2)    //account for the smallest prime numbers
        return n;

    long cut_off = sqrt(n); //the greatest prime factor can only be as big as n's sqrt

    if(cut_off % 2 != 0)    //if the cut_off is odd
    {
        for(long i = cut_off; i > 3; i-= 2)  //cycle through odds, starting at largest possible number
        {
            if(n % i == 0 && isPrime(i))    //check if it is a prime factor
                return i;   //return prime factor
        }
    }
    else    //the cut_off is even
    {
       for(long i = cut_off-1; i > 3; i-= 2)    //make loop to cycle through odds
        {
            if(n % i == 0 && isPrime(i))    //check if it is a prime factor   
                return i;   //return prime factor
        }
    }
    //if there was no prime factor found then that means its either 1 or 2
    if(n % 2 == 0)  //if even
        return 2;
    else return 1;  //last possible case
    
}

//used to test
int main(int argc, char **argv)
{
    long num = stol(argv[1]);
    
    cout << greatestPrimeFactor(num) << endl;
}