
#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimeNumbers(int MAX) {
    vector<int> primes;
    vector<bool> notPrime(MAX);
    primes.push_back(2);
    for(int i=3; i<MAX; i+=2) {
        if(notPrime[i]) continue;
        primes.push_back(i);
        long long j = (long long) i * i;
        for(; j<MAX; j+=i) {
            notPrime[j] = true;
        }
    }
    return primes;
}

vector<long long> getPrimeFactors(long long x, vector<int> & primes) {
    vector<long long> primefactors;
    if (x == 0 || x == 1) return primefactors;
    for(int p: primes) {
        if(x%p) continue;
        primefactors.push_back(p);
        while (x%p == 0) x/=p;
    }
    if (x > 1) primefactors.push_back(x);
    return primefactors;
}


int main() {
    ios_base::sync_with_stdio(false);
    long long num = 600851475143;
    int MAX = 1000001;
    vector<int> primes = getPrimeNumbers(MAX);
    vector<long long> primefactors = getPrimeFactors(num, primes);
    for(auto x: primefactors) cout << x << " ";
    return 0;
}


//Answer:  6857
