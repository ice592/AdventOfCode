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
    int currentRow = 0;
    int currentColumn = -1;
    while(currentColumn == -1){
        currentColumn = vec1[currentRow].find('^');
        currentRow++;
    }
    currentRow--;
    while(1){
        if(vec1[currentRow][currentColumn]=='^'){
            vec1[currentRow][currentColumn]= 'X';
            if(currentRow==0)
                break;
            else if(vec1[currentRow-1][currentColumn]=='#'){
                vec1[currentRow][currentColumn]='>';
            }
            else{
                currentRow--;
                vec1[currentRow][currentColumn]='^';
            }
        }

        if(vec1[currentRow][currentColumn]=='>'){
            vec1[currentRow][currentColumn]= 'X';
            if(currentColumn==maxColums-1)
                break;
            else if(vec1[currentRow][currentColumn+1]=='#'){
                vec1[currentRow][currentColumn]='v';
            }
            else{
                currentColumn++;
                vec1[currentRow][currentColumn]='>';
            }
        }

        if(vec1[currentRow][currentColumn]=='v'){
            vec1[currentRow][currentColumn]= 'X';
            if(currentRow==maxRow-1)
                break;
            else if(vec1[currentRow+1][currentColumn]=='#'){
                vec1[currentRow][currentColumn]='<';
            }
            else{
                currentRow++;
                vec1[currentRow][currentColumn]='v';
            }
        }

        if(vec1[currentRow][currentColumn]=='<'){
            vec1[currentRow][currentColumn]= 'X';
            if(currentColumn==0)
                break;
            else if(vec1[currentRow][currentColumn-1]=='#'){
                vec1[currentRow][currentColumn]='^';
            }
            else{
                currentColumn--;
                vec1[currentRow][currentColumn]='<';
            }
        }


    }

    for(currentRow=0;currentRow<maxRow;currentRow++){
        for(currentColumn=0;currentColumn<maxColums;currentColumn++){
            if(vec1[currentRow][currentColumn]=='X'){
                result++;
            }
        }
    }


    std::cout << result <<std::endl;
    return 0;
}