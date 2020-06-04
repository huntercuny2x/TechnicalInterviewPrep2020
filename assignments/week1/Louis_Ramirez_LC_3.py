"""
3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
"""

#iterate through string
#if char a != b : counter++


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        counter=0
        index=0
        numlist=[]
        numlisti=0
        holder =""
        listofsub=[]
        for char in s:
            if(index!=0):
                if char!=holder:
                    counter+=1
                    numlist.insert(numlisti,counter)
                    numlisti+=1
                    holder = char
                # else:
                #     counter = 0
            else:
                holder = char
            index+=1

        highestnum=0
        for num in numlist:
            if(num>highestnum):
                highestnum=num

        if highestnum==0:
            return 1
        else:
            return int(highestnum/2)

#There is a better solution thats works. it involves placing characters in hashtable
# class Solution:
#     def lengthOfLongestSubstring(self, s: str) -> int:
