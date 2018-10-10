#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>

#include <algorithm>    // std::next_permutation, std::sort

using namespace std;

typedef struct STACK {
    string str;
    int zero;
    int one;
    int two;
    int three;
    int four;
    int five;
    int six;
    int seven;
    int eight;
    int nine;
    bool increment;
} Stack;

void displayArray(int array[], int arraySize);
void failure();
Stack* addToStack(Stack stacks[], string str, int indexToAdd);
Stack addNumberToStack(Stack stack, string number);
bool checkStackForDuplicate(Stack stack[], Stack temp, int end);


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
    
   // bool firstFlag = true;
    
    list<int> permuList;
    
    
    cout << "Input the number stacks followed by the boxes: " << endl;
    getline (cin, str);
    
    // Check if it is valid input
    if (isdigit(str[0]) && str[1] == ' '){
        
        int arLen = str.length() - 2;
        int boxAr[arLen];
        numOfStacks = str[0] - '0';
        // Turn the user inputted string into a sum
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
        Stack* stackArray = malloc(sizeof(Stack)*(stackSize*10));
        int numbOfStacks = 0;
        
        // Get the permutations of the string to find possible stacks
        do {
            //cout << boxStr[0] << boxStr[1] << boxStr[2] << endl;
            //cout << boxStr << endl;
            temp = 0;
            for (i = 0; (unsigned)i  < boxStr.length() + 0; i++){
                //j = 0;
                //cout << boxStr << endl;
                temp = 0;
                tempStr = boxStr.substr(0, i);
                
                for (j = 0; j < i; j++){
                    temp = temp + (tempStr[j] - '0');
                   // cout << "Temp = " << temp << endl;
                }
                
                if (temp == stackSize){
                    cout << "Found a stack : " << tempStr << endl;
                    
                    //add to list]
                    stackArray[numbOfStacks] = addToStack(stackArray, tempStr, numbOfStacks);
                    //numbOfStacks++
                    if (stackArray[0].increment == true){
                        numbOfStacks++;
                        cout << "Found a stack : " << tempStr << endl;
                    }
                    
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

Stack* addToStack(Stack stacks[], string str, int indexToAdd){

    Stack temp;
    temp.str = str;
    temp = addNumberToStack(temp, str);
    stacks[0].increment = false;
    
    if (stacks == 0){
        stacks[indexToAdd] = temp;
        stacks[0].increment = true;
    } else {
        
        if ( checkStackForDuplicate(stacks, temp, indexToAdd) == true){
            // No duplicates
            stacks[indexToAdd] = temp;
            stacks[0].increment = true;
        } else {
            // already exists. Ignore this!
            return stacks;
        }
    }

    return stacks;

}

Stack addNumberToStack(Stack stack, string number){
    int i = 0;
    for (i = 0; i < number.length() ; i++){
        if (number[i] == '0'){
            stack.zero++;
        } else if (number[i] == '1'){
            stack.one++;
        } else if (number[i] == '2'){
            stack.two++;
        } else if (number[i] == '3'){
            stack.three++;
        } else if (number[i] == '4'){
            stack.four++;
        } else if (number[i] == '5'){
            stack.five++;
        } else if (number[i] == '6'){
            stack.six++;
        } else if (number[i] == '7'){
            stack.seven++;
        } else if (number[i] == '8'){
            stack.eight++;
        } else if (number[i] == '9'){
            stack.nine++;
        } else {
            exit (EXIT_FAILURE);
        }
    }
    
    return stack;
}
/*
typedef struct STACK {
    string str;
    int zero;
    int one;
    int two;
    int three;
    int four;
    int five;
    int six;
    int seven;
    int eight;
    int nine;
} Stack;
*/
bool checkStackForDuplicate(Stack stack[], Stack temp, int end){
    int i = 0;
    for (i = 0; i < end; i ++){
        
        if ( (stack[i].zero == temp.zero) && (stack[i].one == temp.one) 
        && (stack[i].two == temp.two) && (stack[i].three == temp.three)
        && (stack[i].four == temp.four) && (stack[i].five == temp.five)
        && (stack[i].six == temp.six) && (stack[i].seven == temp.seven)
        && (stack[i].eight == temp.eight) && (stack[i].nine == temp.nine) ){
            return false;
        }
    
    }
    return true;
}
