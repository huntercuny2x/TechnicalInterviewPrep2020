//i didn't get how todo this, but i think the way to go is to find the square root of the original number and add the
//square roots of the integers less than that. I just can't seem to figure out how to do that part. 


class Solution {
public:
    int numSquares(int n) {
        double root = sqrt((double)n);
        cout << root << '\n';
        int floor_root = (int)floor(root);
        cout << floor_root<< '\n';
        // return 0;
        for(int i =floor_root; i<=0; i--){
            if(i*i < n){

            }
        }
    }
};
