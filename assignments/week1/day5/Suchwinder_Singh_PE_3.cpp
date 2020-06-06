#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

/*
I implemented this with the idea that I only need to go up to the sqrt of 
the number to find 1 number in a pair that is a factor of n
e.g: if n = 15 the factors are 1,3,5,15. All we need to do is check 1,3 since
15/1 = 15 and 15/3 = 5. Thus we only need the lower half of the sqrt(15), which is
approx 3.9 which becomes 3 since we are working with int types.
*/
bool isprime(int &n){ 
    if(n==2 || n ==3) return true;
    int sqr = sqrt(n);
    for( int i = 2; i <= sqr; i++ ) {
        if( n % i == 0 ) return false;}
    return true;
}

int main() {
    int number = sqrt(600851475143); // only need to go up until sqrt of number to find all pairs
    // for the scope of this problem I think we only needed to go till the sqrt of the number
    // and check the number we are at and value/number (to see if the other pair is prime as well)
    // the reason is cause we want to check all pairs of the numbers
    // e.g. for 15 we want to see if 1,3,5,15 if any of them is prime
    // For this loop below though I only check the number and not value/number
    // so I think this shouldnt be allowed but it works for the scope of the
    // current problem
    long value = 600851475143;
    int max = 0;
    for(number; number>=2; number--){ // start from sqrt value and then calculate, 
    //we begin at larger number to find the largest faster, in reality if properly implemented above
    // we could start from beginning = 2 or at number.
        if(isprime(number)){
            if(value%number==0){
                max = number;
                break;
            }
        }        
    }
    cout << max << endl;
}

// Time Complexity = O(sqrt(n)*sqrt(m)) = n is all numbers we go through, and m is number we checking if prime, so finding all divisible numbers
// Space Complexity = O(1)

// Can get a time complexity of O(nlog log(n)) by https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// not sure if this is worth implementing. as space is O(n) as well