// Return if the value is less than 2
// a & b will represent starting values of fib sequence
// and will be used to calculate c. Then we update a and b 
int fib(int N) {
    if (N < 2) return N;
    
    unsigned int a = 0, b = 1, c;
    for(unsigned int i = 1; i < N; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}