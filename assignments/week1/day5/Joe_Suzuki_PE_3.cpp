#include <bits/stdc++.h>
using namespace std;

int largest_pf(unsigned long long num){
	unsigned long long i = 2, large = 1;
	for(i = 2; num != 1; ++i){
		while(num % i == 0){
			num /= i;
			large = i;
		}
	}
	return large;
}

int main(int argc, char **argv){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	unsigned long long num = 600851475143;	
	printf("The prime factor of %lld: %i\n", num, largest_pf(num));
	
	return 0;
}

