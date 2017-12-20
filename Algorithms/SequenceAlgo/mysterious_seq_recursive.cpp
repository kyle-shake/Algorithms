/*
File: mysterious_seq_recursive.cpp
Author: Kyle Shake
Date: 2/7/17
Purpose: Compute nth element of the Mysterious sequence mod 1000

Input: one line containing n for which we want to computer s(n)
Output: One line with s(n)

*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <chrono>
#define MODULO 1000

using namespace std;

unsigned long mysterious2(unsigned long n){
    if(n == 0)	return 1; //base case for mysterious sequence

    unsigned long total = 0; //initialize a long variable to hold the summation total

    //Use for loop to calculate summation of mysterious sequence
    for (int i = 0; i < n; i++)
    {
        total += pow(2, i)*(mysterious2(i)%MODULO)*(mysterious2(n-i-1)%MODULO);
    }
    return total%MODULO;
}

int main(){

    unsigned long n; //initialize a long variable for mysterious2 function parameter
    cin >> n;

    cout << mysterious2(n) << endl;
}
