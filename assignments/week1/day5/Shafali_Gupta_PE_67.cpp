#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
// #include <sstream>

/*
I really don't know how to approach this problem. I know that you would have to read in the file by every line.
Then you find the max of the first line. Then I noticed that in the next line, the indexes would be either the index
in the previous line or the one after. So you would find the max of those two, and then proceed with the next lines.
I don't know how to implement this. 
*/

int maxLineOne(std::string s){
  int i = 0;
  std::string n = "";
  std::vector<int> v;
  while(i<s.length()){
    if(s[i] != ' '){
      n += s[i];
    }
    else{
      int num = std::stoi(n);
      v.push_back(num);
      n = "";
    }
  }
  return maxVector()
}
int maxPathSum(){
  std::ifstream myfile ("p067_triangle.txt");
    std::string line;
    int lineNum = 0;
    int ret = 0;
    if (myfile.is_open()){
    while ( getline (myfile,line) )
    {
      if(lineNum ==0){
        ret += maxLineOne(line);
      }
      else{

      }
    }
    myfile.close();
  }
  return 0;
}

int main(){
  // maxPathSum();
  // std::cout << typeid(int).name()<< '\n';
  // std::cout << typeid(std::stoi("34")).name()<< '\n';
  // std::string line;
  // std::ifstream myfile ("p067_triangle.txt");
  //   if (myfile.is_open()){
  //   while ( getline (myfile,line) )
  //   {
  //     std::cout << line << '\n';
  //   }
  //   myfile.close();
  // }
}
