//Filename: LinkedList.cpp
//Author: Kyle Shake
//Date Created: 1/31/17
//Last Modified: 1/31/17
//Purpose: Provides function implementation for custom clss Linked List

#include "LinkedList.h"
#include <cmath>
#include <string>
#define pi 3.14159265
#define earthRadiusKm 6371.0

//Default Constructor
//Longitude/Latitude values for head and tail are set
//to their maximum and minimum corresponding with the programs
//desired ordering of cities.
// West to East for Longitude (-180 for head to 180 for tail)
// North to South for Latitude (90 for head to -90 for tail)

LinkedList::LinkedList(){
     //Initialize head and tail pointers
     head = NULL;
     tail = NULL;

     //Initialize length
     listLength = 0;
}

bool LinkedList::insertNode(node *newNode, int pos){
     if ((pos < 0) || (pos > listLength+1)){
          cout << "nError: given position is out of range \n";
          return false;
     }
     if (head == NULL){
         this->head = newNode;
         this->tail = newNode;
         newNode->next = NULL;
         newNode->prev = NULL;
         listLength++;
         return true;
     }
     int count = 0;
     node *p = new node; 
           p = this->head;
     node *q = new node;
           q = this->head;

     while(q){
         if(count == pos){
             p->next = newNode;
             newNode->next = q;
             newNode->prev = p;
             q->prev = newNode;
             listLength++;
             delete p;
             p = NULL;
             delete q;
             q = NULL;
             return true;
         }
         p = q;
         q = p->next;
         count++;
    }
    if (count == pos){
        p->next = newNode;
        this->tail = newNode;
        newNode->next = NULL;
        newNode->prev = p;
        listLength++;
        delete p;
        p = NULL;
        delete q;
        q = NULL;
        return true;
   }
   cout << "nError: node was not added to the list \n";
   return false;
}

void LinkedList::removeDuplicates(){
    if(head->next == tail){
        return; //if list is empty, do nothing
    }

    node *curr = head;
    node *after = NULL; //pointer to the node after the dup
    while(curr->next != NULL){
        if(curr->latitude == curr->next->latitude){
            if(curr->longitude == curr->next->longitude){
                after = curr->next->next;
                delete curr->next;
                curr->next = after;
            }else{
                curr = curr->next;
            }  
        }
    }
}

bool LinkedList::removeNode(int pos){
    if ((pos <= 0) || (pos > listLength + 1)){
        cout << "nError: the given position is out of range \n";
        return false;
    }
    if (head->next == NULL){
        cout << "nError: there is nothing to remove \n";
        return false;
    }
    int count = 0;
    node *p = head;
    node *q = head;
    node *r = tail;
    while(q != tail){
        if(count == pos){
            p->next = q->next;
            delete q;
            if(p->next){
                r = p->next;
                r->prev = p;
            }
            listLength--;
            return true;
        }
        p = q;
        q = p->next;
        count++;
    }
    cout << "nError: nothing was removed from the list \n";
    return false;
}

bool LinkedList::findPosition(bool findlat, float key, int& pos){
    if(listLength <= 0){
        //cout << "There are no nodes in List \n"; **DEBUG**
        pos = 0;
        return true;
    }
    node *p = head;
    node *q = head;
    int count = 0;

    if(findlat){
        while(q != NULL){
            if((p->latitude >= key) && (q->latitude <= key)){
                pos = count;
                return true;
            }
        
 //           if ((s->latitude <= key) && (r->latitude >= key)){
 //               pos = (listLength + 2) - count;  //Not sure if correct ***********
//                return true;
//            }
            p = q;
            q = p->next;
//            s = tail;
//            r = s->prev;
            count++;
        }
    }else{
        while(q != NULL){
            if((p->longitude <= key) && (q->longitude >= key)){
                pos = count;
                return true;
            }
    //        if ((r->longitude <= key) && (s->longitude >= key)){
    //            pos = (listLength + 2) - count; //Not sure if correct *************
    //            return true;
    //       }
            p = q;
            q = p->next;
    //        s = r;
    //        r = s->prev;
            count++;
        }
    }
    //cout << "Putting node at the end of list.\n"; **DEBUG**
    pos = count;

    return true; //pos not able to be found
}

int LinkedList::getLength(){
    return listLength;
}

string LinkedList::getNESWmostCity(char NESWdir){

    node *p = new node;
    //Switch statement to return city at desired cardinal direction
    switch(NESWdir){
        case 'N':
            p = this->head;
        case 'E':
            p = this->tail;
        case 'S':
            p = this->tail;
        case 'W':
            p = this->head;
    }
    return p->cityname;
}

float LinkedList::deg2rad(float deg){
    return (deg * pi / 180);
}

float LinkedList::rad2deg(float rad){
    return (rad * 180 / pi);
}

float LinkedList::computeHaversine(){

    float distance, lat1r, long1r, lat2r, long2r, havLat, havLong;
    
    //While loop to traverse list and compute the distance between cities
    node *p = head;
    node *q = head->next;
    while(q != tail){
        p = q;
        lat1r = deg2rad(p->latitude);
        long1r = deg2rad(p->longitude);
        lat2r = deg2rad(q->latitude);
        long2r = deg2rad(q->longitude);
        havLat = sin((lat2r-lat1r)/2);
        havLong = sin((long2r-long1r)/2);
        distance += 2.0 * earthRadiusKm * asin(sqrt(havLat*havLat + cos(lat1r) * cos(lat2r) * havLong*havLong));
        q = p->next;
    }
    return distance;
}


LinkedList::~LinkedList(){
    node *p = head;
    node *q = head;
    while(q){
        p = q;
        q = p->next;
        if(q){
            delete p;
        }
    }
}



