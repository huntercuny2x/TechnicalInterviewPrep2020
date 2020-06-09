#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using std::string;

int maxPathSum(std::string path) {
    std::fstream infile(path);
    if (infile.bad()) {
        std::cerr << "File can't be opened\n";
        exit(1);
    }
    
    // matrix of size 100 because we already know the number of rows in the file
    std::vector<std::vector<int>> matrix(100);
    string line;
    
    // this fills up the matrix to represent the triangle from file
    // this matrix will be our tabulation table for dynamic programming
    int row = 0;
    while (getline(infile, line)) {
        std::vector<int> row_vec(row + 1);
        std::stringstream ss(line);
        string str_value;
        
        int col = 0;
        while(ss >> str_value) {
            row_vec[col] = stoi(str_value);
            ++col;
        }
        matrix[row] = row_vec;
        ++row;
    }

    /**
     * This is a bottom-up approach, where we start at the 2nd to last row in the matrix
     * and then go through each column then increase this position by the larger of the 
     * two values that can be picked below it (which are either at the same column or 1 column ahead)
     * This approach will work all the way up and at matrix[0][0] will be the largest possible value
     */ 
    for(row = matrix.size() - 2; row >= 0; --row) {
        for(int col = 0; col <= row; ++col) {
            matrix[row][col] += std::max(matrix[row + 1][col], matrix[row + 1][col + 1]);
        }
    }
  
    return matrix[0][0];
}

int main() {
    std::string path("triangle.txt");
    // Answer: 7273
    
    std::cout << maxPathSum(path) << "\n";
}