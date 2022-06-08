#include <iostream>
#include <string.h>
using namespace std;

// Declare Structure
struct Node{
    string data;
    Node *next;
};

// Assign head in Global Scope
Node *head = NULL;

// Insert Function
void AddEmployeeData(string NodeData){
    Node *ptr = new Node();
    ptr -> data = NodeData;
    ptr -> next = NULL;
    
    if (head == NULL){          // If Linked List is Empty
        head = ptr;
    }
    else{
        Node *temp = head;
        while (temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = ptr;  
    }
}

// Display Function
void DisplayEmployeeData(Node *ptr){
    cout << "Linked List : ";
    while (ptr != NULL){
        cout << ptr -> data << " -> ";
        ptr = ptr -> next;
    }
    if (ptr == NULL){
        cout << "Null";
    }
}

// Search Record for Employee ID
void SearchEmployeeData(Node *ptr, string ID){
    cout << "\nSearching Records ...";

    while (ptr != NULL){
        if ((ptr -> data).substr(1, 6) == ID){
            cout << "\n\nEmployee Found in Records";
            cout << "\nEmployee Data : " << ptr -> data;
            return;
        }
        ptr = ptr -> next;
    }
    cout << "\nEmployee doesn't exist in records !!!";
}

// Delete Employee Record
void DeleteEmployeeRecord(Node *ptr, string ID){
    // Linked List is Empty
    if(ptr == NULL){
        cout << "\nEmployee Linked List is Empty";
        cout << "\nUnderflow Condition, TERMINATION OF PROGRAM";
        exit(0);
    }
    
    // Linked List has only 1 Node
    else if((ptr -> next == NULL) && ((ptr -> data).substr(1, 6) == ID)){
        head = NULL;
        free(ptr);
        return;
    }
    
    else{
        // Deletion at Beginning
        if((ptr -> data).substr(1, 6) == ID){
            head = head -> next;
            free(ptr);
            return;
        }
        
        // Deletion Elsewhere
        while(ptr -> next != NULL){
            if ((ptr -> next -> data).substr(1, 6) == ID){
                Node *prev = ptr;
                ptr = ptr -> next;
                prev -> next = ptr -> next;
                free(ptr);
                return;
            }
            ptr = ptr -> next;
        }
        cout << "Employee doesn't exist in records !!!";
    }
}

// Update Employee Record
void UpdateEmployeeData(Node *ptr, string ID){
    // Linked List is Empty
    if(ptr == NULL){
        cout << "\nEmployee Linked List is Empty";
        return;
    }
    
    // Linked List has only 1 Node
    else if((ptr -> next == NULL) && ((ptr -> data).substr(1, 6) == ID)){
        cout << "\nPrevious Employee Data : " << ptr -> data;
        cout << "\n\nEnter Updated Employee Data : " << endl;
        string UpdationArray[3];
                
        cout << "Employee ID (6-Digit) : ";
        cin >> UpdationArray[0];
        cout << "Employee Name : ";
        cin >> UpdationArray[1];
        cout << "Employee Salary : ";
        cin >> UpdationArray[2];
        
        // Concatenating all Employee Data to a string
        string Updation_String = "[";
        Updation_String.append(UpdationArray[0]);
        Updation_String.append(", ");
        Updation_String.append(UpdationArray[1]);
        Updation_String.append(", ");
        Updation_String.append(UpdationArray[2]);
        Updation_String.append("]");
        
        AddEmployeeData(Updation_String);
        DeleteEmployeeRecord(head, ID);
        cout << "\nUpdation Done !!!";
        return;
    }
    
    else{
        while (ptr -> next != NULL){
            if ((ptr -> next -> data).substr(1, 6) == ID){
                cout << "\nPrevious Employee Data : " << ptr -> next -> data;
                cout << "\n\nEnter Updated Employee Data : " << endl;
                
                string UpdationArray[3];
                    
                cout << "Employee ID (6-Digit) : ";
                cin >> UpdationArray[0];
                cout << "Employee Name : ";
                cin >> UpdationArray[1];
                cout << "Employee Salary : ";
                cin >> UpdationArray[2];
                
                // Concatenating all Employee Data to a string
                string Updation_String = "[";
                Updation_String.append(UpdationArray[0]);
                Updation_String.append(", ");
                Updation_String.append(UpdationArray[1]);
                Updation_String.append(", ");
                Updation_String.append(UpdationArray[2]);
                Updation_String.append("]");
                
                AddEmployeeData(Updation_String);
                DeleteEmployeeRecord(head, ID);
                cout << "\nUpdation Done !!!";
                return;
            }
            ptr = ptr -> next;
        }
        cout << "Employee doesn't exist in records !!!";
    }
}


int main(){
    cout << "\t\t\t\t\t\t\t\t***** Employee Management System *****" << endl;
    
    while(1){
        char Choice;
        cout << "\n\nPress 1 to Add Employee Details";
        cout << "\nPress 2 to Display Employee Details";
        cout << "\nPress 3 to Search Employee Record";
        cout << "\nPress 4 to Update Employee Record";
        cout << "\nPress 5 to Delete Employee Record";
        cout << "\nPress 6 to Exit";
        
        cout << "\n\nUser Choice : ";
        cin >> Choice;
        switch(Choice){
            case '1':
            {
                // To Add Data to Store Employee Details (ID, Name, Salary)
                string Array[3];
                
                cout << "\nEmployee ID (6-Digit) : ";
                cin >> Array[0];
                cout << "Employee Name : ";
                cin >> Array[1];
                cout << "Employee Salary : ";
                cin >> Array[2];
                
                // Concatenating all Employee Data to a string
                string D = "[";
                D.append(Array[0]);
                D.append(", ");
                D.append(Array[1]);
                D.append(", ");
                D.append(Array[2]);
                D.append("]");
                
                AddEmployeeData(D);
                break;
            }
            
            case '2':
            {
                // To Show/Display Employee Details
                cout << "\nEmployee Data : " << endl;
                DisplayEmployeeData(head);
                cout << "\n";
                break;
            }
            
            case '3':
            {
                // To Search for an Employee
                string Emp_ID;
                cout << "\nEmployee ID to be searched for ? ";
                cin >> Emp_ID;
                SearchEmployeeData(head, Emp_ID);
                cout << "\n";
                break;
            }
            
            case '4':
            {
                // To Update Employee Details
                string Emp_ID;
                cout << "\nEmployee ID to be updated ? ";
                cin >> Emp_ID;
                UpdateEmployeeData(head, Emp_ID);
                cout << "\n";
                break;
            }
            
            case '5':
            {
                // To Delete Employee Record
                string Emp_ID;
                cout << "\nEmployee ID to be deleted ? ";
                cin >> Emp_ID;
                DeleteEmployeeRecord(head, Emp_ID);
                cout << "\nDeleting Employee Record...";
                cout << "\nEmployee Record successfully Deleted !";
                cout << "\n";
                break;
            }
            
            case '6':
            {
                cout << "\nThank You :) Have a nice day" << endl;
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