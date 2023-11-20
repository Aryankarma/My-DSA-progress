#include<bits/stdc++.h>
using namespace std;

// learning how to create 1D & 2D arrays in heap memory (dynamically)

int main(){
    // creating a 1D array

    int value;
    cout << "enter number of values : " << endl;
    cin >> value;

    int *arr = new int[value];

    cout << "taking input for 1D array (" << value << " numbers)" << endl;
    for(int i=0; i<value; i++){
        cin >> arr[i];
    }
    cout << "printing output " << endl;
    for(int i=0; i<value; i++){
        cout << arr[i] << " ";
    }
    cout << endl;


    // creating a 2D array (3X5)
    int row, col;
    cout << "Enter number of row : " << endl;
    cin >> row ;
    cout << "Enter number of col : " << endl;
    cin >> col;

    int **arr2 = new int*[row];

    for(int i=0; i<row; i++){
        arr2[i] = new int[col];
    }

    cout << "taking input : " << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> arr2[i][j];
        }
    }

    cout << "printing output " << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    // now to free up the heap memory
    for(int i=0; i<row; i++){   
        delete [] arr2[i];
    }
    delete []arr2;
}