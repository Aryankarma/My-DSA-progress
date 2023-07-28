#include<bits/stdc++.h>
using namespace std;

// Simple Bubble sort Program

int main(){
    int array[15] = {564,5,1542,564,987,987,12,48,84,9,56,1,12,5,48};
    int size = sizeof(array)/sizeof(array[0]);
    cout << size << endl;

    // for(int i=1; i<size; i++){
    //     for(int j=0; j<size-1; j++){
    //         if(array[j] > array[j+1]){
    //             swap(array[j], array[j+1]);
    //         }
    //     }
    // }

    // for(int i=0; i<size; i++){
    //     cout << array[i] << " ";
    // }
    for(int i=1; i<size;i++){
    bool swapped = false;
        for(int j=0; j<size-1; j++){
            if(array[j]>array[j+1]){
                swap(array[j],array[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
            // the array is already sorted;
        }
    }
    for(int i=0; i<size; i++){
        cout << array[i] << " ";
    }

}