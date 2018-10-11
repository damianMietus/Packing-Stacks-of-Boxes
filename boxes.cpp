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
    int k = 0;
    int temp = 0;
    int sum = 0;
    
    string str;
    string boxStr;
    string tempStr;
    
    bool duplicateFlag = true;
    bool firstFlag = true;
    
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
        //Sort the string of boxes
        sort(boxStr.begin(), boxStr.end());
        
        cout << boxStr << endl;
        
        string tempStr;
        Stack stackArray[10 * numOfStacks];
        int numbOfStacks = 1;
        
        
        
        
        
        // Get the permutations of the string to find possible stacks
        do {
            //cout << boxStr[0] << boxStr[1] << boxStr[2] << endl;
            cout <<"This string is entering the for loop: "  <<boxStr << endl;
            temp = 0;
            for (i = 0; (unsigned)i  < boxStr.length() - 1; i++){
                //j = 0;
                //cout << boxStr << endl;
                temp = 0;
                //for (k = 0; k < boxStr.length() )
                cout << "i = " << i << endl;
                tempStr = boxStr.substr(0, i);
                cout << tempStr << endl;
                for (j = 0; j < i; j++){
                    temp = temp + (tempStr[j] - '0');
                    //cout << "Temp = " << temp << endl;
                }
                
                if (temp == stackSize){
                    //cout << "Found a stack : " << tempStr << endl;
                    
                    //add to list]
                   // stackArray[numbOfStacks] = addToStack(stackArray, tempStr, numbOfStacks);
                   
                   Stack temp;
                   temp.str = tempStr;
                   temp.zero = 0;
                   temp.one = 0;
                   temp.two = 0;
                   temp.three = 0;
                   temp.four = 0;
                   temp.five = 0;
                   temp.six = 0;
                   temp.seven = 0;
                   temp.eight = 0;
                   temp.nine = 0;
                   //Put numbers in this stack
                    for (i = 0; i < temp.str.length() ; i++){
                        if (temp.str[i] == '0'){
                            temp.zero++;
                        } else if (temp.str[i] == '1'){
                            temp.one++;
                        } else if (temp.str[i] == '2'){
                            temp.two++;
                        } else if (temp.str[i] == '3'){
                            temp.three++;
                        } else if (temp.str[i] == '4'){
                            temp.four++;
                        } else if (temp.str[i] == '5'){
                            temp.five++;
                        } else if (temp.str[i] == '6'){
                            temp.six++;
                        } else if (temp.str[i] == '7'){
                            temp.seven++;
                        } else if (temp.str[i] == '8'){
                            temp.eight++;
                        } else if (temp.str[i] == '9'){
                            temp.nine++;
                        } else {
                            exit (EXIT_FAILURE);
                        }
                    }
                   
                    if (firstFlag == true){
                        stackArray[0] = temp;
                        firstFlag = false;
                        cout << "The first one: " << stackArray[0].str << endl;
                    } else {
                        // check for duplicate stacks
                        duplicateFlag = false;
                        for (i = 0; i < numbOfStacks+1; i ++){
        
                            if ( (stackArray[i].zero == temp.zero) && (stackArray[i].one == temp.one) 
                            && (stackArray[i].two == temp.two) && (stackArray[i].three == temp.three)
                            && (stackArray[i].four == temp.four) && (stackArray[i].five == temp.five)
                            && (stackArray[i].six == temp.six) && (stackArray[i].seven == temp.seven)
                            && (stackArray[i].eight == temp.eight) && (stackArray[i].nine == temp.nine) ){
                                duplicateFlag = true;  
                                cout << "D'oh! It already exists! xD" << endl;
                                break;
                            }
    
                        }
                        if (duplicateFlag == false){
                            stackArray[numbOfStacks] = temp;
                            cout << "String: " << stackArray[numbOfStacks].str << " put in this index: " << numbOfStacks << endl;
                            numbOfStacks++;
                        } // else it already exists. Change nothing
                        
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

/*

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

*/
