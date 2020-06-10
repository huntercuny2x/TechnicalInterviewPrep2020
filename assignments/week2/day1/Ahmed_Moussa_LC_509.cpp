  int fib(int N) {
      if(N < 2) return N;
      int last = 1, beforeLast = 0;
      int counter = 2;
      while(counter < N) {
          int cur = last + beforeLast;
          beforeLast = last;
          last = cur;
          counter ++;
      }
      return (last + beforeLast);
  }
