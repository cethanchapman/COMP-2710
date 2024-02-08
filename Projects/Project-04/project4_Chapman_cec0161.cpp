/*
* Name: project4_Chapman_cec0161.cpp
* Author: Ethan Chapman
* Trivia game with nodes as structures
*
*   compile: g++ project4_Chapman_cec0161.cpp -std=c++11
*
*  Sources used: Hints pdf
*  geeksForGeeks page about adding nodes to a list and counting number of nodes.
*  worked with Jack Ryan Fulford to discuss the way nodes must be formatted.
* used https://www.codesdope.com/blog/article/c-linked-lists-in-c-singly-linked-list/#:~:text=The%20first%20part%20is%20to,required%20for%20a%20linked%20list.
*   to learn about creating linked lists.
* Talked to Miller Kleckley about creating singly linked lists.
*
*
*/


#include <iostream>
#include <string>

using namespace std;

//creates a linked list that holds trivia question, answer, and point amount.
int num_of_questions = 0;

struct trivia_node {
    string question;
    string answer;
    int point;
    trivia_node *next;

};
// creates pointer to trivia node

typedef trivia_node* ptr_node;

//prototypes
void init_question_list(ptr_node& q_list); 
void add_question(ptr_node& q_list); 
int ask_question(ptr_node q_list, int num_ask); 
void Unit_Test();





//creates 2 versions
//#define UNIT_TESTING

#define trivia_quiz

int main() {
    Unit_Test();
    
    //creates new trivia game
    //sets up 3 questions
    //sets up loop for user input questions
    //quiz questions stored in linked list
#ifdef trivia_quiz
	ptr_node node_list = new trivia_node;
	init_question_list(node_list);


	cout << "*** Welcome to Ethan's trivia quiz game ***\n";
	string input;
	bool keep_going = true;
	
    while(keep_going) {
		
        add_question(node_list);
		cout << "Continue adding questions? (Yes/No): ";
		getline(cin, input);
		if (input.compare("YES") == 0 || input.compare("Yes") == 0 || input.compare("yes") == 0) {
			keep_going = true;
		} 
        
        else {
			keep_going = false;
		}
	} 
	cout << "\n";

	//Start of the trivia quiz game
	ask_question(node_list, num_of_questions);
	cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***\n";
	return 0;
}
#endif

//Method For testing

#ifdef UNIT_TESTNG
    Unit_test();
    return 0;
    }
#endif

//initializes the quiz to have these three questions inputted into the linked list.

void init_question_list(ptr_node& q_list) {
    //ptr_node cur_ptr;
    //ptr_node cur_ptr;
    string bob;
    ptr_node cur_ptr = new trivia_node;
    cur_ptr->question = "How long was the shortest war on record? (Hint: how many minutes)";
    cur_ptr->answer = "38";
    cur_ptr->point = 100;
    cur_ptr->next = new trivia_node;

    q_list = cur_ptr;
    cur_ptr = q_list->next;

    cur_ptr->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
	cur_ptr->answer = "Bank of Italy";
	cur_ptr->point = 50;
	cur_ptr->next = new trivia_node;
	cur_ptr = cur_ptr->next;

    cur_ptr->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
	cur_ptr->answer = "Wii Sports";
	cur_ptr->point = 20;
	cur_ptr->next = NULL;

	num_of_questions += 3;
}




//gives user the option to add a question to the linked list.
//question is added to the front of the linked list.
void add_question(ptr_node& q_list) {
    
    ptr_node new_ptr = new trivia_node;
    //gets data from user.
    cout << "Enter a new question: ";
    getline(cin, new_ptr->question);
    cout << "Enter an answer: ";
	getline(cin, new_ptr->answer);
	cout << "Enter award points: ";
	cin >> new_ptr->point;
	cin.ignore(); // ignores '\n' character that gives tons of problems with input
	new_ptr->next = NULL; // this is needed to add at the end of the list

	// Add to the end of the list
	trivia_node* last = q_list;
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_ptr;

	// Add to the beginning of the list
	//new_ptr->next = q_list;
	//q_list = new_ptr;

	num_of_questions++;
}


//Checks for null value
//Ask the user trivia questions and starts the game
int ask_question(ptr_node q_list, int num_ask) {

    ptr_node cur_ptr = q_list;
    string answer;
    int total_points = 0;


    if (q_list == NULL) {
        return 0;
    }
    
    if(num_ask <= 1) {
        cout << "Warning - the number of trivia to be asked must equal to or be larger than 1." << endl;
        return 1;
    }   
    
    else if(num_of_questions < num_ask) {
        cout << "Warning - There is only " << num_of_questions << " trivia in the list." << endl;
        return 1;
    }
    
    else {
        
        for(int x = 0; x < num_ask; x++) {
            cout << "Question: " << cur_ptr->question << endl;
            cout << "Answer: ";
            getline(cin, answer);
            
            if (answer.compare(cur_ptr->answer) == 0) {//correct_answer) {
                cout << "Your answer is correct. You receive " << cur_ptr->point << " points." << endl;
				total_points += cur_ptr->point;
            }
            
            else {
                cout << "Your answer is wrong. The correct answer is: " << cur_ptr->answer << endl;
            }
            
            cout << "Your total points: " << total_points << endl << endl;

			// Debugging '\n'
			//cout << answer << "    " << cur_ptr->answer << endl;

			cur_ptr = cur_ptr->next;
		}
	}

    return 0;
}
//Test cases to check whether the methods work.
void Unit_Test() {
    
    cout << "*** This is a debugging version ***\n";
    
    ptr_node node_list = new trivia_node;
    init_question_list(node_list);
    
    cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
    ask_question(node_list, 0);
    cout << "Case 1 Passed\n\n";
    
    cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
    ask_question(node_list, 1);
    cout << "Case 2.1 passed\n\n";
    
    cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
    ask_question(node_list, 1);
    cout << "Case 2.2 passed\n\n";
    
    cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list." << endl;
    ask_question(node_list, 3);
    cout << "Case 3 passed\n\n";

    cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
    ask_question(node_list, 5);
    cout << "Case 4 passed\n\n";
    
    cout << "\n\n*** End of the Debugging Version ***";


}
