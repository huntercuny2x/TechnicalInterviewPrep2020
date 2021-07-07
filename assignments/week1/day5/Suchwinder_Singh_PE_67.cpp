#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    vector< unsigned int> test;
    cin >> test[0]; // storing first value
    for (unsigned int row = 1; row < 100; row++) // we start on row one
    {
        std::vector<unsigned int> current;

        // go through all the columns in a row
        for (unsigned int column = 0; column < row+1; column++)
        {
        unsigned int x;
        std::cin >> x;

        // find sum of elements in left row above
        unsigned int leftParent = 0;
        if (column > 0)
            leftParent = test[column - 1];

        // find sum of elements in right row above
        unsigned int rightParent = 0;
        if (column < test.size())
            rightParent = test[column];
        
        unsigned int sum = x + std::max(leftParent, rightParent);
        current.push_back(sum);
        }
        test = current; // updating row
    }

    // find largest sum in final row
    std::cout << *std::max_element(test.begin(), test.end()) << std::endl;
}
