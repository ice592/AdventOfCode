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
    std::regex pattern(R"(mul\(([1-9]\d{0,2}),([1-9]\d{0,2})\)|do\(\)|don't\(\))");
    std::string line;
    std::smatch matches;
    std::string checkLine;
    std::vector<int> vec1;
    long int number,result=0;
    bool safe = true;

    if (file.is_open()) { 
        while (getline(file, line)) { 
            std::string::const_iterator searchStart(line.cbegin());
            while (std::regex_search(searchStart, line.cend(), matches, pattern)) {
                std::string match = matches[0].str();
                if(match == "do()")
                    safe = true;
                else if(match == "don't()")
                    safe = false;
                else if(safe && matches[1].matched && matches[2].matched){
                    vec1.push_back(std::stoi(matches[1].str()));
                    vec1.push_back(std::stoi(matches[2].str()));
                }
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