// Perform Enqueue, Dequeue & Display Operations on Queue using Linked List
// Queue -> FIFO

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

// Declaration of *head* node in Global Scope
Node *head = NULL;


// Enqueue Function
void Enqueue(int nodeData){
    Node *ptr = new Node();
    ptr -> data = nodeData;
    ptr -> next = NULL;
    
    if(head == NULL){               // If Linked List is Empty
        head = ptr;
        cout << "Element added successfully to Queue !!!" << endl;
    }
    
    else{
        Node *newNode = head;
        while(newNode -> next != NULL){
            newNode = newNode -> next;
        }

        newNode -> next = ptr;
        cout << "Element added successfully to Queue !!!" << endl;
    }
}

// Dequeue Function
void Dequeue(Node *ptr){
    // If Linked List is Empty
    if(ptr == NULL){
        cout << "Queue Underflow :(" << endl;
    }
    
    // If Linked List has only 1 Element
    else if(ptr -> next == NULL){
        head = NULL;
        cout << "Element successfully deleted from Queue !" << endl;
        free(ptr);
    }
    
    // Other Conditions
    else{
        head = ptr -> next;
        free(ptr);
        cout << "Element successfully deleted from Queue !" << endl;
    }
}

// Display Function
void Display(Node *ptr){
    if(ptr == NULL){
        cout << "Queue is Empty !" << endl;
    }
    
    else{
        cout << "Queue : ";
        
        while(ptr -> next != NULL){
            cout << ptr -> data << " -> ";
            ptr = ptr -> next;
        }
        
        if (ptr -> next == NULL){
            cout << ptr -> data << "";
            ptr = ptr -> next;
        }
        cout << "\n";
    }
}


int main(){
    cout << "\t\t\t\t\t\t\t\t***** Queue Operations using Linked List *****" << endl;
    
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
                Dequeue(head);
                break;
            }
            
            case '3':
            {
                Display(head);
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