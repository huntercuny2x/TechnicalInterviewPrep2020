class Solution {
public:
     map<int, int> fibs;
    int fib(int N) {
        if(N <=1){
            return N;
        }
        else{
            fibs[0] = 0;
            fibs[1] = 1;
            return mem(N);
        }
    }
    int mem(int n){
        for(int i =2; i<= n; i++){
            fibs[i] = fibs[i-1] + fibs[i-2];
        }
        return fibs[n];
    }
};
