// Remove K Digits

string removeKdigits(string num, int k) {
    string result = "";
    for(char ch: num){
        // check if there is a number in result
        // if so then see if the ch we are at is smaller
        // and if we have removed < k elements, if we removed k then we shouldn't
        // remove anymore
        while(result.size() && result[result.size()-1] > ch && k) {
            result.pop_back();
            k--;
        }
        if(result.size() || ch!='0') result.push_back(ch); // want to avoid leading 0s but also add 0s after
    }
    // ensure if all values are the same then we remove the the right most
    while (result.size() && k--){
        result.pop_back();
    }
    return result==""?"0":result;
}
