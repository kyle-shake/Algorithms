//Filename: testcreator.cpp
//Author: Kyle Shake
//Date: 11/13/17
//Purpose: This program creates test files for the median.cpp program


#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

int main(){

    ofstream ofs;
    string filename;
    stringstream ss;

    for(int i = 0; i < 10 ; i++){
       ss << i;
       filename = "input" + ss.str();
       filename += ".in";
       
      
       ofs.open(filename.c_str(), ios::out);
       cout << "Creating file: " << filename <<" ..." << endl;
       cout << "Writing ..." << endl;

       
       for(int j = 0; j < 5; j++){
           int var = rand() % 100 + 1;
           ofs << var << endl;
           cout << var << endl;
       }
       ofs.close();
       ss.str("");
       cout << "File: " << filename << " successfully created!" << endl;
    }


}
