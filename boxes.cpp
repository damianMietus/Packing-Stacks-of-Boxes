// Reddit Daily Programmer
// Damian Mietus
// Challenge #349 [Intermediate] Packing Stacks of Boxes
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
void displayStackArray(Stack array[], int arraySize);
void failure();
Stack createStack (string str);
Stack subtractStackVals(Stack s1, Stack s2);


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
            //cout <<"This string is entering the for loop: "  <<boxStr << endl;
            temp = 0;
            for (i = 0; (unsigned)i  < boxStr.length() - 0; i++){
                //j = 0;
                //cout << boxStr << endl;
                temp = 0;
                //for (k = 0; k < boxStr.length() )
                //cout << "i = " << i << endl;
                tempStr = boxStr.substr(0, i);
                //cout << tempStr << endl;
                for (j = 0; j < i; j++){
                    temp = temp + (tempStr[j] - '0');
                    //cout << "Temp = " << temp << endl;
                }
                
                if (temp == stackSize){
                    //cout << "Found a stack : " << tempStr << endl;
                    
                    //add to list]
                   // stackArray[numbOfStacks] = addToStack(stackArray, tempStr, numbOfStacks);
                   
                   Stack temp = createStack(tempStr);
                   /*
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
                    */
                   
                    if (firstFlag == true){
                        stackArray[0] = temp;
                        firstFlag = false;
                        cout << "The first one: " << stackArray[0].str << endl;
                    } else {
                        // check for duplicate stacks
                        duplicateFlag = false;
                        for (k = 0; k < numbOfStacks+1; k ++){
        
                            if ( (stackArray[k].zero == temp.zero) && (stackArray[k].one == temp.one) 
                            && (stackArray[k].two == temp.two) && (stackArray[k].three == temp.three)
                            && (stackArray[k].four == temp.four) && (stackArray[k].five == temp.five)
                            && (stackArray[k].six == temp.six) && (stackArray[k].seven == temp.seven)
                            && (stackArray[k].eight == temp.eight) && (stackArray[k].nine == temp.nine) ){
                                duplicateFlag = true;  
                                //cout << "It exists." << endl;
                                //i++;
                                //break;
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
        
        
        Stack inputStack = createStack(boxStr);
        int oldNumbStacks = numbOfStacks;
        //Begin looking for potential edge case doubles of stacks
        for (i = 0; i < oldNumbStacks; i++){
            Stack temp = stackArray[i];
            Stack in = createStack(boxStr);
            cout << "temp.str := "<< temp.str << endl;
            cout << "temp.six := " << temp.six << endl;
            cout << "in.six := " << in.six << endl;
            while ( (temp.one < in.one) && (temp.two < in.two) && (temp.three < in.three) 
                && (temp.four < in.four) && (temp.five < in.five) && (temp.six < in.six) 
                && (temp.seven < in.seven) && (temp.eight < in.eight) && (temp.nine < in.nine)
                ){
                //subtract it
                in = subtractStackVals(in, temp);
                stackArray[numbOfStacks] = temp;
                cout << "adding this := "<<temp.str << endl;
                numbOfStacks++;
                
            }
 
        }
        
        displayStackArray(stackArray, numbOfStacks);

    } else {
     
        failure();
        
    }

}

void displayStackArray(Stack array[], int arraySize){
    int i = 0;
    for (i = 0; i < arraySize; i++){
        cout << array[i].str << ", ";
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

Stack createStack (string str){
    Stack temp;
    temp.str = str;
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
    
    int i = 0;
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
    return temp;
}
// s1 == in, s2 == temp
Stack subtractStackVals(Stack s1, Stack s2){
    s1.one = s1.one - s2.one;
    s1.two = s1.two - s2.two;
    s1.three = s1.three - s2.three;
    s1.four = s1.four - s2.four;
    s1.five = s1.five - s2.five;
    s1.six = s1.six - s2.six;
    s1.seven = s1.seven - s2.seven;
    s1.eight = s1.eight - s2.eight;
    s1.nine = s1.nine - s2.nine;
    
    return s1;
}
