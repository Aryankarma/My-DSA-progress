#include<bits/stdc++.h>
using namespace std;

// bubble sort using recursion

void bblSort(int *arr, int n){
    if(n==1 || n==0){
        return ;    // array got sorted till n=1 or array of size 0 or 1 is sent that can already be considered sorted 
    }

    for(int i=0; i<n; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    bblSort(arr, n-1);
}

int main(){
    int arr[8] = {54,54,47,87,8,56,2,6};
    bblSort(arr, 7);
    for(int i=0; i<8; i++){
        cout << arr[i] << " ";
    }cout << endl;
}