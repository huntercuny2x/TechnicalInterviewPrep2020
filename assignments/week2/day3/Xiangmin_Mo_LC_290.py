# split str
# a = str[0]
# dict
# b will the next unique word in str
# add the eltters in pattern into dict
# values will be unique
# go through pattern
# get value from dict
# get value from the split string
# compare

def word_pattern(pattern, str):
  split_str = str.split(' ')
  patterns_dict = {}
  
  if len(split_str) != len(pattern):
    return False
  
  for i, k in enumerate(pattern):
    if k not in patterns_dict and split_str[i] not in patterns_dict.values():
      patterns_dict[k] = split_str[i]
  
  for i, k in enumerate(pattern):
    value = patterns_dict.get(k, '')
    if value != split_str[i]:
      return False
  
  return True
  
print(word_pattern('abba', 'dog cat cat dog'))

