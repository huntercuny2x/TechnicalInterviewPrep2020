int numSquares(int n) {
    int sums[n+1];
    for(int i = 0; i < n+1; i++)
        sums[i] = n;
    sums[0] = 0;
    sums[1] = 1;
    for (int i = 2; i < n+1; i++){
        for(int j = 1; j*j <= i; j++){
            int num_current = sums[i];
            if((sums[i-j*j]+1) < num_current){
                sums[i] = (sums[i-j*j]+1);
            }
        }
    }
        
    return sums[n];
}
