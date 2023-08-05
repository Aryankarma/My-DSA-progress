#include<bits/stdc++.h>
using namespace std;

// we have to print the array in a wave patterns

/* Problem statement - Print Like A Wave
1 | 2 | 3 |
4 | 5 | 6 |
7 | 8 | 9 |
  `````  
print this in a form
given = row, col, array

    For a given two-dimensional integer array/list ‘ARR’ of size (N x M), print the ‘ARR’ 
    in a sine wave order, i.e., print the first column top to bottom, next column bottom 
    to top, and so on.
    
    eg - 
     sample input - 
    3(row) 4(col)
    1 2 3 4
    5 6 7 8
    9 10 11 12

     sample Output -
    1 5 9 10 6 2 3 7 11 12 8 4

     sample input - 
    4 4
    1 2 4 '5'
    3 6 8 10
    11 12 13 15
    16 14 9 7

     sample Output -
    1 3 11 16 14 12 6 2 4 8 13 9 7 15 10 5
*/

// Link to CodingNinjas [https://www.codingninjas.com/studio/problems/print-like-a-wave_893268?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_6]

// CodingNinjas solution
#include <bits/stdc++.h> 
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols){
    vector<int> v;
    for(int col=0; col<mCols; col++){
        if(col%2 == 0){
            int row=0;
            while(row<nRows){
                v.push_back(arr[row][col]);
                row++;
            }
        }else{
            int row=nRows-1;
            while(row >= 0){
                v.push_back(arr[row][col]);
                row--;
            }
        }
    }
    return v;
}



// VS Code solution
int main(){
    int row0=4, col0=4;
    // int arr[row0][col0] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int arr[row0][col0] = {{1,2,4,5},{3,6,8,10},{11,12,13,15},{16,14,9,7}};

    // output
    for(int col=0; col<col0; col++){
        if(col%2 == 0){
            int row=0;
            while(row<row0){
                cout << arr[row][col] << " ";
                row++;
            }
        }else{
            int row=row0-1;
            while(row >= 0){
                cout << arr[row][col] << " ";
                row--;
            }
        }
    }
}