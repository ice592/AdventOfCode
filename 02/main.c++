#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>

int main() {
    std::ifstream file("input.txt");
    std::string line;
    std::vector<int> vec1;
    int number,result=0;
    bool rising = false;
    bool falling = false;
    bool safe = true;

    if (file.is_open()) { 
        while (getline(file, line)) { 
            std::istringstream iss(line); 
            while (iss >> number) { 
                vec1.push_back(number);
            }
            if(vec1[0]<vec1[1])
                rising = true;
            else if(vec1[0]>vec1[1])
                falling = true;
            else
                safe = false;
            for(unsigned int i=0;i<vec1.size()-1;i++){
                if(!safe)
                    break;
                if(vec1[i]<vec1[i+1] && rising){
                    if(abs(vec1[i]-vec1[i+1])>3)
                        safe = false;
                }
                else if(vec1[i]>vec1[i+1] && falling){
                    if(abs(vec1[i]-vec1[i+1])>3)
                        safe = false;
                }
                else
                    safe = false;

            }
            if(safe)
                result++;
            vec1.clear();
            rising = false;
            falling = false;
            safe = true;
        }
        file.close(); 
    } 
    std::cout << result <<std::endl;
    return 0;
}