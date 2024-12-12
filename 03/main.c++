#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <regex>

int main() {
    std::ifstream file("input.txt");
    std::regex pattern(R"(mul\(([1-9]\d{0,2}),([1-9]\d{0,2})\))");
    std::string line;
    std::smatch matches;
    std::string checkLine;
    std::vector<int> vec1;
    int number,result=0;
    bool rising = false;
    bool falling = false;
    bool safe = true;

    if (file.is_open()) { 
        while (getline(file, line)) { 
            std::string::const_iterator searchStart(line.cbegin());
            while (std::regex_search(searchStart, line.cend(), matches, pattern)) {
                vec1.push_back(std::stoi(matches[1].str())); 
                vec1.push_back(std::stoi(matches[2].str()));
                searchStart = matches.suffix().first;
            }
        }
        file.close(); 
    }
    for(int i=0;i<vec1.size();i+=2){
        result=result+vec1[i]*vec1[i+1];
    }
    std::cout << result <<std::endl;
    return 0;
}