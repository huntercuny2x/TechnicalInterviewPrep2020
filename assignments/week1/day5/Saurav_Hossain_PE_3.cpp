std::vector<long> primeFactor(long number, std::vector<long> result)
{
  if(number == 1)
    return result;
  if(number % 2 == 0)
  {
    result.push_back(2);
    return primeFactor(number/2, result);
  }
  else
  { 
    int i = 3;
    if(!result.empty())
    {
      i = result.back();
    }

    while(i <= (long)sqrt(number))
    {
      if(number % i == 0)
      {
        result.push_back(i);
        return primeFactor(number/i, result);
      }
      i = i + 2;
    }
    result.push_back(number);
    return result;
  }
}

long findLargestPrimeFactor(long num)
{
  std::vector<long> willHoldAllPrimeFactors;
  willHoldAllPrimeFactors = primeFactor(num, willHoldAllPrimeFactors);
  if(willHoldAllPrimeFactors.size() < 1)
    return -1;
  else
    return willHoldAllPrimeFactors.back();
}
