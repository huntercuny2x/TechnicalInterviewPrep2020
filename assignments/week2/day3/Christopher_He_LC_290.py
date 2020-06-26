class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        words = str.split()
        
        if len(words) != len(pattern):
            return False
        
        words_to_char = {}
        chars_to_words = {}
        
        for i, word in enumerate(words):
            char = pattern[i]
            
            if char in chars_to_words and word not in words_to_char:
                return False
            
            if char not in chars_to_words and word in words_to_char:
                return False
            
            if char not in chars_to_words and word not in words_to_char:
                chars_to_words[char] = word
                words_to_char[word] = char
            else:
                if chars_to_words[char] != word or words_to_char[word] != char:
                    return False
        
        return True
