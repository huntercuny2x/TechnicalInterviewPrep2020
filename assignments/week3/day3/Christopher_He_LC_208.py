class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.fullwords = set()
        self.prefixes = set()



    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        self.fullwords.add(word)
        for i in range(len(word)):
            self.prefixes.add(word[:i+1])


    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        return word in self.fullwords


    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        return prefix in self.prefixes



# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
