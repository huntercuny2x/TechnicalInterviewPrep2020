int reverse(int x) {
    int ans = 0;
    while (x != 0){
        
        if (ans < INT_MIN/10 || ans > INT_MAX/10)
            return 0;   //added an overlow check
        
        ans = ans * 10 + (x % 10);
        x = x/10;
    }
    
return ans;
}
