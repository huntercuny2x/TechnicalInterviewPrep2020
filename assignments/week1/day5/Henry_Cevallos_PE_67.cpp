#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//This function will take the inputted line and split it
//based on spaces and push it into a vector
vector<int> split(string& line)
{
    stringstream in(line);
    vector<int> splitString;
    string wrd;
    while(in >> wrd)    //cycle throught individual words in string
    { 
        splitString.push_back(stoi(wrd));   //push it to vector
    }
    return splitString;
}

//this function will build a matrix equivalent to the triangle file
void buildTriangle(string&file, vector<vector<int>>& tri)
{
    fstream input(file);
    string line; 
    while(getline(input, line))    //loop through triangle 
    {
        vector<int> curr_line = split(line);    //split the line
        tri.push_back(curr_line);   //add it to the matrix
    } 
    input.close();
}

//this function will find the longest path sum of the triangle passed
int getLongestPathSum(string& file)
{
    vector<vector<int> > triangle;
    buildTriangle(file, triangle);  //sets up triangle matrix

    
    for(int i = triangle.size()-2; i >= 0; i--) //we start looking at second to last line and toop to top of triangle
    {
        for(int j = 0; j < triangle[i].size(); j++) // we look at all numbers on line[i]
        {
            int sum = triangle[i][j] + max(triangle[i+1][j], triangle[i+1][j+1]);   //Look at row below and get the max of the two adjacent add it to num in [i][j]
            triangle[i][j] = sum;   //set the sum to the current value
        }
    }
    /* Example:
            2          2         15
           7 0  ->   13 6   ->
          4 6 1 
    */
    return triangle[0][0];  //The first value will contain max sum
}

//used to test
int main(int argc, char **argv)
{
    string filename = argv[1];
    cout << getLongestPathSum(filename) << endl;
}