struct TrieNode {
    unordered_map<char, TrieNode*> branches;
    bool is_word = false;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : head{new TrieNode()} {
        /* intentionally empty */
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = head;
        
        for (char c : word) {
            if ( ! curr->branches.count(c) ) {
                curr->branches[c] = new TrieNode();
            }
            curr = curr->branches[c];
        }
        
        curr->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = getNode(word);
        return node ? node->is_word : false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return getNode(prefix);
    }
    
private:
    TrieNode* head;
    
    TrieNode* getNode(string word) {
        TrieNode* curr = head;
        
        for (char c : word) {
            if (curr->branches.count(c)) {
                curr = curr->branches[c];
            }
            else {
                return nullptr;
            }
        }
        
        return curr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */