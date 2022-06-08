// Order of Operation :- 1) Parenthesis 2) Exponents {Right -> Left} 3) Multiplication & Division {Left -> Right} 4) Addition & Subtraction {Left -> Right}
// Operator Associativity :- Left -> Right : Left Associative & Right -> Left : Right Associative

// While Solving :- 1) Check Precednce of Operators 2) Associativity
// Infix : 2 + 3 ----> Prefix : + 2 3
// Infix : 2 + 3 ----> Postfix : 2 3 + (Least Costliest to Parse AND Least Costly in Time & Memory)


// C++ Implementation to Convert Infix Expression to Postfix & Prefix

#include <bits/stdc++.h>                                     // Header File that Includes Every Standard Library of C++
using namespace std;

// Function Returns Precedence of Operators
int Precedence_Checker(char c) {
	if(c == '^') {
		return 3;
	}
	
	else if(c == '/' || c == '*') {             // Equal Precedence
		return 2;
	}
	
	else if(c == '+' || c == '-') {             // Equal Precedence
		return 1;
	}
	
	else {                                                    // Not a Valid Operator
		return -1;
	}
}

// Main Driver Function for Infix -> Postfix
string Infix_To_Postfix(string expressionString) {
    stack<char> operatorStack;                                // For Stack Operations, we are using C++ Built in Stack (<bits/stdc++.h>)
    string resultString;

	for(int i = 0; i < expressionString.length(); i++) {
		char c = expressionString[i];

		// If Operand, directly add to ResultString
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
			resultString += c;
		}
		
		// If ‘(‘, PUSH to operatorStack
		else if(c == '(') {
			operatorStack.push('(');
		}
		
		// If ‘)’, keep POPPING Characters to ResultString, Until an ‘(‘ is encountered.
		else if(c == ')') {
			while(operatorStack.top() != '(')
			{
				resultString += operatorStack.top();
				operatorStack.pop();
			}
			operatorStack.pop();
		}

		// If Operator
		else {
			while(!operatorStack.empty() && Precedence_Checker(expressionString[i]) <= Precedence_Checker(operatorStack.top())) {
				resultString += operatorStack.top();
				operatorStack.pop();
			}
			operatorStack.push(c);
		}
	}


	// Reaching End of expressionString
	while(!operatorStack.empty()) {
		resultString += operatorStack.top();
		operatorStack.pop();
	}
    return resultString;
}

// Main Driver Function for Infix -> Prefix
string Infix_To_Prefix(string expressionString)
{
    stack<char> operatorStack;                                // For Stack Operations, we are using C++ Built in Stack (<bits/stdc++.h>)
    reverse(expressionString.begin(), expressionString.end());

    for (int i = 0; i < expressionString.size(); i++) {
        if (expressionString[i] == '(') {
            expressionString[i] = ')';
            i ++;
        }
        else if (expressionString[i] == ')') {
            expressionString[i] = '(';
            i++;
        }
    }
 
    string resultString = Infix_To_Postfix(expressionString);
 
    // Reverse Postfix
    reverse(expressionString.begin(), expressionString.end());

    reverse(resultString.begin(), resultString.end());
    return resultString;
}


// Main Function
int main() {
	string userInput;
	cout << "User Please Enter Infix Expression : ";
	cin >> userInput;
	
	while(1){
        char Choice;
        cout << "\n\nPress 1 for Infix to Postfix";
        cout << "\nPress 2 for Infix to Prefix";
        cout << "\nPress 3 to Exit";
        
        cout << "\n\nUser Choice : ";
        cin >> Choice;
        switch(Choice){
            case '1':
            {
            	cout << "\nPostfix String : " << Infix_To_Postfix(userInput) << endl; 
                break;
            }
            
            case '2':
            {
                cout << "\nPrefix String : " << Infix_To_Prefix(userInput) << endl;
                break;
            }
            
            case '3':
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

// (a+b)-(c*d)+(g^f)
// Postfix expression: ab+cd*-gf^+
// Prefix expression: -+ab+*cd^gf
