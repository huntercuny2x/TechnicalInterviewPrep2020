#include <iostream>
bool isPrime(long num){
  if(num <=1){
    return false;
  }
  for(int i =2; i< num; i++){
    if(num%i ==0){
      return false;
    }
  }
  return true;
}
long largestPrimeHelper(long num){
  int ret = 1;
  int temp = 2;
  while(temp <=num){
    // std::cout << temp  << " "<< num%temp<< '\n';
    if(num%temp ==0 ){
      // std::cout << "IF " << temp << '\n';
      if(isPrime(temp) && temp > ret){
        // std::cout << "PRIME " << temp<< '\n';
        ret = temp;
        num = num/temp;
        // std::cout << ret << '\n';
      }
    }
    temp++;
  }
  return ret;
}
long largestPrimeFactor(long num){
  if(num %2 ==0){
    int temp = 2;
    int ret = largestPrimeHelper(num/2);
    if(ret>temp){
      return ret;
    }
    else{
      return temp;
    }
  }
  else{
    return largestPrimeHelper(num);
  }

}

int main(){
  std::cout << isPrime(3) << '\n';
  std::cout << largestPrimeFactor(12) << '\n';
  std::cout <<largestPrimeFactor(13195) << '\n';
  std::cout << largestPrimeFactor(600851475143) << '\n'; //6857
}
