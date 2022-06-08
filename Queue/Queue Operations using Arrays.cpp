// Perform Enqueue, Dequeue & Display Operations on Queue
// Queue -> FIFO

#include <iostream>
using namespace std;

// Limit maximum size of Queue to *5* -> For Convenience Purpose
#define queueSize 5
int Queue[queueSize];

// Queue Essentials (Declared in Global Scope)
int FrontEnd = -1;
int RearEnd = -1;

// Enqueue Function
void Enqueue(int Data){
    if(RearEnd == queueSize - 1){
        cout << "Queue Overflow :(" << endl;
    }
    
    else{
        if(FrontEnd == -1){
            FrontEnd ++;
        }
        
        RearEnd ++;
        Queue[RearEnd] = Data;
        cout << "Element Successfully Added to Queue" << endl;
    }
}

// Dequeue Function
void Dequeue(){
    if (FrontEnd <= RearEnd){
        FrontEnd ++;
        cout << "Element Successfully Removed from Queue" << endl;
    }
    
    else{
        cout << "Queue Underflow :(" << endl;
    }
}

// Display Function
void Display(){
    if(FrontEnd > RearEnd){
        cout << "Queue is Empty" << endl;
    }
    
    else{
        cout << "Queue : ";
        
        for(int i = FrontEnd; i <= RearEnd; i++){
            cout << Queue[i] << " ";
        }
        
        cout << "\n";
    }
}


int main(){
    cout << "\t\t\t\t\t\t\t\t***** Queue Operations using Arrays *****" << endl;
    
    while(1){
        char Choice;
        cout << "\n\nPress 1 to Enqueue an Element";
        cout << "\nPress 2 to Dequeue an Element";
        cout << "\nPress 3 to Display Queue";
        cout << "\nPress 4 to Exit";
        
        cout << "\n\nUser Choice : ";
        cin >> Choice;
        
        switch(Choice){
            case '1':
            {
                int queueDataInput;
                cout << "\nItem to be Enqueued to Queue ? ";
                cin >> queueDataInput;
                Enqueue(queueDataInput);
                break;
            }
            
            case '2':
            {
                Dequeue();
                break;
            }
            
            case '3':
            {
                Display();
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