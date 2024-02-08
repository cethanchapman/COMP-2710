/*
* File Name: project2_Chapman_cec0161.cpp
* Author: Ethan Chapman
*
*  project 2. Program for a duel simmulator game
*  Compile: g++ project2_Chapman_cec0161.cpp
* Run : ./a.out
*
* Sources: Hints file from canvas
*
* I used a geeksforgeeks.com article about assertions.
* I used a Code Morsels YouTube tutorial about creating unit tests
*  
* Talked with Jack Ryan Fulford about creating constant variables and 
*   formatting my code.
*
* Talked with Miller Kleckley about assertion statments.
*/

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>

using namespace std;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);

void Aaron_shoots1(bool& B_alive, bool& C_alive);

void Bob_shoots(bool& A_alive, bool& C_alive);

void Charlie_shoots(bool& A_alive, bool& B_alive);

void Aaron_shoots2(bool& B_alive, bool& C_alive);

//Simple method to implement pause function in linux 
void Press_any_key(void); 
 
//TEST PROTOTYPES 
void test_at_least_two_alive(void); 
void test_Aaron_shoots1(void); 
void test_Bob_shoots(void); 
void test_Charlie_shoots(void); 
void test_Aaron_shoots2(void); 

//VARIABLES 
const int TOTAL_RUNS = 10000;
const int AARON_ACCURACY = 100/3;
const int BOB_ACCURACY = 100/2;

int aaronWins1 = 0;
int aaronWins2 = 0;
int bobWins = 0;
int charlieWins = 0;

bool A_alive = true;
bool B_alive = true;
bool C_alive = true;


//.............

int main() {
// initializes Random number generator's seed and calls test functions 
    cout<<"***Welcome to Ethan's duel simmulator***\n";
    srand(time(0));
    test_at_least_two_alive();

    Press_any_key();

    test_Aaron_shoots1();

    Press_any_key();

    test_Bob_shoots();

    Press_any_key();

    test_Charlie_shoots();

    Press_any_key();

    test_Aaron_shoots2();

    Press_any_key();

    // starts strategy 1 and runs 10000 times

    cout<<"Ready to test strategy 1 (run 10000 times):\n";

    Press_any_key();

    for (int i=0; i < TOTAL_RUNS; i++) {
        //initialize as alive
        A_alive = true;
        B_alive = true;
        C_alive = true;

        while (at_least_two_alive(A_alive, B_alive, C_alive)) {
            
            if (A_alive) {
                Aaron_shoots1(B_alive, C_alive);
            }
            if (B_alive) {
                Bob_shoots(A_alive, C_alive);
            }
            if (C_alive) {
                Charlie_shoots(A_alive, B_alive);
            }

        }
        if (A_alive) {
            aaronWins1++;
        }
        else if (B_alive) {
            bobWins++;
        }
        else  {
            charlieWins++;
        }
    }
        
    cout<<"Aaron won "<< aaronWins1 <<"/10000 duels or " <<static_cast<double>(aaronWins1)/
        TOTAL_RUNS * 100 <<"%\n"

        <<"Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS 
        * 100 << "%\n"

        << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / 
        TOTAL_RUNS * 100 << "%\n"

        <<endl;
        
    
    // reinstates variable and starts strategy 2 and runs 10000 times

    bobWins = 0;
    charlieWins = 0;

    cout<<"Ready to test strategy 2 (run 10000 times):\n";

        Press_any_key();

        for (int i=0; i < TOTAL_RUNS; i++) {
            //initialize as alive
            A_alive = true;
            B_alive = true;
            C_alive = true;

            while (at_least_two_alive(A_alive, B_alive, C_alive)) {
            
                if (A_alive) {
                    Aaron_shoots2(B_alive, C_alive);
                }
                if (B_alive) {
                    Bob_shoots(A_alive, C_alive);
                }
                if (C_alive) {
                    Charlie_shoots(A_alive, B_alive);
                }

            }
            if (A_alive) {
                aaronWins2++;
            }
            if (B_alive) {
                bobWins++;
            }
            if (C_alive) {
                charlieWins++;
            }
        }
        
        cout<<"Aaron won "<< aaronWins2 <<"/10000 duels or " <<static_cast<double>(aaronWins1)/
            TOTAL_RUNS * 100 <<"%\n"

            <<"Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS 
                * 100 << "%\n"

            << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / 
                TOTAL_RUNS * 100 << "%\n"

        <<endl;
        
    
    
            if (aaronWins1 > aaronWins2) {
                cout<<"Strategy 1 is better than strategy 2.\n";

            }
            else {
                cout<<"Strategy 2 is better than strategy 1. \n";

            }
    return 0;

}


//Implementation of functions. Look above for documentation of them.

//checks at least 2 are alive
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
    return (A_alive && B_alive || B_alive && C_alive || C_alive && A_alive);

}

