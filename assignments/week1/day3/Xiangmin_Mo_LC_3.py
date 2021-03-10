def lengthOfLongestSubstring(s):
  start = 0
  max_length = 0
  letters = {}
  
  for i in range(len(s)):
      # second part of the condition ensures that the start will not change if
      # the index of the repeating letter is lower than the start value
      # which means, it is not repeated yet in the current substring.
      if s[i] in letters and start <= letters[s[i]]:
          start = letters[s[i]] + 1
      else:
          # add one because we're finding length
          max_length = max(max_length, i - start + 1)
      
      letters[s[i]] = i
      
  return max_length

print(lengthOfLongestSubstring("abcabcbb"))
print(lengthOfLongestSubstring("tmmzuxt"))