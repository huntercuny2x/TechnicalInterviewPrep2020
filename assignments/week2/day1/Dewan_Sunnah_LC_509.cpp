int fib(int N) {
    
    int ans = 0;
    
    if (N == 0)
        return 0;
    
    if (N == 1)
        return 1;
    
    int  before_last= 0;
    int  last = 1;
    
    for (int i = 2; i <= N; i++){
        ans = last + before_last;
        before_last = last;
        last = ans;
        
    }
    
    return ans;
    
    
    
}

int main(){
    return 0;
    
}
