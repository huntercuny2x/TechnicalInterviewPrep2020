// ans: 7273

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream file("triangle.txt");
    vector<vector<size_t>> triangle;
    triangle.reserve(100);

    for (size_t i = 1; i <= 100; ++i) {
        triangle[i - 1].reserve(i);
        for (size_t j = 0; j < i; ++j) {
            file >> triangle[i - 1][j];
        }
    }

    file.close();

    for (int i = 98; i >= 0; --i) {
        for (size_t j = 0; j < i + 1; ++j) {
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }

    cout << triangle[0][0] << endl;

    return 0;
}
