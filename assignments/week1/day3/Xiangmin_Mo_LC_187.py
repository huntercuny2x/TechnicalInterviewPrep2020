def findRepeatedDnaSequences(s):
  anagram_dictionary = {}
  output = []
  
  for i in range(0, len(s)-9):
      sequence = s[i:i+10]
      
      # dictionary get function, default value here is 0 (int) and you increment if the sequence is already
      # in the dict
      anagram_dictionary[sequence] = anagram_dictionary.get(sequence, 0) + 1
      
  for i in anagram_dictionary:
      if anagram_dictionary[i] > 1:
          output.append(i)
          
  return output

print(findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"))