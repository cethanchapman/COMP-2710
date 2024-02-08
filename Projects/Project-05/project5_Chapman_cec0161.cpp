#include <iostream>
using namespace std;

int main(void) {
  const int MAXIMUM_SIZE = 10;
  int tests[MAXIMUM_SIZE];
  int num_elems;
  
  cout << "How many numbers? ";
  cin >> num_elems;
  
  if (num_elems > MAXIMUM_SIZE) {
    cout << "Error: Too many numbers." << endl;
    return 1;
  }
  
  for (int i = 0; i < num_elems; i++) {
    cout << "Please type a number: ";
    cin >> tests[i];
  }
  
  return 0;
}
