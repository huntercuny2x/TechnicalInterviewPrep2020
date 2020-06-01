int strStr(string haystack, string needle) {
    
    if(needle.length() == 0)
        return 0;
    
    int index = 0;
    int stop = haystack.length() - needle.length();
    while(index <= stop){
        
        if(haystack.substr(index, needle.length()) == needle)
            return index;
        
        index++;
    }
    
    return -1;
}
    
