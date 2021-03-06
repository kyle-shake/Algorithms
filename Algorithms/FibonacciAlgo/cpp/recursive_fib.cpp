/*

Filename: recursive_fib.cpp
Author: Kyle Shake
Last Modified: 11/08/17

Input: An integer n >= 0
Output: The solution to Fibonacci's Sequence F(n) below at the inputted integer n

F(n) = F(n-2) + F(n-1)

with base case:
F(0) = 0
F(1) = 1

Purpose: This program calculates the value of Fibonacci's Sequence at a given integer
modulo 10000 (overflow protection) through recursive function calls


Modifications:
 *Calculate Fibonacci  modulo 10000
    -- to avoid overflow (just in case);
 *Run time measurements (chrono);

*/

#include <iostream>
#include <chrono>
#include <ctime>
#include <cstring>

#define MODULO 10000

using namespace std;

//Recursive function for Fibonacci's sequence
long fibonacci(unsigned long n) {
  if (n < 2) return n;
  return (fibonacci(n-1)%MODULO + fibonacci(n-2)%MODULO)%MODULO;
}

int main(int argc, char *argv[]) {
  // Check command line arguments to tell if timing information should be printed
  char timing_arg[] = "-t";
  bool print_timing = (argc == 2 && strcmp(argv[1], timing_arg) == 0);

  // Read input number
  unsigned long n;
  cin >> n;

  // Run program and deal with timing stuff
  chrono::time_point<chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  cout << "f(" << n << ")%" << MODULO << " = " << fibonacci(n) << endl;
  end = std::chrono::system_clock::now();

  chrono::duration<double> elapsed_seconds = end-start;
  time_t end_time = std::chrono::system_clock::to_time_t(end);

  if( print_timing )
    cout << "elapsed time: " << elapsed_seconds.count() << "s" << endl << endl;
}
