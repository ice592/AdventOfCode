#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

int main() {
    std::cout << "hello world" << std::endl;
    std::ifstream file("input.txt");
    std::string line;
    std::vector<int> vec1;
    std::vector<int> vec2;
    int number,result=0;
    bool first = true;

    if (file.is_open()) { 
        while (getline(file, line)) { 
            std::istringstream iss(line); 
            while (iss >> number) { 
                if(first){
                    vec1.push_back(number);
                    first = false;
                }
                else{
                    vec2.push_back(number);
                    first = true;
                }
                
            } 
        }
        file.close(); 
    } 

    std::stable_sort(vec1.begin(),vec1.end());
    std::stable_sort(vec2.begin(),vec2.end());
    for(unsigned int i=0;i<vec1.size();i++){
        result=result+std::max(vec1[i],vec2[i])-std::min(vec1[i],vec2[i]);
    }
    std::cout << result <<std::endl;
    return 0;
}