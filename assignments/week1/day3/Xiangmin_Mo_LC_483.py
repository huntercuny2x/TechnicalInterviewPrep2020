def findAnagrams(s, p):
  # Couldn't finish within an hour, spent too long thinking and drawing it out
  # Doesn't work (yet?)
  # Comments on my thought process are below

  dictP = {}
  dictS = {}
  
  # stores the letters of string p
  for i in p:
      if dictP.get(i) != None:
          dictP[i] += 1
      else:
          dictP[i] = 1
  
  # stores the letters of string s
  for i in s[:len(p)]:
      if dictS.get(i) != None:
          dictS[i] += 1
      else:
          dictS[i] = 1
  
  # Check to see if the substring from s[0 to the length of p] is an anagram
  # Also make sure to keep incrementing it until you reach the size of s
  # It should be (length of p) <= (length of s)
  start = 0
  end = len(p)
  output = []

  while end <= len(s):
    # If we see the letter of the current index of string s, we should decrement
    # and if it's 0 we should remove the key from the dict?
    # and I think check to see if the two dicts are equal to each other
    # If we do that, we should know that the current index is an anagram
    # We also need to add the next letter into the dictionary too:
    # dictS[s[end_window]] = dictS.get(s[end_window], 0) + 1
    # This should(?) be fine because I am setting the default value to 0 if the
    # key does not exist in the dict.

    start += 1
    end += 1
  
  return output

print(findAnagrams("cbaebabacd", "abc"))