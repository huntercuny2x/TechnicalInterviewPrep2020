// Fibonacci Number

int fib(int N) {
    if(N<=1) return N;
    
    int fib[N+1];
    fib[0]=0;
    fib[1]=1;
    for(int i = 2; i <= N; i++){ // populate array to store our numbers
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[N];
}
