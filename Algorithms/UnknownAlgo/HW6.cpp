/*

 File: HW6.cpp

Author: Kyle Shake

Date: 2/20/17

Purpose: 


*/


#include <iostream>

using namespace std;

//Input: Two integers, x&y, where y >= 1
int whatisit(int x, int y, int& q, int& r)
{
    if(x==0)
    {
        q = 0;
        r = 0;
        return 0;
    }

    whatisit(x/2, y, q, r);

    q = q*2;

    r = r*2;
    
    if (x % 2 == 1)
    {
        r = r+1;
    }

    if (r >= y)
    {
        r = r-y;
        q = q + 1;
    }


}

int main(){

     //Initialize variables 
     int n = 0, x = 0, y = 0, q = 0, r = 0;

     //Number of inputs
     cin >> n;

     //For loop to run multiple inputs
     for (int i = 0; i < n; i++){
        cin >> x >> y;
        whatisit(x, y, q, r);
     
        cout << x << "/" << y << ":     " << x << " = " << q << " * " << y << " + " << r << endl;
        q = 0;
        r = 0;
    }
}



