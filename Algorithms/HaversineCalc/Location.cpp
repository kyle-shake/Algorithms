//Filename: Location.cpp
//Author: Kyle Shake
//Date Created: 4/3/17
//Last Modified: 4/3/17
//Purpose: Provides function implementation for custom class Location

#include "Location.h"
#include <cmath>
#include <string>

using namespace std;

//Default Constructor
//Cityname variable is initialized
//Longitude/Latitude variables are initialized to 0
Location::Location(){
     cityname = "";
     latitude = 0;
     longitude = 0; 
}

bool Location::operator==(const Location &rhs) const{
     if (this->latitude != rhs.latitude){
          return false;
     }
}
