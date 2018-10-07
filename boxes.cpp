#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>

#include <algorithm>    // std::next_permutation, std::sort

using namespace std;

void displayArray(int array[], int arraySize);
void failure();


int main()
{

    int numOfStacks = 0;
    int stackSize = 0;
    int i = 0;
    int j = 0;
    int temp = 0;
    int sum = 0;
    
    string str;
    string boxStr;
    string tempStr;
    
    list<int> permuList;
    
    
    cout << "Input the number stacks followed by the boxes: " << endl;
    getline (cin, str);
    
    if (isdigit(str[0]) && str[1] == ' '){
        
        int arLen = str.length() - 2;
        int boxAr[arLen];
        numOfStacks = str[0] - '0';
        for (i = 2; (unsigned)i < 0 + str.length(); i++){
 
            temp = str[i] - '0';
            boxAr[j] = temp;
            j++;
            sum = sum+temp;
        
        }
        
        if ((sum % numOfStacks) != 0){
            failure();
        }
        
        stackSize = (sum / numOfStacks);
        cout <<"The stacks must be size of : " << stackSize << "\n";
        
        displayArray(boxAr, arLen);
        
        boxStr = str.substr(2, str.length() - 2);
        cout << boxStr << endl;
        
        string tempStr;
        
        do {
            //cout << boxStr[0] << boxStr[1] << boxStr[2] << endl;
            //cout << boxStr << endl;
            temp = 0;
            for (i = 0; (unsigned)i  < boxStr.length() + 0; i++){
                //j = 0;
                temp = 0;
                tempStr = boxStr.substr(0, i);
                for (j = 0; j < i; j++){
                    temp = temp + (tempStr[j] - '0');
                   // cout << "Temp = " << temp << endl;
                }
                
                if (temp == stackSize){
                    cout << "Found a possible stack : " << tempStr << endl;
                }
                      
            }
            
        } while (next_permutation(boxStr.begin(), boxStr.end()));
        

    } else {
     
        failure();
        
    }

}

void displayArray(int array[], int arraySize){
    int i = 0;
    for (i = 0; i < arraySize; i++){
        cout << array[i] << ", ";
    }
    
}

void failure(){
    cout << "Invalid input. Try re-running the program\n";
    exit (EXIT_FAILURE);
}
