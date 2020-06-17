class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> access;
        stack<int> st;
        
        access.insert(0);
        st.push(0);
        
        while ( ! st.empty() ) {
            int room = st.top();
            st.pop();
            
            for (int n : rooms[room]) {
                if (!access.count(n)) {
                    access.insert(n);
                    st.push(n);
                }
            }
        }
        
        return access.size() == rooms.size();
    }
};