// Implementation of Stack Operations using Linked List 
// 1. Push an Element on to Stack // 2. Pop an Element // 3. Demonstrate Overflow Simulations on Stack // 4. Display Stack
// Stack -> LIFO : Stack Terminology - top, push, pop, overflow, underflow

// Building a Stack using Linked List, removes the possibility of OVERFLOW Condition.


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// Declaring *head* in GLobal Scope
Node *head = NULL;

// Push Operation
void Push(int stackData){
    Node *ptr = new Node();
    ptr -> data = stackData;
    ptr -> next = NULL;
    
    if (head == NULL){          // If Linked List is Empty
        head = ptr;
        cout << "Element pushed successfully to Stack !!!" << endl;
    }
    else{
        Node *temp = head;           // No OVERFLOW Condition here
        while (temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = ptr;
        cout << "Element pushed successfully to Stack !!!" << endl;
    }
}

// Pop Operation
void Pop(Node *ptr){
    // If Stack is Empty
    if (ptr == NULL){
        cout << "Stack Underflow Condition :(" << endl;
    }
    
    // If Stack has only 1 Element
    else if (ptr -> next == NULL){
        head = NULL;
        cout << "Element successfully Popped !" << endl;
        free(ptr);
    }
    
    // Other Cases
    else{
        while(ptr -> next -> next != NULL){
            ptr = ptr -> next;
        }
        Node *prev = ptr;
        ptr = ptr -> next;
        prev -> next = ptr -> next;
        cout << "Element successfully Popped !" << endl;
        free(ptr);
        return;
    }
}

// Display Stack
void DisplayStack(Node *ptr){
    if (ptr == NULL){
        cout << "Stack is Empty !" << endl;
    }
    
    else{
        cout << "Stack : ";
        
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
    cout << "\t\t\t\t\t\t\t\t***** Stack Operations using Linked List *****" << endl;
    
    while(1){
        char Choice;
        cout << "\n\nPress 1 to Push an Element onto Stack";
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
                Pop(head);
                break;
            }
            
            case '3':
            {
                DisplayStack(head);
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