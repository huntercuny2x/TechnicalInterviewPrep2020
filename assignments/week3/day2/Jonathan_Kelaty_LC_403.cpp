using State = pair<int, int>;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        for (size_t i = 3; i < stones.size(); ++i) {
            if (stones[i] > stones[i - 1] * 2) {
                return false;
            }
        }
        
        int last_position = stones[stones.size() - 1];
        unordered_set<int> positions;
        for (size_t i = 0; i < stones.size(); ++i) {
            positions.insert(stones[i]);
        }
        
        stack<State> st;
        st.push(make_pair(0, 0));
        
        while ( ! st.empty() ) {
            State s = st.top();
            st.pop();
            
            for (int i = s.second - 1; i <= s.second + 1; ++i) {
                if (i <= 0) {
                    continue;
                }
                
                int next_position = s.first + i;
                if (next_position == last_position) {
                    return true;
                }
                else if (positions.count(next_position)) {
                    st.push(make_pair(next_position, i));
                }
            }
        }
        
        return false;
    }
    
    // Naive solution
    // bool canCross(vector<int>& stones) {
    //     for (size_t i = 3; i < stones.size(); ++i) {
    //         if (stones[i] > stones[i - 1] * 2) {
    //             return false;
    //         }
    //     }

    //     unordered_map<int, size_t> positions;
    //     for (size_t i = 0; i < stones.size(); ++i) {
    //         positions[stones[i]] = i;
    //     }
        
    //     return canCrossHelper(stones, positions, 0, 0);
    // }
    
    // bool canCrossHelper(vector<int>& stones, unordered_map<int, size_t>& positions, size_t pos, int k) {
    //     if (pos == stones.size() - 1) {
    //         return true;
    //     }
        
    //     int check = stones[pos] + k - 1;
    //     for (size_t i = 3; i > 0; --i) {
    //         if ((check - stones[pos]) > 0 && positions.count(check)) {
    //             if (canCrossHelper(stones, positions, positions[check], check - stones[pos])) {
    //                 return true;
    //             }
    //         }
    //         ++check;
    //     }
        
    //     return false;
    // }
};