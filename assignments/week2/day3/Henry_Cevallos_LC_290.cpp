class Solution
{
public:
    //This function will take the inputted line and split itr up depending on
    //the delimeter. It will take every string in between the delimeters and put them into
    //a vector
    vector<string> split(string line, char delimeter)
    {
        int start = 0, searchFrom = 0;
        vector<string> splitString;
        while (searchFrom != -1)
        {
            searchFrom = line.find(delimeter, start);
            string token = line.substr(start, (searchFrom - start));
            if (token == "")
                continue;
            splitString.push_back(token);
            start = searchFrom + 1;
        }
        return splitString;
    }
    bool wordPattern(string pattern, string str)
    {

        vector<string> line = split(str, ' '); //splits string into vector
        if (pattern.length() != line.size())   //if they do not match size then false
            return false;

        unordered_map<char, string> map_to_str;
        unordered_map<string, char> map_to_char;

        for (int i = 0; i < pattern.length(); i++) //loop through pattern
        {
            if (!map_to_str.count(pattern[i]) && !map_to_char.count(line[i])) //if unique  item
            {
                map_to_str[pattern[i]] = line[i];  //map the string to a char
                map_to_char[line[i]] = pattern[i]; //map the char to a strig
            }
            else //repeated item
            {
                if (map_to_str[pattern[i]] != line[i]) //if the string at that char is not equal
                    return false;                      //not correct mapping false
            }
        }
        return true;
    }
};