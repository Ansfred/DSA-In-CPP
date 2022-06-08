#include <iostream>
using namespace std;

class Employee{
    private:
        struct Emp {
            string Emp_ID, Emp_Name, Emp_DOB, Emp_Address;
            double Emp_Salary;
            long long Emp_Phone;
        };
    
    public:
        Emp Emp_Array[15];                  // Declaration of Array in Global Scope
        int Total = 0;                      // Declaration of Variable in Global Scope --> Keeps a Track/Counter of the Total Number of Students
        
        void Add_Emp_Details() {
            int Number;
            cout << "How many Employees Data is to be Added ? ";
            cin >> Number;
            
            for (int i = Total; i < Total + Number; i++){                   // Important Step : It Prohibits Over-Writing of Data
                cout << "\nEnter Data for Employee " << i + 1 << endl;
                cout << "\n";
            
                cout << "Employee ID : ";
                cin >> Emp_Array[i].Emp_ID;                                 // Adding Employee Details To the Array
            
                cout << "Employee Name : ";
                cin >> Emp_Array[i].Emp_Name;
                
                cout << "Employee Salary : ";
                cin >> Emp_Array[i].Emp_Salary;
                if (Emp_Array[i].Emp_Salary <= 0) {
                    cout << "Invalid Salary (Salary cannot be 0 or -ve) ! Please Re-Enter Inputs !";
                    cout << "\nEmployee Salary : ";
                    cin >> Emp_Array[i].Emp_Salary;
                }
                
                cout << "Employee Phone_Number : ";
                cin >> Emp_Array[i].Emp_Phone;
                if ((Emp_Array[i].Emp_Phone < 1000000000) || (Emp_Array[i].Emp_Phone > 9999999999)){
                    cout << "Invalid Phone_Number (Phone_Number -> 10 Digits) ! Please Re-Enter Inputs !";
                    cout << "\nEmployee Phone_Number : ";
                    cin >> Emp_Array[i].Emp_Phone;
                }
                
                cout << "Employee DOB in DD/MM/YYYY Format : ";
                cin >> Emp_Array[i].Emp_DOB;
                
                cout << "Employee Address : ";
                cin >> Emp_Array[i].Emp_Address;
                }
                
                cout << "\n\n";
                
            Total += Number;
        }
        
        void Show_Emp_Details() {
            if (Total != 0){
                for (int i = 0; i < Total; i++){                // Reason Why We Use Total Variable
                    cout << "\nData Of Employee " << i + 1 << endl;
                    cout << "\nEmployee ID : " << Emp_Array[i].Emp_ID << endl;
                    cout << "Employee Name : " << Emp_Array[i].Emp_Name << endl;
                    cout << "Employee Salary : " << Emp_Array[i].Emp_Salary << endl;
                    cout << "Employee Phone_Number : " << Emp_Array[i].Emp_Phone << endl;
                    cout << "Employee DOB in DD/MM/YYYY Format : " << Emp_Array[i].Emp_DOB << endl;
                    cout << "Employee Address : " << Emp_Array[i].Emp_Address << endl;
                    cout << "\n\n";
                }
            }
            
            else{
                cout << "Employee Record List is Empty !!!\n" << endl;
            }
        }
        
        void Search_Emp_Details() {
            if (Total != 0){
                string ID;
                cout << "Enter Employee ID to be Searched : ";
                cin >> ID;
                
                for (int i = 0; i < Total; i++){
                    if (ID == Emp_Array[i].Emp_ID){
                        cout << "\nEmployee Found in Records..." << endl;
                        cout << "\nData Of Employee " << i + 1 << endl;
                        cout << "\nEmployee ID : " << Emp_Array[i].Emp_ID << endl;
                        cout << "Employee Name : " << Emp_Array[i].Emp_Name << endl;
                        cout << "Employee Salary : " << Emp_Array[i].Emp_Salary << endl;
                        cout << "Employee Phone_Number : " << Emp_Array[i].Emp_Phone << endl;
                        cout << "Employee DOB in DD/MM/YYYY Format : " << Emp_Array[i].Emp_DOB << endl;
                        cout << "Employee Address : " << Emp_Array[i].Emp_Address << endl;
                        cout << "\n\n";
                        break;
                    }
                    if(i == Total - 1){            // Condition To Check, whether we reached End of our Array & still haven't found the data required
                        cout << "\n Employee Doesn't Exist in Records !!!" << endl;
                    }
                }
            }
            else{
                cout << "Employee Record List is Empty !!!\n" << endl;
            }
        }
        
