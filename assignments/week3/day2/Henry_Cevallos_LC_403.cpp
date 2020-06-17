#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;

bool canCross(vector<int> &stones)
{

    unordered_set<int> stonePos;
    for (int stone : stones)
        stonePos.insert(stone); //keep track of all stone positions

    stack<int> positions;
    stack<int> jumps;

    positions.push(0);                          //we start and pos 1
    jumps.push(0);                              //our first jump is -1,0,1
    int last_stone = stones[stones.size() - 1]; //keep track of last stone

    while (!positions.empty()) //while we have places to jump to
    {
        int jump = jumps.top(); //get the jump
        jumps.pop();

        int pos = positions.top(); //get the pos
        positions.pop();

        for (int k = jump - k; k <= jump + 1; k++) //loops through k-1, k, k+1
        {
            if (k <= 0) //or jump cannot be this (first jump case)
                continue;

            int next_pos = pos + k;     //get the positions we can jump to
            if (next_pos == last_stone) //if we reach last stone then true
                return true;

            else if (stonePos.count(next_pos)) //if the pos is a stone then try its jumps
            {                                  
                positions.push(next_pos);      //add the pos to stack
                jumps.push(k);                 //add its jump to stack
            }
        }
    }
    return false; //did not reach final stone
}