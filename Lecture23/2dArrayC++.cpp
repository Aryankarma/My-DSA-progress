#include<bits/stdc++.h>
using namespace std;

int main(){

    int row0,col0;
    cout <<"Enter row and col respectively : " << endl;
    cin >> row0;
    cin >> col0;
    int arr[row0][col0]; 
    
// input (ROW WISE)
//  1 2 3 4 5 6 7 8 9 10 11 12
//  OUTPUT
//  1 2 3 4
//  5 6 7 8
//  9 10 11 12 

    cout << "Enter elements for array : " << endl; 
    for(int row=0; row<row0; row++){
        for(int col=0; col<col0; col++){
            cin >> arr[row][col];
        }
    }


// input (COL WISE)
//  1 2 3 4 5 6 7 8 9 10 11 12
//  OUTPUT
//  1 4 7 10
//  2 5 8 11
//  3 6 9 12
    // for(int col=0; col<col0; col++){
    //     for(int row=0; row<row0; row++){
    //         cin >> arr[row][col];
    //     }
    // }

// output

    for(int row=0; row<row0; row++){
        for(int col=0; col<col0; col++){
            cout << arr[row][col] <<" ";
        }cout << endl;
    }

// Linear search in 2D Arrays

    int temp;
    int count=0;
    cout << "Enter a number to find : " << endl; 
    cin >> temp;
    for(int i=0; i<row0; i++){
        for(int j=0; j<col0; j++){
            if(arr[i][j] == temp){
                count++; 
                cout << "Element present " << endl;
            }
        }
    }
    if(count==0){
        cout << "Element is not present "<< endl;
    }
}