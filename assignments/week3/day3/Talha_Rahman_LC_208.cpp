#include <vector>
#include <string>
using std::string;

class Trie {
private:
    struct Node {
        bool is_word;
        std::vector<Node*> children;
        Node() : is_word(false), children(26, nullptr) {}
    };
    
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() : root(new Node()){}
    
    ~Trie() { clear(root); }

    void clear(Node* root) {
        for(int i = 0; i < 26; ++i) {
            if (root->children[i])
                clear(root->children[i]);
        }
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = root;
        for(char& c : word) {
            int pos = c - 'a';
            if (cur->children[pos] == nullptr) {
                cur->children[pos] = new Node();
            }   
            cur = cur->children[pos];
        }
        cur->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = root;
        
        for(char& c : word) {
            cur = cur->children[c - 'a'];
            
            if (!cur) return false;
        }
        
        return cur->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur = root;
        
        for(char& c : prefix) {
            cur = cur->children[c - 'a'];
            
            if (!cur) return false;
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */