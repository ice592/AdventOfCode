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
    std::vector<std::string> vec1;
    int result = 0;

    if(file.is_open()){
        while(getline(file,line)){
            std::istringstream iss(line);
            std::vector<std::string> row;
            std::string cell;

            while(getline(iss,cell,'\n')){
                vec1.push_back(cell);
            }
        }
        file.close();
    }
    
    const int maxColums = vec1.at(0).size();
    const int maxRow = vec1.size();
    std::string stringBefore,currentString,afterString;

    for(int currentRow=0;currentRow<maxRow;currentRow++){
        if(currentRow>0)
            stringBefore = vec1[currentRow-1];
        currentString = vec1[currentRow];
        if(currentRow!=maxRow-1)
            afterString = vec1[currentRow+1];
        for(int currentColumn=0;currentColumn<maxColums;currentColumn++){
            if(vec1[currentRow][currentColumn]=='X'){
                //Check for backwards horizontal SAMX
                if(currentColumn>2){
                    if(vec1[currentRow][currentColumn-1]=='M'
                    && vec1[currentRow][currentColumn-2]=='A'
                    && vec1[currentRow][currentColumn-3]=='S')
                    result++;
                }

                //Check for backwards diagonal '\' SAMX
                if(currentColumn>2 && currentRow>2){
                    if(vec1[currentRow-1][currentColumn-1]=='M'
                    && vec1[currentRow-2][currentColumn-2]=='A'
                    && vec1[currentRow-3][currentColumn-3]=='S')
                    result++;
                }

                //Check for backwards vertical SAMX
                if(currentRow>2){
                    if(vec1[currentRow-1][currentColumn]=='M'
                    && vec1[currentRow-2][currentColumn]=='A'
                    && vec1[currentRow-3][currentColumn]=='S')
                    result++;
                }

                //Check for diagonal '/' XMAS
                if(currentRow>2 && currentColumn<maxColums-3){
                    if(vec1[currentRow-1][currentColumn+1]=='M'
                    && vec1[currentRow-2][currentColumn+2]=='A'
                    && vec1[currentRow-3][currentColumn+3]=='S')
                    result++;
                }

                //Check for horizontal XMAS
                if(currentColumn<maxColums-3){
                    if(vec1[currentRow][currentColumn+1]=='M'
                    && vec1[currentRow][currentColumn+2]=='A'
                    && vec1[currentRow][currentColumn+3]=='S')
                    result++;
                }
                
                //Check for diagonal '\' XMAS
                if(currentColumn<maxColums-3 && currentRow<maxRow-3){
                    if(vec1[currentRow+1][currentColumn+1]=='M'
                    && vec1[currentRow+2][currentColumn+2]=='A'
                    && vec1[currentRow+3][currentColumn+3]=='S')
                    result++;
                }

                //Check for vertical XMAS
                if(currentRow<maxRow-3){
                    if(vec1[currentRow+1][currentColumn]=='M'
                    && vec1[currentRow+2][currentColumn]=='A'
                    && vec1[currentRow+3][currentColumn]=='S')
                    result++;
                }

                //Check for diagonal backwards '/' SAMX
                if(currentColumn>2 && currentRow<maxRow-3){
                    if(vec1[currentRow+1][currentColumn-1]=='M'
                    && vec1[currentRow+2][currentColumn-2]=='A'
                    && vec1[currentRow+3][currentColumn-3]=='S')
                    result++;
                }
            }
        }
    }

    std::cout << result <<std::endl;
    return 0;
}