// Implementation of Stack Operations using Arrays 
// 1. Push an Element on to Stack // 2. Pop an Element // 3. Demonstrate Overflow Simulations on Stack // 4. Display Stack
// Stack -> LIFO : Stack Terminology - top, push, pop, overflow, underflow

#include <iostream>
using namespace std;

// Limit maximum size of Stack to *10* -> For Convenience Purpose
#define stackSize 10
int stack[stackSize];

// Uppermost Element of Stack
int top = -1;

// Push Function
void Push(int Data){
    if (top == stackSize - 1){
        cout << "Stack Overflow Condition :(";
    }
    
    else{
        top += 1;
        stack[top] = Data;
        cout << "Element pushed successfully to Stack !!!";
    }
}

// Pop Function
void Pop(){
    if (top == -1){
        cout << "Stack Underflow Condition :(";
    }
    
    else{
        // No need for Deletion or anything, as for loop for DisplayStack function only works till *top*
        top -= 1;
        cout << "Element popped successfully from Stack !!!";
    }
}

// Display Stack [(Left -> Right) => (Down -> Top)]
void DisplayStack(){
    if (top == -1){
        cout << "Stack is Empty !";
    }
    
    else{
        cout << "Stack : ";
        for (int i = 0; i <= top; i++){
            cout << stack[i] << " ";
        }
    }
}

int main()
{
    cout << "\t\t\t\t\t\t\t\t***** Stack Operations using Arrays *****" << endl;
    
    while(1){
        char Choice;
        cout << "\n\n\nPress 1 to Push an Element onto Stack";
        cout << "\nPress 2 to Pop an Element";
        cout << "\nPress 3 to Display Stack";
        cout << "\nPress 4 to Exit";
        
        cout << "\n\nUser Choice : ";
        cin >> Choice;
        
        switch(Choice){
            case '1':
            {
                int stackDataInput;
                cout << "\nItem to be Pushed to Stack ? ";
                cin >> stackDataInput;
                Push(stackDataInput);
                break;
            }
            
            case '2':
            {
                Pop();
                break;
            }
            
            case '3':
            {
                DisplayStack();
                break;
            }
            
            case '4':
            {
                cout << "\nThank You :) Have a Nice Day" << endl;
                exit(0);
            }
            
            default:
            {
                cout << "\nInvalid Input :(" << endl;
                break;
            }
        }
    }
    return 0;
}