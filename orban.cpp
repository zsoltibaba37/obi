/*
    orban
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <random>
#include "color.h"
using namespace std;

// ----- Get File Content -----
bool getFileContent(string fileName, vector<string> & idezet, vector<string> & datum){
    //open thefile
    ifstream in(fileName.c_str());
    // Check file is available
    if(!in)
    {
        cerr << "Cannot open the File: " << fileName << endl;
        return false;
    }
    string str;
    // Read File line by line
    while (getline(in, str))
    {
        // Line contains string of length > 0 then save it in vector
        if(str.size() > 0 && *str.begin() != '\'' ){
            idezet.push_back(str);
        }
        if(str.size() > 0 && *str.begin() == '\''){
            datum.push_back(str);
        }
    }
    //Close The File
    in.close();
    return true;   
}


// ----- Print Eempty Line -----
void printLn(){
    cout << endl;
}


// ----- START MAIN ----------
// ----- START MAIN ----------
int main(){
    srand ( time(NULL) );
    vector<string> idezet;
    vector<string> datum;
    bool result = getFileContent("orban.txt", idezet, datum);
    if (result == false){
        exit (EXIT_FAILURE);
    }
    else{
        // Question
        int howMany;
        printLn();
        cout << GREEN << "How many quotes should print? " << "[" << idezet.size() << "]: " << RESET;
        cin >> howMany;
        printLn(); // print empty line
        // Print quotes
        for (int i = 0; i < howMany; i++){
            int randomNum = rand() % idezet.size(); // random number
            cout << UNDLGREEN << i+1 << ". " << "quote:" << RESET << endl;
            cout << idezet[randomNum] << endl;
            printLn(); // print empty line
        }
        //cout << "The dates:" << endl;
        //cout << "The dates num: " << datum.size() << endl;
        //for (int y=0; y < datum.size(); y++){
        //    cout << y+1 << ". " << datum[y] << endl;
        //}
    }
}
// ----- END MAIN -----------