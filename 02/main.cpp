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
    int rising = 0;
    int falling = 0;
    bool safe = true;
    bool valueErased = false;

    if (file.is_open()) { 
        while (getline(file, line)) { 
            std::istringstream iss(line); 
            while (iss >> number) { 
                vec1.push_back(number);
            }
            int vecSize = vec1.size()-1;
            for(int i=0;i<vecSize;i++){
                if(vec1[i]>vec1[i+1])
                    falling++;
                if(vec1[i]<vec1[i+1])
                    rising++;
            }

            if(rising == vecSize || falling == vecSize)
            {
                safe = true;
            }
            else if (rising == vecSize-1){
                for(int i=0;i<vec1.size()-1;i++){
                    if(i==0 && vec1[i]>=vec1[i+1]){
                        vec1.erase(vec1.begin()+i);
                        break;
                    }
                    else if(i==vec1.size()-1 && vec1[i]>=vec1[i+1]){
                       vec1.erase(vec1.begin()+i+1);
                       break; 
                    }
                    else if(vec1[i]>=vec1[i+1]){
                        vec1.erase(vec1.begin()+i);
                        break;
                    }
                }
                valueErased = true;
            }
            else if(falling == vecSize-1){
                for(int i=0;i<vec1.size()-1;i++){
                    if(i==0 && vec1[i]<=vec1[i+1]){
                        vec1.erase(vec1.begin()+i);
                        break;
                    }
                    else if(i==vec1.size()-1 && vec1[i]<=vec1[i+1]){
                       vec1.erase(vec1.begin()+i+1);
                       break; 
                    }
                    else if(vec1[i]<=vec1[i+1]){
                        vec1.erase(vec1.begin()+i);
                        break;
                    }
                }
                valueErased = true;
            }
            else
                safe = false;

            vecSize = vec1.size()-1;
            for(int i=0;i<vecSize;i++){
                if(!safe)
                    break;
                if(rising>2){
                    if(abs(vec1[i]-vec1[i+1])>3){
                        if(!valueErased){
                            if(i>0)
                                vec1.erase(vec1.begin()+i+1);
                            else
                                vec1.erase(vec1.begin()+i);
                            valueErased = true;
                            i=-1;
                            vecSize=vecSize-1;
                        }
                        else
                            safe = false;
                    }
                }
                else if(falling>2){
                    if(abs(vec1[i]-vec1[i+1])>3)
                        if(!valueErased){
                            if(i>0)
                                vec1.erase(vec1.begin()+i);
                            else
                                vec1.erase(vec1.begin()+i+1);
                            valueErased = true;
                            i=-1;
                            vecSize=vecSize-1;
                        }
                        else
                            safe = false;
                }
                else
                    safe = false;

            }
            if(safe)
                result++;
            vec1.clear();
            rising = 0;
            falling = 0;
            safe = true;
            valueErased = false;
        }
        file.close(); 
    } 
    std::cout << result <<std::endl;
    return 0;
}