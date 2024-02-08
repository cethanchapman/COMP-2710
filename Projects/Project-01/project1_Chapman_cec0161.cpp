/*  FILE NAME: project1_Chapman_cec0161
 *  AUTHOR: Ethan Chapman 
 *  Description: simple c++ program that tells the user how many months 
 *      it will take to pay off a loan
 *  Compile: g++ project1_Chapman_cec0161.cpp
 *  Run: ./a.out
 * 
 * 
 * Sources: I used the hints file in canvas
 * 
 * I used stackoverflow.com pages about if/else statements and while loops.
 * 
 * I used multiple Kindson the Tech Pro YouTube tutorials 
 * 
 * I talked with Miller Kleckly about If/Else statements
 * 
 * I talked with Jack Ryan Fulford (took the course previously) 
 *      to help with formatting and calculation code
 *  Recieved help from Ben Buchannon to upload code to server and deal 
 *      with errors displayed in terminal.
 * 
 *  
 */ 

#include <iostream>
using namespace std;

int main() {
    // variable initialization

    double loan = 0;
    double interestRate = 0;
    double interestRateC = 0;
    double monthlyPaid = 0;
    int currentMonth = 0;
    double interestTotal = 0;
    double monthlyInterest = 0;
    double principal = 0;
    

   // currency formatting
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

// user input
// input for loan, interest, and monthly payment must be
// positive numbers. Monthly payment must also be large enough
// to terminate the loan.

cout<<"\nLoan Amount: ";
cin>> loan;

while (loan <= 0) {
    cout<<"\nPlease enter a positive loan amount.";
    cin>> loan;

}

cout<<"Interest Rate (% per year): ";
cin>> interestRate;

while (interestRate < 0) {
    cout<<"Please enter a positive interest rate amount.";
    cin>> interestRate;

}
// get proper interest rates for calculations
interestRate /= 12;
interestRateC = interestRate / 100;

do {
    cout<<"Monthly Payment: ";
    cin>> monthlyPaid; 
    if (monthlyPaid <= (interestRateC * loan)) {
        cout<<"Please enter a sufficient monthly payment: ";

    }

}
while (monthlyPaid < (interestRateC * loan));

cout << endl;

//amortization table
cout << "*****************************************************************\n" 
     << "\tAmortization Table\n" 
     << "*****************************************************************\n" 
     << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n"; 

//loop to fill the table
while (loan > 0) {
    if (currentMonth == 0) {
        cout<< currentMonth++ << "\t$" << loan;
    if (loan < 1000) cout << "\t"; // Formatting MAGIC
        cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
    
    }
    
    else {
        monthlyInterest = loan * interestRateC;
        interestTotal += monthlyInterest;

        //check to see if loan is paid off
        loan = (loan *(1 + interestRateC)) - monthlyPaid;
        if (loan < 0) {
            monthlyPaid += loan;
            loan = 0;
        }
        // formatting statement
        if (loan < 1000) {
            cout<< currentMonth++ << "\t$" << loan << "\t\t" << monthlyPaid << "\t"
                << interestRate << "\t" << monthlyInterest << "\t\t" << principal << "\n";
        
        }
        else {
            cout<< currentMonth++ << "\t$" << loan << "\t" << monthlyPaid << "\t"
                << interestRate << "\t" << monthlyInterest << "\t\t" << principal << "\n";
        }

    
    }
    
}
cout << "****************************************************************\n";
cout << "\nIt takes " << --currentMonth << " months to pay off "
     << "the loan.\n"
     << "Total interest paid is: $" << interestTotal;
cout << endl << endl;
return 0;

}