//----------------------------------------------------------------------
void test_at_least_two_alive(void) {
    cout<<"Unit Testing 1: Function - at_least_two_alive()\n";

    cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n"; 
    A_alive = true;
    B_alive = true;
    C_alive = true;
    assert(true == at_least_two_alive(A_alive, B_alive, C_alive));
    cout<<"\tCase Passed ...\n";


    cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
    A_alive = false;
    B_alive = true;
    C_alive = true;
    assert(true == at_least_two_alive(A_alive, B_alive, C_alive));
    cout << "\tCase Passed ...\n";

    cout <<"\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
    A_alive = true;
    B_alive = false;
    C_alive = true;
    assert(true == at_least_two_alive(A_alive, B_alive, C_alive));
    cout << "\tCase Passed ...\n";

    cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
    A_alive = true;
    B_alive = true;
    C_alive = false;
    assert(true == at_least_two_alive(A_alive, B_alive, C_alive));
    cout << "\tCase Passed ...\n";

    cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
    A_alive = false;
    B_alive = false;
    C_alive = true;
    assert(false == at_least_two_alive(A_alive, B_alive, C_alive));
    cout << "\tCase Passed ...\n";

    cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
    A_alive = false;
    B_alive = true;
    C_alive = false;
    assert(false == at_least_two_alive(A_alive, B_alive, C_alive));
    cout << "\tCase Passed ...\n";

    cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
    A_alive = true;
    B_alive = false;
    C_alive = false;
    assert(false == at_least_two_alive(A_alive, B_alive, C_alive));
    cout << "\tCase Passed ...\n";

    cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
    A_alive = false;
    B_alive = false;
    C_alive = false;
    assert(false == at_least_two_alive(A_alive, B_alive, C_alive));
    cout << "\tCase Passed ...\n";
}
void Aaron_shoots1(bool& B_alive, bool& C_alive) {
   //assert(A_alive == true);
    int shootResult = rand() % 100;
    if (C_alive) {
        if (shootResult <= AARON_ACCURACY) {
            C_alive = false;

        }
    }
    else {
        if (shootResult <= AARON_ACCURACY) {
            B_alive = false;
        }
    }

}
void test_Aaron_shoots1(void) {
    cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n"; 
    B_alive = true;
    C_alive = true;

    cout << "\tCase 1: Bob alive, Charlie alive\n"
        << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots1(B_alive, C_alive);

    B_alive = false;
    C_alive = true;
    
    cout << "\tCase 2: Bob dead, Charlie alive\n"
        << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots1(B_alive, C_alive);

    B_alive = true;
    C_alive = true;
    
    cout << "\tCase 3: Bob alive, Charlie dead\n"
        << "\t\tAaron is shooting at Bob\n";
    Aaron_shoots1(B_alive, C_alive);

}
void Bob_shoots(bool& A_alive, bool& C_alive) {
    //assert(B_alive == true);

    int shootResult = rand() % 100;

    if (C_alive) {
        if (shootResult <= BOB_ACCURACY) {
            C_alive = false;
        }
    }        
    else {
        if (shootResult <= BOB_ACCURACY) {
            A_alive = false;
        }
    }
    
}
void test_Bob_shoots(void) {
    cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
    A_alive = true;
    C_alive = true;

    cout << "\tCase 1: Aaron alive, Charlie alive\n"
        << "\t\tBob is shooting at Charlie\n";
    Bob_shoots(A_alive, C_alive);

    A_alive = false;
    C_alive = true;

    cout << "\tCase 2: Aaron dead, Charlie alive\n"
        << "\t\tBob is shooting at Charlie\n";
    Bob_shoots(A_alive, C_alive);

    A_alive = true;
    C_alive = false;

    cout << "\tCase 3: Aaron alive, Charlie dead\n"
        << "\t\tBob is shooting at Aaron\n";
    Bob_shoots(A_alive, C_alive);

}
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
    // this statement ensures Aaron will miss his first shot
    if (B_alive && C_alive) {
        return;

    }

    int shootResult = rand() % 100;

    if (B_alive) {
        if (shootResult <= AARON_ACCURACY) {
            B_alive = false;
        }
    }
    else {
        if (shootResult <= AARON_ACCURACY) {
            C_alive = false;
        }
    }
}

void test_Aaron_shoots2(void) {

    cout << "Unit testing 5: Function Aaron_Shoots2(Bob_alive, Charlie_alive)\n";

    B_alive = true;
    C_alive = true;

    cout << "\tCase 1: Bob alive, Charlie alive\n"
        << "\t\tAaron intentionally misses his first shot\n"
        << "\t\tBoth Bob and Charlie are alive.\n";

    Aaron_shoots2(B_alive, C_alive);
    
    B_alive = false;
    C_alive = true;

    cout << "\tCase 2: Bob dead, Charlie alive\n"
        << "\t\tAaron is shooting at Charlie\n";
    
    Aaron_shoots2(B_alive, C_alive);

    B_alive = true;
    C_alive = false;

    cout << "\tCase 3: Bob alive, Charlie dead\n"
        << "\t\tAaron is shooting at Bob\n";
    
    Aaron_shoots2(B_alive, C_alive);


}
void Charlie_shoots(bool& A_alive, bool& B_alive) {
    if (B_alive) {
        B_alive = false;
    }
    else {
        A_alive = false;
    }
}
void test_Charlie_shoots(void) {
    cout << "Unit testing 4: function Charlie_shoots(Aaron_alive, Bob_alive)\n";

    A_alive = true;
    B_alive = true;

    cout << "\tCase 1: Aaron alive, Bob alive\n"
        << "\t\tCharlie is shooting at Bob\n";

    Charlie_shoots(A_alive, B_alive);

    A_alive = true;
    B_alive = false;

    cout << "\tCase 2: Aaron dead, Bob alive\n"
        << "\t\tCharlie is shooting at Bob\n";

    Charlie_shoots(A_alive, B_alive);

    A_alive = false;
    B_alive = true;

    cout << "\tCase 3: Aaron alive, Bob dead\n"
        << "\t\tCharlie is shooting at Aaron\n";
    
    Charlie_shoots(A_alive, B_alive);
}

void Press_any_key(void) {
    cout << "Press any key to continue...";
    cin.ignore().get(); 

}
