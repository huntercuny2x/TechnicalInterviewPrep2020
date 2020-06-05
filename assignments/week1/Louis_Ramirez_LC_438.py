"""
438. Find All Anagrams in a String
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.


Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
"""


#better solution works on second test case but have to debug for it to work on all test cases
#would work better if i put ascii value as key and index as value in a dict


class Solution:
    def findAnagrams(self, s: str, p: str):

        pvalue = 0
        psize=len(p)
        for i in range(0,psize):
            pvalue+=ord(p[i])
        print(pvalue)
        #iterates through string to compare pvalue
        List=[]
        comparel=[]
        sSize=len(s)
        sval=0

        i=0
        j=0
        index = 0
        while(i != sSize-1): #iterate through string

            # sval+=ord(s[i])
            # print(sval)

            for k in range(j,psize+i):
                sval+=ord(s[k])


            if(pvalue == sval):
                comparel.insert(index,i)
                index+=1
            sval=0
            i+=1
            j+=1

        return comparel

sol = Solution()

print(sol.findAnagrams("abab","ab"))
print(sol.findAnagrams("cbaebabacd","abc"))
