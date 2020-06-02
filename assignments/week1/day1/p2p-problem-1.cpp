/**
 * tolowercase(string s)
 *  return all chars in lowercase
 * 
 * 
 */
#include <string>
#include <iostream>

std::string toLower(const std::string& str) {
    std::string retVal = "";
    
    for(auto& c : str) {
        if (c >= 'A' && c <= 'Z') {
            retVal += (c + 32);
        } else {
            retVal += c;
        }
    }
    
    return retVal;
}


int main() {
    
}