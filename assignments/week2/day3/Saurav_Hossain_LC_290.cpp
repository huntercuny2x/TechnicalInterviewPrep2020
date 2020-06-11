class Solution 
{
    public boolean wordPattern(String pattern, String str) 
    {
        //i have a feeling im forced to use hash   
        //i can start with edge cases
        
        //i can make hash easier with split so lets do in java
        String [] strWords = str.split(" ");
        
        if(str.length() < 1 || pattern.length() < 1 || pattern.length() != strWords.length)
        {
            return false;
        }
        
        //declare hashmaps in java
        //im unsure how to make the key of word in str to a char from pattern so ill do double map kinda sorta
        HashMap<Character, String> check = new HashMap<Character, String>();
	    HashMap<String, Character> checkAgainst = new HashMap<String, Character>();
        
        //iterate thru pattern first
        for(int i = 0; i < pattern.length(); i++)
        {
            //if wasnt in map then we put it in 
            if(check.get(pattern.charAt(i)) == null)
            {
                check.put(pattern.charAt(i), strWords[i]);
            }
		    //if we can find it and its not what we matched and put it to return false
			if(!check.get(pattern.charAt(i)).equals(strWords[i]))
            {
                return false;
            }
        }
        
        //iteratre thru strWords
        for(int i = 0; i < strWords.length; i++)
        {
            if (checkAgainst.get(strWords[i]) == null)
            {
                checkAgainst.put(strWords[i], pattern.charAt(i));
            }
            if (!checkAgainst.get(strWords[i]).equals(pattern.charAt(i)))
            {
                return false;
            }
        }
        
        //if we made it thru all return true
        return true;
    }
}
