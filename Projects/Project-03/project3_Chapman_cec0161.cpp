/* FILE NAME: project3_Chapman_cec0161
*  AUTHOR: Ethan Chapman 
*  Description: simple c++ program that takes two input files and sorts the
*      numbers in the files. The program then prints an output file with the result.
*  Compile: g++ project3_Chapman_cec0161.cpp
*  Run: ./a.out
* 
* 
* Sources: I used the hints file in canvas
* 
* I used stackoverflow.com pages about while statements.
* 
* I used multiple Kindson the Tech Pro YouTube tutorials 
* 
* I talked with Miller Kleckly about streams and arrays.
* 
* I talked with Jack Ryan Fulford (took the course previously) 
*      to help with formatting and global variables in my code.
*  Used a stackoverflow.com page on streams and file I/O
* 
*  
*/ 



#include<iostream>
#include<fstream>
#include<string>

using namespace std; 

const int MAX_SIZE = 500;

int readFile(int inputArray[], ifstream& instream);
int mergeFile(int inputArray1[], int inputArraySize1, int inputArray2[], int inputArraySize2, int outputArray[]);
void writeFile(ofstream& outStream, int outputArray[], int outputArraySize);
void toString(int array[], int size, char separator); 
bool checkFile(string filename);

int main(int argc, char const *argv[]) {

    ifstream inStream;
    ofstream outStream;
    int inArray1[MAX_SIZE];
    int inArraySize1;
    int inArray2[MAX_SIZE];
    int inArraySize2;
    int outArray[MAX_SIZE*2];
    int outArraySize;


    cout << "*** Welcome to Ethan's sorting program ***" << endl;
    string filename;

    cout << "Enter the first input file name: ";
    cin >> filename;
    while (cin.fail() || !checkFile(filename)) {
        cout << "Input file opening failed, try again: ";
        cin >> filename;

    }
    inStream.open(filename.c_str());
    inArraySize1 = readFile(inArray1, inStream);
    inStream.close();
    cout << "The list of "<< inArraySize1 <<" numbers in file "  << filename << " is: " << endl;
    toString(inArray1, inArraySize1, '\n');
    cout << endl;

    cout << "Enter the second input file name: ";
    cin >> filename;
    while (cin.fail() || !checkFile(filename)) {
        cout << "Input file opening failed, try again: ";
        cin >> filename;
    }
    inStream.open(filename.c_str());
    inArraySize2 = readFile(inArray2, inStream);
    inStream.close();
    cout << "The list of "<< inArraySize2 <<" numbers in file "  << filename << " is: " << endl;
    toString(inArray2, inArraySize2, '\n');
    cout << endl;



    outArraySize = mergeFile(inArray1, inArraySize1, inArray2, inArraySize2, outArray);
    cout << "The sorted list of "<< outArraySize << " numbers is: ";
    toString(outArray, outArraySize, ' ');

    string out_filename;
    cout << "\nEnter the output file name: ";
    cin >> out_filename;

    outStream.open(out_filename.c_str());
    writeFile(outStream, outArray, outArraySize);
    outStream.close();

    cout << "*** Please check the new file - " << out_filename << " ***\n*** Goodbye. *** ";
    return 0;

}

int readFile(int input_array[], ifstream& instream) {
    int index = 0;

    instream >> input_array[index];
    while (!instream.eof()) {
        index++;
        instream >> input_array[index];
    }
    return index;
}
int mergeFile(int inputArray1[], int inputArraySize1, int inputArray2[], int inputArraySize2, int outputArray[]) {
    int i=0,j=0,k=0;
    while(i < inputArraySize1 && j < inputArraySize2) {
        if (inputArray1[i] <= inputArray2[j]) {
            outputArray[k] = inputArray1[i];
            i++;
        }
        else {
            outputArray[k] = inputArray2[j];
            j++;
        }
        k++;
    }
    while (i < inputArraySize1) {
        outputArray[k] = inputArray1[i];
        i++;
        k++;
    }
    while (j < inputArraySize2) {
        outputArray[k] = inputArray2[j];
        j++;
        k++;
    }
    return k;
}
void writeFile(ofstream& outStream, int outputArray[], int outputArraySize) {
    for (int i = 0; i < outputArraySize; i++) {
        outStream << outputArray[i] << endl;
    }
    
}
void toString(int array[], int size, char separator) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << separator;
    }
}
bool checkFile(string filename) {
    ifstream inStream;
    inStream.open(filename.c_str());
    if (inStream.fail())  {
        
        inStream.close(); //unsure if this is needed, but better safe than sorry
        return false;
    }
    inStream.close();
    return true;
}
