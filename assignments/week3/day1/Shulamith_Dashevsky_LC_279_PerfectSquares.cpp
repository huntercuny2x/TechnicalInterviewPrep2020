class Solution {
public:
    int numSquares(int n) {
        //unordered_set<int> perfSquares;
        vector<int> perfSquares;
        int counter;
        int sum = 0;
        int max_sqr_rt = n/2; //or sqrt(n)
        for(int i=1; i<max_sqr_rt; i++){
            if(i*i <=n){
                perfSquares.pushback(i*i);
            }
            //add all perfect squares less than or equal to n to hashSet
        }
        //go through each perfect square and add?
        //do n - the largest perfect square, if the square is in the
        //got through list of perfect squares if
       for(int i=perfSquares.size()-1; i>=0; i--){
            sum = n - perfSquare[i];
            while(sum!=n){
               for(int j=i; j>=0; j--){

               }
           }
       }
    }
};
