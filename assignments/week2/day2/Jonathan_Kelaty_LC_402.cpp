class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        result.reserve(num.size() - k);
        unordered_set<size_t> del;
        
        for (size_t i = 0; i < k; ++i) {
            size_t index = 0;
            for (size_t j = 0; j < num.size(); ++j) {
                if (del.count(j)) {
                    continue;
                }
                else if ( ! del.count(index) && num[j] < num[index]) {
                    break;
                }
                index = j;
            }
            del.insert(index);
        }
        
        bool zero = false;
        
        for (size_t i = 0; i < num.size(); ++i) {
            if ( ! del.count(i) ) {
                if (num[i] - '0') {
                    zero = true;
                }
                if (zero) {
                    result.push_back(num[i]);
                }
            }
        }
        
        if (result == "") {
            result = "0";
        }
        
        return result;
    }
};