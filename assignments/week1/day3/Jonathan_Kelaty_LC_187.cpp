class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<size_t, size_t> substrs;
        unordered_map<char, size_t> mapping {
            {'A', 1},
            {'C', 2},
            {'G', 3},
            {'T', 4}
        };
        unordered_map<size_t, char> mapping2 {
            {1, 'A'},
            {2, 'C'},
            {3, 'G'},
            {4, 'T'}
        };
        size_t hash = 0;

        for (size_t i = 0; i < 10; ++i) {
            hash *= 10;
            hash += mapping[s[i]];
        }

        substrs[hash] = 1;

        for (size_t i = 0, j = 10; j < s.size(); ++i, ++j) {
            hash -= mapping[s[i]] * 1'000'000'000;
            hash *= 10;
            hash += mapping[s[j]];
            if (substrs.count(hash)) {
                if (substrs[hash] == 1) {
                    string hash_str = "";
                    size_t hash_cpy = hash;
                    while (hash_cpy > 0) {
                        hash_str.push_back(mapping2[hash_cpy % 10]);
                        hash_cpy /= 10;
                    }
                    reverse(hash_str.begin(), hash_str.end());
                    result.push_back(hash_str);
                }
                substrs[hash]++;
            }
            else {
                substrs[hash] = 1;
            }
        }
        
        return result;
    }
};