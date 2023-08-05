#include<bits/stdc++.h>
using namespace std;


int main(){
    int row0, col0;
    cout << "Enter row and col respectively : ";
    cin >> row0;
    cin >> col0;
    int arr[row0][col0];
    
    // inputs;
    cout << "Enter elements : "<< endl;
    for(int row=0; row<row0; row++){
        for(int col=0; col<col0; col++){
            cin >> arr[row][col];
        }
    }
    // output 
    int sum;
    for(int row=0; row<row0; row++){
        for(int col=0; col<col0; col++){
            sum = sum + arr[row][col];
        }
        cout << sum << endl;
        sum = 0;
    }   
}