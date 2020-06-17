class TrieNode
{
public:
    TrieNode();
    unordered_map<char, TrieNode *> links;
    bool isWord = false;
};

class Trie
{
public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (!node->links.count(ch))
            {
                node->links[ch] = new TrieNode;
            }
            node = node->links[ch];
        }
        node->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (node->links.count(ch))
                node = node->links[ch];

            else
                node = nullptr;
        }

        return node != nullptr && node->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (char ch : prefix)
        {
            if (node->links.count(ch))
                node = node->links[ch];

            else
                node = nullptr;
        }
        return node != nullptr;
    }

private:
    TrieNode *root;
};
