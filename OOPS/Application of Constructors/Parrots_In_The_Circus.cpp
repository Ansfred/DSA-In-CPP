// From a Set of 15 Parrots(Identified by Name, Color), Select 7 Talking Parrots
// Every Talking Parrot is Assigned a Unique Number --> Starting from 7001 (Increment By 1 for every Talking Parrot)
// Use Constructor for Incrementing the Static_Variable of Parrot's Unique Number
// Program to be written using OOPS(Classes, Objects, Constructor)
// Necessary Data of the Parrot to be Displayed --> Name, Type_of_Parrot, Color, Unique_Number (IF_TALKING) {Assume Necessary Data}


#include<iostream>
using namespace std;

class Parrot{
    private:
        static int Unique_Number;                       // Declaring a Static-Variable(Unique_Number)
        
    public:
        string Parrot_Array_Name[15], Parrot_Array_Type[15], Parrot_Array_Color[15];            //Declaring Arrays to store all our Data
        char Parrot_Array_Verbal_Capability[15];
        
        void Get_Parrot_Details(){                                              // Function Created To Accept Data for 15 Parrots and Store it in the Array
            for (int i = 0; i < 15; i++){
                cout << "PARROT " << i + 1 << " DETAILS :-\n\n";
                
                cout << "Parrot Name : ";
                cin >> Parrot_Array_Name[i];
                
                cout << "Parrot Type : ";
                cin >> Parrot_Array_Type[i];
                
                cout << "Parrot Color : ";
                cin >> Parrot_Array_Color[i];
                
                cout << "Verbal Capability('T' for Talking Parrot / 'N' for Non-Talking Parrot) : ";
                cin >> Parrot_Array_Verbal_Capability[i];
                
                cout << "\n\n";
            }
        }
        
        Parrot(){                                               // Created a Constructor & used it to increment the value of Unique_Number whenever an object is Created
            Unique_Number ++;
        };
        
        void Check_And_Display_Talking_Parrot(){                // Checker Function --> Checks whether the Parrot is a Talking Parrot or Not 
            int Talking_Parrot_Count = 0;
            cout << "\n\n\nLIST OF TALKING-PARROTS :-" << endl;
            
            while (Talking_Parrot_Count < 7){                   // Problem Statement says "Circus has 7 Talking Parrots"
                for (int j = 0; j < 15; j++){
                    if (Parrot_Array_Verbal_Capability[j] == 'T'){
                        cout << "Parrot Name : " << Parrot_Array_Name[j] << endl;           // If Parrot is able to TALK, Displays its Details
                        cout << "Parrot Type : " << Parrot_Array_Type[j] << endl;
                        cout << "Parrot Color : " << Parrot_Array_Color[j] << endl;
                        cout << "Unique Number : " << Unique_Number << endl;
                        cout << "\n\n";
                        Parrot Obj;                             // Object created each time we find the particular Parrot is a speaking one --> which inturn activates the Costructor, thereby auto-incrementing the Unique_Number by 1
                        Talking_Parrot_Count ++;
                    }
                }
            }
        }
};

int Parrot :: Unique_Number = 7000;                  // Declared to 7000 & not 7001 because in the main function, we make an object to use our functions, this creation of the object also activates/triggers the constructor which auto-increments the value of Unique_Number which is actually undesirable (therefore, if we would have declared Unique_Number = 7001, our First-Talking Parrot would have got Assigned Unique_Number = 7002 and not 7001)
                                                    // :: --> Scope Resolution Operator
int main(){
    cout << "\t\t\t\t\t\t*****ANIMAL WELFARE TRUST'S VISIT TO THE CIRCUS*****\n\n\n";
    Parrot P;                                       // Creating Object so as to use our Member functions
    P.Get_Parrot_Details();
    P.Check_And_Display_Talking_Parrot();
    return 0;
}



// Data Set For Parrots (ORDER --> Name, Type/Species, Color, Talking/Non-Talking) :D

// 1) Lola, Quaker_Parrot, Green, T 	            --> \/
// 2) Pat, African_Grey_Parrot, Grey, T 	        --> \/
// 3) Rosa, Eclectus_Parrot, Red, T 	            --> \/
// 4) Pepper, Cape_Parrot, Green, N
// 5) Ollie, Senegal_Parrot, Green, N
// 6) Ricky, Golden_Parakeet, Yellow, N
// 7) Ruby, Cockatoo_Parrot, White, T 	            --> \/
// 8) Billy, Burrowing_Parrot, Olive_Green, N
// 9) Alfie, Amazon_Parrot, Green, T 	            --> \/
// 10) Ozzy, Meyer's_Parrot, Brown, N
// 11) Bubba, Golden_Parakeet, Yellow, N
// 12) Rio, African_Grey_Parrot, Grey, T 	        --> \/
// 13) Spike, Cape_Parrot, Green, N
// 14) Pika-Boo, Quaker_Parrot, Green, T 	        --> \/
// 15) Aplha, Burrowing_Parrot, Olive_Green, N