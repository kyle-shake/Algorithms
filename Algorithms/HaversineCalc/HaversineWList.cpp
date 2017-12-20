/*
File: HaversineWList.cpp

Author: Kyle Shake

Date: 3/23/17

Purpose: Provided with a list of cities and their geographic coordinates, 
this program finds the length of the path from city to city when always moving
to the next city in the east (south, respectively) direction

README:
3/23 -- Working on parsing the incoming strings, assigning them to variables. 
Needs work on storing the data -- map? linkedlist?

3/28 -- Finished first draft of LinkedList

3/29 -- Finished first draft of program, yet to attempt compile and debug

4/3 -- Problem exists in placing a node in second Linked List. Pointers in Linked
	List functions will point to nodes placed in the first Linked List.
	Do not know how to resolve...

*/


#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "LinkedList.h"
#include <cmath>
#include <math.h>

using namespace std;

//Function to round off the decimals after the 4th
double trimDecimal(double num){
     double trimmed = (num * pow(10, 4));
     trimmed = round(trimmed/pow(10,4));
     return trimmed;
}

/*
MAIN FUNCTION

Reads in a file, line by line. Parses each line according to specified delimiter.
	Stores each token and then assigns the respective values to their variables in a 
	custom node structure. 

Node is then placed into a custom doubly Linked List object via an insertion sort.
	LinkedList functions return cities at furthest point of each cardinal direction 
	relative to other cities. Additionally, Linked List functions compute distance
	from city to city based on the Haversine formula. 

This main function then outputs the results


*/
int main(){

    //Initialize two LinkedLists: one to be sorted by latitude,
    //one to be sorted by longitude
    LinkedList listbyLat;
    LinkedList listbyLong;
    

    //Set up user input and verification 
    string UI;
    while(getline(cin, UI)){
        //Initialize variables for housing tokens of each parsed line
        string substrUI;
        string delim = " ";
        size_t idx = 0;
	size_t previdx = 0;
        size_t sublen = 0;
        vector<string> tokens;

	//Variables to store tokens as desired data
        string cityname;
        double latitude;
        double longitude;
        
        //While loop to parse string into substrings delimited by a space
	//tokens then stored in a vector to be traversed later	
        bool stringparsed = false;
        while(!stringparsed){
	    idx = UI.find(delim, previdx);
            sublen = idx - previdx;
            substrUI = UI.substr(previdx, sublen);
            if(!substrUI.empty()){
                 tokens.push_back(substrUI);
            }
            previdx = idx + delim.length();
            if (idx == string::npos){
                stringparsed = true;
	    }
        }
	/*
        For Debug
        // In the ideal world, the three pieces of data are split by one delimitter (space, in this case)
        // We do not live in an ideal world	
        if (tokens.size() > 3){
            cout << "Data split by multiple delimitters. \n";
            for (int i = 0; i < tokens.size(); i++){

                cout << "[" << i << "]" << tokens[i] << endl;
            }
        }
	*/

        //Last two string values in tokens vector should be our longitude and our latitude
	//But alot of things should be that are not 
	try{
        longitude = atof((tokens[tokens.size()-1]).c_str());
        latitude = atof((tokens[tokens.size()-2]).c_str());

        }catch(const exception& e){
            cout<<"a standard exception was caught, with message "
                << e.what() << "\n";
        }

        //Handling city names with spaces
        if(tokens.size() < 4){
            cityname = tokens[0];
        } else {
            for (int i = 0; i < tokens.size()-2; i++){
                cityname = cityname + " " + tokens[i];
	    }
	}
        node *temp = new node;
        temp->cityname = cityname;
        temp->latitude = trimDecimal(latitude); 
        temp->longitude = trimDecimal(longitude);

        int tempLatPos = 0, tempLongPos = 0;
        bool LatPosFound = listbyLat.findPosition(true, latitude, tempLatPos);
        bool LongPosFound = listbyLong.findPosition(false, longitude, tempLongPos);

        listbyLat.insertNode(temp, tempLatPos);
        listbyLong.insertNode(temp, tempLongPos);

        tokens.clear();
    }
    



    //  Printing out the results here
    cout << "WE: " << listbyLong.getNESWmostCity('W') << " - " 
         << listbyLong.getNESWmostCity('E') << endl;
    cout << listbyLong.computeHaversine() << " km" << endl;
    cout << listbyLong.computeHaversine()*0.621371 << " mi" << endl;
    cout << "NS: " << listbyLat.getNESWmostCity('N') << " - " 
         << listbyLat.getNESWmostCity('S') << endl;
    cout << listbyLat.computeHaversine() << " km" << endl;
    cout << listbyLat.computeHaversine()*0.621371 << " mi" << endl;

    return 0;

}
