"""
187. Repeated DNA Sequences

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]

"""



#substring has to 10 letters long
#there can be more than 1 substring
#if substrinng repeats return that substring

#iterate through string
#every 10th char is a potential substring
#store that substring in a list
# iterate through sublist and see if there any of the same subtring return it
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        sublist = []
        subindex =0
        mystring=""
        index = 0

        #for loop to store strings in respective substring container
        for char in s:
            if(index%10!=0 ):
                mystring+=char
            else:
                mystring+=char   #questionable
                sublist.insert(subindex, mystring )
                subindex+=1
                mystring=""
            index+=1

    #for loop to compare the string 's' to a list of substrings of length 10
        mystring =""
        index=0
        subindex=0
        repeatedS=[]
        rsindex=0
        for char in s:
            if(index%10!=0):
                mystring+=char
            else:
                mystring+=char
                if(mystring == sublist[subindex]):
                    repeatedS.insert(rsindex,mystring)
                    rsindex+=1
                subindex+=1
                mystring=""
            index+=1

        return(list(repeatedS))


#Better solution is to store all substrings into a dictionary and do comparison
