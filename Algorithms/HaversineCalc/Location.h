//Filename: Location.h
//Author: Kyle Shake
//Date Created: 4/3/17
//Last Modified: 4/3/17
//Purpose: Provides the definition for the custom Location class

#ifndef LOCATION_H
#define LOCATION_H


#include <string>
#include <iostream>

using namespace std;
class Location
{
    public:
    //Default Constructor initializes Location variables
    Location();
    //Defining == operator for use in removing duplicates
    bool operator==(const Location& rhs) const;
    string cityname;
    double latitude;
    double longitude; 

    private:
};

#endif
