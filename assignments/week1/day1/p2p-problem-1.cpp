#include <iostream>
#include <vector>
using namespace std;

/*
a 2d x-y coord 
vector has pts (x,y)
go through each pt and calculte how from one pt to next and how long in total

up- 1 unit
right/diagonal 1 unit

(1,2) (2,2) (4,2)

1,2
2,4
diff = 1,2

*/


int minTimeToVisitAllPoints(vector<vector<int>>& points)
{
    int sum = 0; 

    for(int i = 0; i < points.size()-1; i++)
    {
        int x = abs(points[i+1][0] - points[i][0]);
        int y = abs(points[i+1][1] - points[i][1]);
        sum += max(x,y);
    }
    return sum;
}//O(n)


int main()
{
    vector<vector<int>> points {{1,1},{3,4},{-1,0}};
    cout << minTimeToVisitAllPoints(points);
    return 0;
}

