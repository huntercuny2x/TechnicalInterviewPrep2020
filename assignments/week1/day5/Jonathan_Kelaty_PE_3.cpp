// ans: 6857

#include <iostream>
#include <vector>

using namespace std;

size_t num1 = 600'851'475'143;
size_t num2 = 13'195;

vector<size_t> primes;

bool isPrime(size_t n) {
    for (size_t prime : primes) {
        if (n >= prime) {
            break;
        }
        if (n % prime == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    size_t num = num1;
    size_t max = 1;

    for (size_t i = 2; i <= num; ++i) {
        if (isPrime(i)) {
            primes.push_back(i);
            while (num % i == 0) {
                num /= i;
                max = i;
            }
        }
    }

    cout << max << endl;

    return 0;
}