        void Update_Emp_Details() {
            if (Total != 0){
                string ID;
                cout << "Enter Employee ID to be Updated : ";
                cin >> ID;
        
                for (int i = 0; i < Total; i++){
                    if (ID == Emp_Array[i].Emp_ID){
                        cout << "\n\nPrevious Record : " << endl;
                        cout << "\nData Of Employee " << i + 1 << endl;
                        cout << "\nEmployee ID : " << Emp_Array[i].Emp_ID << endl;
                        cout << "Employee Name : " << Emp_Array[i].Emp_Name << endl;
                        cout << "Employee Salary : " << Emp_Array[i].Emp_Salary << endl;
                        cout << "Employee Phone_Number : " << Emp_Array[i].Emp_Phone << endl;
                        cout << "Employee DOB in DD/MM/YYYY Format : " << Emp_Array[i].Emp_DOB << endl;
                        cout << "Employee Address : " << Emp_Array[i].Emp_Address << endl;
                        cout << "\n\n";
                        
                        cout << "Enter New Data : " << endl;
                        cout << "Employee ID : ";
                        cin >> Emp_Array[i].Emp_ID;                                 // Adding Employee Details To the Array
                    
                        cout << "Employee Name : ";
                        cin >> Emp_Array[i].Emp_Name;
                        
                        cout << "Employee Salary : ";
                        cin >> Emp_Array[i].Emp_Salary;
                        if (Emp_Array[i].Emp_Salary <= 0) {
                            cout << "Invalid Salary (Salary cannot be 0 or -ve) ! Please Re-Enter Inputs !";
                            cout << "\nEmployee Salary : ";
                            cin >> Emp_Array[i].Emp_Salary;
                        }
                        
                        cout << "Employee Phone_Number : ";
                        cin >> Emp_Array[i].Emp_Phone;
                        if ((Emp_Array[i].Emp_Phone < 1000000000) || (Emp_Array[i].Emp_Phone > 9999999999)){
                            cout << "Invalid Phone_Number (Phone_Number -> 10 Digits) ! Please Re-Enter Inputs !";
                            cout << "\nEmployee Phone_Number : ";
                            cin >> Emp_Array[i].Emp_Phone;
                        }
                        
                        cout << "Employee DOB in DD/MM/YYYY Format : ";
                        cin >> Emp_Array[i].Emp_DOB;
                        
                        cout << "Employee Address : ";
                        cin >> Emp_Array[i].Emp_Address;
                        
                        cout << "\n\n";
                        break;
                    }
                    
                    if (i == Total - 1){            // Condition To Check, whether we reached End of our Array & still haven't found the data required
                        cout << "\n Employee Doesn't Exist in Records !!!" << endl;
                    }
                }
            }
            else{
                cout << "Employee Record List is Empty !!!\n" << endl;
            }
        }
        
        void Delete_Emp_Details() {
            if (Total != 0){
                string ID;
                cout << "Enter Employee ID to be Deleted : ";
                cin >> ID;
                
                for (int i = 0; i < Total; i++){
                    if (ID == Emp_Array[i].Emp_ID){
                        for (int j = i; j < Total; j++){            // Making Changes Only After the Data Matches & the changes made are only on the following Data, No overwriting Should be done on the preceding Data
                            Emp_Array[j].Emp_ID = Emp_Array[j + 1].Emp_ID;          //Copy The Next Data in the Memory onto the Current One, thereby Deleting the Current Data and Successfully Unaltering the Sequence of Our Data
                            Emp_Array[j].Emp_Name = Emp_Array[j + 1].Emp_Name;
                            Emp_Array[j].Emp_Salary = Emp_Array[j + 1].Emp_Salary;
                            Emp_Array[j].Emp_Phone = Emp_Array[j + 1].Emp_Phone;
                            Emp_Array[j].Emp_DOB = Emp_Array[j + 1].Emp_DOB;
                            Emp_Array[j].Emp_Address = Emp_Array[j + 1].Emp_Address;
                            Total --;       //As the Last Memory Location gets Freed Up
                            break;
                        }
                        cout << "\nEmployee Record Deleted !!!\n\n" << endl;
                    }
                    if (i == Total - 1){            // Condition To Check, whether we reached End of our Array & still haven't found the data required
                        cout << "\n Employee Doesn't Exist in Records !!!\n" << endl;
                    }
                }
            }
            else{
                cout << "\nEmployee Record List is Empty !!!\n" << endl;
            }
        }
};


int main()
{
    cout << "\t\t\t\t\t\t\t*****EMPLOYEE MANAGEMENT SYSTEM*****\n\n";
    cout << "NOTE - Restrict Maximum Number of Employees to 15 !\n\n";
    char User_Choice;
    Employee E;         //Creating Object(E) of Our Class(Employee)
    
    while(1){
        cout << "Press 1 to Enter New Record" << endl;
        cout << "Press 2 to Display All Records" << endl;
        cout << "Press 3 to Search for Record" << endl;
        cout << "Press 4 to Update Record" << endl;
        cout << "Press 5 to Delete Record" << endl;
        cout << "Press 6 to Exit" << endl;
        
        cout << "\nUser's Choice : ";
        cin >> User_Choice;
        switch (User_Choice){
            case '1':
                E.Add_Emp_Details();
                break;
                
            case '2':
                E.Show_Emp_Details();
                break;
                
            case '3':
                E.Search_Emp_Details();
                break;
                
            case '4':
                E.Update_Emp_Details();
                break;
            
            case '5':
                E.Delete_Emp_Details();
                break;
                
            case '6':
                cout << "\n\nTHANK YOU :) Have A Great Day :D";
                exit(0);
                
            default:
                cout << "Invalid Input" << endl;
                break;
        }
    }
    return 0;
}