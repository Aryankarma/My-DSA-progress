#include<bits/stdc++.h>
using namespace std;

// selection sort using recursion

void selSort(int *arr, int size, int index){
    // base case
    if(index > size){
        return ;
    }

    int minimum = index;
    for(int i=index+1; i<size; i++){
        if(arr[i] < arr[minimum]){
            minimum = i;
        }
    }
    swap(arr[index], arr[minimum]);
    return selSort(arr, 7,index+1);
}

int main(){
    int arr[8] = {54,12,87,32,5,54,32,4};
    selSort(arr, 8,0);
    for(int i=0; i<8; i++){
        cout << arr[i] << " ";
    }cout << endl;
}