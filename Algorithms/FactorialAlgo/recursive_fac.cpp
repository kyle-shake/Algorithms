/*

File: recursive_fac.cpp 
Author: Kyle Shake
Date: 2/7/17
Purpose: Calculate factorial of a number n using recursive functions

*/

#include <iostream>
#include <string>


using namespace std;


unsigned long long fact(unsigned long long n){
    if(n==1) return 1;
    else{
        return (n * fact(n-1));
    }
}

int main(){
    unsigned long long n;
    cin >> n;

    while(n != 0){
        cout << "The factorial of " << n << " is " << fact(n) << endl;
        cin >> n;
    }
}


