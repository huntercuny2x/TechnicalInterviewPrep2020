/*
Name: Dewan Sunnah
Date: 6/5/20
Problem: https://projecteuler.net/problem=3
 */

// The Largest Prime factor of 600851475143 is 6857
#include <iostream>
using namespace std;


long divide_num(long n, long num){
    while (n % num == 0)
        n = n / num;
    
    return n;
}


long Largest_Prime_Factor(long n){
    
    long biggest_prime = 2;
    
    n = divide_num(n, 2);
    
    for (long i = 3; n!=1; i+=2){
        if( n % i == 0){
            n = divide_num(n, i);
            biggest_prime = i;
        }
    }
    
    return biggest_prime;
    
}


int main(){
    
    long num;
    cout << "Please enter an int: ";
    cin >> num;
    cout << endl;
    long ans = Largest_Prime_Factor(num);
    cout << "The largest prime factor of " << num << " is " << ans << endl << endl;
    
    return 0;
}
