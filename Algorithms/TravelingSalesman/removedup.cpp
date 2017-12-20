/*

FIle: removedup.cpp

Author: Kyle Shake

Date: 3/2/17

Purpose: Removes duplicates from a list of strings



*/


#include <string>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;


int main(){
    map <string, int> lines;

    string line;
    int idx = 0;
    while ( getline(cin, line) )
    {
        if (lines.find(line) == lines.end() ){
            lines[line] = idx++;
        }
    }
    cout << "num cities:" << idx << endl;
    return 0;

}
