/* 
File: mysterious_seq_memoized.cpp
Author: Kyle Shake
Date: 2/7/17
Purpose: Program calculates value of mysterious sequence at an input value n; 
              specifically using memoization to decrease program run time.

*/

#include <chrono>
#include <iostream>
#include <cmath>
#include <ctime>

#define MODULO 1000

using namespace std;

unsigned long mys_arr[100000]; //initialize long array to hold values already calculated

long mysterious_memo(unsigned long n){
    if(n==0)    return 1; //base case for mysterious sequence

    if(mys_arr[n] > 0) return mys_arr[n]; //if n has already been calculated, retrieves it from array
    
    // use for loop to calculate summation of mysterious sequence
    // instead of just adding to a single total, save totals of each
    // n to it's respective nth index in the array
    for(int i = 0; i < n; i++){
        mys_arr[n] += pow(2, i) * (mysterious_memo(i)%MODULO) * (mysterious_memo(n-i-1)%MODULO); 
    }

    return mys_arr[n]%MODULO;
}

int main(){
    unsigned long n;
    cin >> n;
    
    cout << mysterious_memo(n) << endl; 
}


