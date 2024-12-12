#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>

int main() {
    std::ifstream file("input.txt");
    std::string line;
    std::unordered_map<int,int> map1;
    std::vector<int> vec1;
    int number,result=0,qty=0;
    bool first = true;
    std::pair<std::unordered_map<int, int>::iterator, bool> insertRet;

    if (file.is_open()) { 
        while (getline(file, line)) { 
            std::istringstream iss(line); 
            while (iss >> number) { 
                if(first){
                    vec1.push_back(number);
                    first = false;
                }
                else{
                    insertRet = map1.insert({number,1});
                    if(!insertRet.second){
                        map1[number]=map1[number]+1;
                    }
                    first = true;     
                }
            } 
        }
    }
        file.close(); 
    for(int i=0;i<vec1.size();i++){
        result = map1[vec1[i]] * vec1[i] + result;
    }

    std::cout << result <<std::endl;
    return 0;
}