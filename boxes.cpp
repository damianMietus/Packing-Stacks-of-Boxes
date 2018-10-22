// Reddit Daily Programmer
// Damian Mietus
// Challenge #349 [Intermediate] Packing Stacks of Boxes
#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
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
Stack setToZero();

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
        boxStr = str.substr(2, str.length() - 2);
        //Sort the string of boxes
        sort(boxStr.begin(), boxStr.end());

        string tempStr;
        Stack stackArray[10 * numOfStacks];
        int numbOfStacks = 1;
       
        // Get the permutations of the string to find possible stacks
        do {

            temp = 0;
            for (i = 0; (unsigned)i  < boxStr.length() - 0; i++){
                temp = 0;
                tempStr = boxStr.substr(0, i);
                for (j = 0; j < i; j++){
                    temp = temp + (tempStr[j] - '0');
                }
                
                if (temp == stackSize){
                   
                   Stack temp = createStack(tempStr);
                   
                    if (firstFlag == true){
                        stackArray[0] = temp;
                        firstFlag = false;
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
                            }
    
                        }
                        if (duplicateFlag == false){
                            stackArray[numbOfStacks] = temp;
                            numbOfStacks++;
                        } // else it already exists. Change nothing
                        
                    }  
                    
                }
                      
            }
            
        } while (next_permutation(boxStr.begin(), boxStr.end()));
        
        Stack inputStack = createStack(boxStr);
        int oldNumbStacks = numbOfStacks;
        
        Stack in = createStack(boxStr);
        int tone = in.one;
        int ttwo = in.two;
        int tthr = in.three;
        int tfou = in.four;
        int tfiv = in.five;
        int tsix = in.six;
        int tsev = in.seven;
        int teig = in.eight;
        int tnin = in.nine;
        
        //Begin looking for potential edge case doubles of stacks
        for (i = 0; i < oldNumbStacks; i++){
            Stack temp = stackArray[i];
            
            Stack in = createStack(boxStr);
            int tone = in.one;
            int ttwo = in.two;
            int tthr = in.three;
            int tfou = in.four;
            int tfiv = in.five;
            int tsix = in.six;
            int tsev = in.seven;
            int teig = in.eight;
            int tnin = in.nine;

		    while( (tone > 0) || (ttwo > 0) || (tthr > 0) 
                    || (tfou > 0) || (tfiv > 0) || (tsix > 0) 
                    || (tsev > 0) || (teig > 0) || (tnin > 0)
            ){
                //subtract it
                bool addFlag = true;
                if (temp.one > 0){
                    if (temp.one < tone){
                        addFlag = true;    
                    } else {
                        break;
                    }
                } if (temp.two > 0){
                    if (temp.two < ttwo){
                        addFlag = true;    
                    } else {
                        break;
                    }
                } if (temp.three > 0){
                    if (temp.three < tthr){
                        addFlag = true;    
                    } else {
                        break;
                    }
                } if (temp.four > 0){
                    if (temp.four < tfou){
                        addFlag = true;    
                    } else {
                        break;
                    }
                } if (temp.five > 0){
                    if (temp.five < tfiv){
                        addFlag = true;    
                    } else {
                        break;
                    }
                } if (temp.six > 0){
                    if (temp.six < tsix){
                        addFlag = true;    
                    } else {
                        break;
                    }
                } if (temp.seven > 0){
                    if (temp.seven < tsev){
                        addFlag = true;    
                    } else {
                        break;
                    }
                } if (temp.eight > 0){
                    if (temp.eight < teig){
                        addFlag = true;    
                    } else {
                        break;
                    }
                } if (temp.nine > 0){
                    if (temp.nine < tnin){
                        addFlag = true;    
                    } else {
                        break;
                    }
                } 
                
                if (addFlag = true){
                    tone = tone - (temp.one);
                    ttwo = ttwo - (temp.two);
                    tthr = tthr - (temp.three);
                    tfou = tfou - (temp.four);
                    tfiv = tfiv - (temp.five);
                    tsix = tsix - (temp.six);
                    tsev = tsev - (temp.seven);
                    teig = teig - (temp.eight);
                    tnin = tnin - (temp.nine);
                    
                    stackArray[numbOfStacks] = temp;
                    numbOfStacks++;                    
                }

            }

        }
        
        //Begin the check to find legal stack combination
    
        //Make string to be permuted to  check for legal stack combination
        string indexStr;
        j = 0;
        stringstream ss;
        for (i = 0; i < numbOfStacks; i++){
            ss << i;
            indexStr = ss.str();
            j += 1;
        }

        string strAr[100];
        int strArSize;
        bool endFlag = false;      
        
        do {
            endFlag = false;
            for (i = 0; (unsigned)i  < indexStr.length() + 1; i++){

                tempStr = indexStr.substr(0, i);
                
                //reset addUp stack
                Stack addUp = setToZero();
                //reset final output Array
                for (k = 0; k < 100; k++){
                    strAr[k] = "";
                }
                //add to addUp stack
                for (j = 0; j < tempStr.length() + 1; j++){
                    int indx = tempStr[j] - '0';
                    
                    addUp.one += stackArray[indx].one;
                    addUp.two += stackArray[indx].two;
                    addUp.three += stackArray[indx].three;
                    addUp.four += stackArray[indx].four;
                    addUp.five += stackArray[indx].five;
                    addUp.six += stackArray[indx].six;
                    addUp.seven += stackArray[indx].seven;
                    addUp.eight += stackArray[indx].eight;
                    addUp.nine += stackArray[indx].nine;
                    strAr[j] = stackArray[indx].str;
                    strArSize = j;
                    
                }
                
                if ((addUp.one == in.one) && (addUp.two == in.two) && (addUp.three == in.three) && 
                (addUp.four == in.four) && (addUp.five == in.five) && (addUp.six == in.six) && 
                (addUp.seven == in.seven) && (addUp.eight == in.eight) && (addUp.nine == in.nine)){
                    
                    cout << "It is stackable: ";
                    for (i = 0; i < strArSize; i++){
                        if (i != strArSize-1){
                            cout << strAr[i] << ", ";                              
                        } else {
                            cout << strAr[i] << endl; 
                        }
  
                    }
                    return(0);

                }
                    
            }
            
        } while (next_permutation(indexStr.begin(), indexStr.end()));
        
        failure();

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
        cout << ", " <<  array[i];
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

Stack setToZero(){
    Stack temp;
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
    
    return temp;
}

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
