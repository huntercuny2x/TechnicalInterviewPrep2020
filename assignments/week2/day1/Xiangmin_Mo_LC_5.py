# 5. Longest Palindromic Substring
# Brute force is to maybe iterate through the string, letter by letter.
# We keep adding onto the letter and check if it is equal to its reverse
# If it is, then set it to res. We have to compare the length too since it's
# asking for the longest palindromic substring

# Time Complexity O(N^3) since [::-1] is O(N)

def longestPalindrome(s):
  if not s:
    return ""
  
  if len(s) == 1:
    return s
  
  res = ""
  for i in range(len(s)):
    for j in range(i+1, len(s)):
      substring = s[i:j+1]
      # res only gets updated when there is a larger palindrome
      if substring == substring[::-1] and len(substring) > len(res):
        res = substring
  
  # Added this because LeetCode wants you to return the first letter of the string
  # if there are no palindromic substrings.
  if res == "":
    res = s[0]
    
  return res

print(longestPalindrome("babad"))