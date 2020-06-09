class Solution {
public:
    int fib(int N) {
        if(N <= 1) return N;
        if(N == 2) return 1;
        
        int a = 1, b = 1, sum = 0;
        for(int i = 3; i <= N; ++i){
            sum = a + b;
            a = b;
            b = sum;
        }
        
        return sum;
    }
};
