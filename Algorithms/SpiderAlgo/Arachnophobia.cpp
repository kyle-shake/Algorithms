/*
File: Arachnophobia.cpp

Author: Kyle Shake

Date Created: 4/6/2017

Purpose: Given the row and column coordinates of a grid cell, this program determines if the "spider"
can reach the fly

Input: User inputs N number of lines containing an N number of characters 'D', 'S' and 'F'

Output: Function outputs NO or YES if "Spider" can reach the "Fly" without stepping
on an 'S' tile

*/

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

#define MAXCOLLEN 99
#define MAXROWLEN 99


using namespace std;

static int MAX_CAPACITY = 99;
char sarray[MAXCOLLEN][MAXROWLEN];
bool visited[MAXCOLLEN][MAXROWLEN];
int row_len, col_len;

int dfs(int row, int col){

    if( row < 0 || col < 0 || sarray[row][col] == 'S' || visited[row][col]){
        return 0;
    }
    if( row >= row_len){
        row = row - row_len;
    }
    if( col >= col_len){
        col = col - col_len;  
    }
    
    visited[row][col] = true;

    int count = 0;

    if (sarray[row][col] == 'F'){
        count += 1;
    }

    count += dfs(row, col+1);
    count += dfs(row, col-1);
    count += dfs(row+1, col);
    count += dfs(row-1, col);
    count += dfs(row+1, col+1);
    count += dfs(row+1, col-1);
    count += dfs(row-1, col-1);
    count += dfs(row-1, col+1);
 
    return count;
}


int main(){

    string line;
    int row, col;
    row_len = col_len = 0;
    while(getline(cin, line)){
        
	if(line[0] == 'F' || line[0] == 'S' || line[0] == 'D'){
            row_len = line.length();
            for(int i = 0; i < row_len; i++){
                sarray[col_len][i] = line[i];
            } 
            col_len++;
        }else{
            istringstream line_in(line);
            line_in >> row >> col;
            
            if( dfs(row-1, col-1) > 0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
            memset(visited, 0, sizeof(visited)); 
        }
       
   }
   return 0;
}






