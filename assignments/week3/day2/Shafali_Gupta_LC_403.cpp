//i'm not sure how to take into account when you can jump to differnt stones other than the next one.

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int k =1;
        for(int i =0; i<stones.size()-1; i++){
            int a = abs(stones[i] - stones[i+1]);
            cout << a << '\n';
            if(a<= k+1 && a>= k-1 ){
                k = a;
            }
            else{
                cout << "a: " <<a<< '\n';
                return false;
            }

        }
        return true;
    }
};
