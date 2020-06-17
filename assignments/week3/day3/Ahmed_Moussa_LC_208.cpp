class Trie {
private:
    void myInsert(string & word, int ind) {
        if(ind == word.size()) leaf = true;
        else {
            if(ch[word[ind] - 'a'] == nullptr)
                ch[word[ind] - 'a'] = new Trie();
            ch[word[ind] - 'a']->myInsert(word, ind+1);
        }
    }
    
    bool mySearch(string & word, int ind) {
        if (ind == word.size()) return leaf;
        if (ch[word[ind] - 'a'] == nullptr) return false;
        return ch[word[ind] - 'a']->mySearch(word, ind+1);
    }
    
    bool myStartWith(string & word, int ind) {
        if (ind == word.size()) return true;
        if (ch[word[ind] - 'a'] == nullptr) return false;
        return ch[word[ind] - 'a']->myStartWith(word, ind+1);
    }
    
public:
    /** Initialize your data structure here. */
    vector<Trie*> ch;
    bool leaf;
    
    Trie() {
        leaf = false;
        ch.resize(26);
        for(int i=0; i<26; i++) ch[i] = nullptr;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        myInsert(word, 0);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return mySearch(word, 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return myStartWith(prefix, 0);
    }
    
};
