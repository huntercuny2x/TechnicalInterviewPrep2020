class Trie 
{
private:
    //my underlying data structure for this class since we need to search and insert quickly is gonna be unordered set
    unordered_set<string> elements;
    
public:
    /** Initialize your data structure here. */
    Trie() 
    {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        elements.insert(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        if(elements.count(word) > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        //this method is gonna be confusing for me cause i cant just check the first part of an element
        //what i can try to do is traverse the entire set and do a .find on each element
        
        for(const string & str : elements)
        {
            if(str.find(prefix) != string::npos)
            {
                return true;
            }
        }
        
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
