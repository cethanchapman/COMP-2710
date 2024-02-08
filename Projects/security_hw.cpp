#include <iostream>
using namespace std;
    int main(void)
    {
        int tests[10];
        int test;
        int num_elems;

        cout << "How many numbers?: ";
        cin >> num_elems;

        for (int i =0; i < num_elems; i++)
            {
                cout << "Please type a number: ";
                cin >> test;
                tests[i] =  test;

            }
        return 0;

    }
