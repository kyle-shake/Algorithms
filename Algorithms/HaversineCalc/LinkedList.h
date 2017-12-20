//Filename: LinkedList.h
//Author: Kyle Shake
//Date Created: 1/31/17
//Last Modified: 1/31/17
//Purpose: Provides the definition for the custom Linked List class

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <string>
#include <iostream>

using namespace std;

/**
Node struct contains template value and a pointer to next node
**/
struct node{
    string cityname;
    double latitude;
    double longitude;
    node *next;
    node *prev;
};

/**
LinkedList class is a list of doubly-linked nodes.

**/    

class LinkedList
{
    public:
    //Default Constructor creates the head node
    LinkedList();

    //Function adds a node to the list at a given position
    //Takes a node and position as parameters
    //Position must be between 1 - listlength
    //Returns true if the operation is successful
    bool insertNode(node *newNode, int position);

    //Function removes duplicates from LinkedList
    void removeDuplicates();

    //Function removes a node by its given position
    //Returns true if the operation is successful
    bool removeNode(int pos);

    //Function implements a two way search on LinkedList to find position where key fits
    //		in the ordered LinkedList
    //@param findlat --  Bool variable if looking for position according to latitude
    //@param key -- latitude or longitude value to be positioned
    //@param pos -- a call by reference position variable to store the position
    //Pos may not be known but we use it as a call by reference parameter
    //    in order to return both a bool variable and the matching value's location
    bool findPosition(bool findlat, float key, int& pos);

    //Function returns length of LinkedList
    int getLength();

    //Function finds the North, East, South, West most city based on list's ordering
    //@param NESWdir -- specifies what cardinal direction
    //Returns city name of specified cardinal direction 
    string getNESWmostCity(char NESWdir);

    //Function converts degrees to radians
    float deg2rad(float deg);

    //Function converts radians to degrees;
    float rad2deg(float rad);

    //Function computes the distance between the cities in the list according to their order
    //returns total distance between all cities in the list
    float computeHaversine();

    //Destructor de-allocates memory used by the list
    ~LinkedList();


    private:
    node *head;
    node *tail;
    int listLength;
};

#endif
