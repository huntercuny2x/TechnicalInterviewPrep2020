class Trie:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.container = set()
        self.prefixes = set()

    def insert(self, word):
        """
        Inserts a word into the trie.
        """
        self.container.add(word)
        
        for i in range(len(word)):
          self.prefixes.add(word[:i+1])

    def search(self, word):
        """
        Returns if the word is in the trie.
        """
        if word in self.container:
          return True
        else:
          return False

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        if prefix in self.prefixes:
          return True
        else:
          return False


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)