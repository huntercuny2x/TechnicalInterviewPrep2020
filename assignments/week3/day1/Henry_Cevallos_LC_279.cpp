int numSquares(int n)
{
    if (n == 0)
        return 0;

    vector<int> count_squares(n + 1, 0); //set up vector with 0's

    for (int i = 0; i <= n; ++i) //loop through all numbers  0 to n
    {
        count_squares[i] = i;              //set the val at that index to its index
        for (int j = 2; j <= sqrt(i); ++j) //loop though  perfect squares up to sqrt(i)
        {
            count_squares[i] = min(count_squares[i], count_squares[i - (j * j)] + 1); //get min
        }                                                                             //look at the val at perfect square - position
    }

    return count_squares[n]; //the nth position will have the number of additions
}