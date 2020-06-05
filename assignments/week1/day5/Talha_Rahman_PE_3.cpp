#include <iostream>
#include <cmath>

// my strategy is to use the prime factor tree strategy. 
// I keep dividing the number by the smallest prime numbers
// up until the number itself, eventually if the number 
// can no longer be broken down then num will equal the 
// largest prime factor.
unsigned long largestPrimeFactor(unsigned long num) {
    bool found = false;
    
    while (!found) {
        for(unsigned int i = 2; i < num; ++i) {
            if (num % i == 0) {
                num /= i;
                break;
            } 
            if (i == num - 1) found = true;
        }
    }
    return num;
}

int main() {
    std::cout << largestPrimeFactor(600'851'475'143) << "\n";
    // answer : 6587
}