bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (matrix.size() == 0) // no possible number
        return false;

    int row = 0;
    int col = matrix[0].size() - 1; //start at last pos in first row

    while (row < matrix.size() && col >= 0) //while we are in bounds
    {
        if (matrix[row][col] == target) //target found
            return true;

        if (matrix[row][col] < target) //less than so move up a row
            row++;

        else
            col--; //greater than so we move down the col
    }

    return false; //not found
}