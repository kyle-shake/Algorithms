/*
File: NESW.cpp

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

----------

Version 2: Rework

4/3 -- Rework on program because LinkedLIst was giving me too much trouble
and I was told it was inefficient

4/3 -- Now using vector of custom Location objects

4/3 -- Looking for a way to using sort algorithm to sort multiple ways with one
vector... @17:05 Program will not compile as functions to provide sort criteria
are not being referenced properly


*/


#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "Location.h"
#include <cmath>
#include <math.h>
#include <algorithm>
#define pi 3.14159265
#define earthRadiusKm 6371.0

using namespace std;

double deg2rad(double deg){
    return ((deg * pi)/180);
}
//Function to round off the decimals after the 4th
double trimDecimal(double num){
     double trimmed = (num * pow(10, 4));
     trimmed = round(trimmed/pow(10,4));
     return trimmed;
}

//Function to tell sort() function how to sort based on latitude
//North to South
bool sortbyLat(const Location &lhs, const Location &rhs){
     return (lhs.latitude > rhs.latitude);
}

// Function to tell sort() function how to sort based on longitude
//West to East
bool sortbyLong(const Location &lhs, const Location &rhs){
     return (lhs.longitude < rhs.longitude);
}

//Function computes distance between n cities using their latitudes
// 	and longitudes, and the Haversine formula.
//Input: vector of Location objects
//Returns distance as double
float computeHaversine(vector<Location>voflocs){

    double distance, lat1r, long1r, lat2r, long2r, havLat, havLong;
    
    //While loop to traverse vector and compute the distance between cities
    for(int i = 0; i < voflocs.size()-1; i++){
        lat1r = deg2rad(voflocs[i].latitude);
        long1r = deg2rad(voflocs[i].longitude);
        lat2r = deg2rad(voflocs[i+1].latitude);
        long2r = deg2rad(voflocs[i+1].longitude);
        havLat = sin((lat2r-lat1r)/2);
        havLong = sin((long2r-long1r)/2);
        distance += 2.0 * earthRadiusKm * asin(sqrt(havLat*havLat + cos(lat1r) * cos(lat2r) * havLong*havLong));
    }
    return distance;
}


/*
MAIN FUNCTION

Reads in a file, line by line. Parses each line according to specified delimiter.
Stores each token and then assigns the respective values to their variables in a 
Location custom object. Location object is stored in vector and then reused on next
line. Function then uses above bool functions to sort according to latitude/longitude
while storing the cities at the furthest end of the cardinal directions in relation 
to the other cities between each sort. Function finally outputs the results of the sorts
and the results of the Haversine calculator function above

*/
int main(){

    //Initializing vector of custom Location objects
    vector <Location> voflocs;

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
            cityname = tokens[0];
            for (int i = 1; i < tokens.size()-2; i++){
                cityname = cityname + " " + tokens[i];
	    }
	}
        Location temploc;
        temploc.cityname = cityname;
        temploc.latitude = latitude;
        temploc.longitude = longitude;

        voflocs.push_back(temploc);

        tokens.clear();
    }
    //Remove duplicates
    voflocs.erase(unique(voflocs.begin(), voflocs.end()), voflocs.end());

    //Sort vector by latitude first, then assign variables to North most
    // and South most cities, and the distance from city to city 
    sort(voflocs.begin(), voflocs.end(), sortbyLat);
    string Nmostcity = voflocs[0].cityname;
    string Smostcity = voflocs[voflocs.size()-1].cityname;
    double distanceN2S = computeHaversine(voflocs);
    
    sort(voflocs.begin(), voflocs.end(), sortbyLong);
    string Wmostcity = voflocs[0].cityname;
    string Emostcity = voflocs[voflocs.size()-1].cityname;
    double distanceW2E = computeHaversine(voflocs);

    //  Printing out the results here
    cout << "WE: " << Wmostcity << " - " << Emostcity << endl;
    cout << distanceW2E << " km" << endl;
    cout << distanceW2E*0.621371 << " mi" << endl;
    cout << "NS: " << Nmostcity << " - " << Smostcity << endl;
    cout << distanceN2S << " km" << endl;
    cout << distanceN2S*0.621371 << " mi" << endl;

    return 0;

}
