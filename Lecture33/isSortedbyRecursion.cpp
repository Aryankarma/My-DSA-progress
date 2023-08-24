#include<bits/stdc++.h>
using namespace std;

/*  Problem statement - Check if the given array is sorted or not

*/

// my approach
bool func(int arr[], int size, int i){
    if(size==0 || size==1){
        return true;
    }
    if(i == size-1){
        return true;
    }

    if(arr[i] <= arr[i+1]){
        i++;
        return func(arr, size, i);
    }else{
        return false;
    }
}

// final approach
bool isSorted(int arr[], int size){
    if(size==0||size==1){
        return true;
    }
    if(arr[0] <= arr[1]){
        return isSorted(arr + 1, size - 1);
    }else{
        return false;
    }
}

int main(){
    int arr[5] = {1,2,2,4,1};
    int ans1 = func(arr, 5, 0);
    cout << ans1 << endl;
    int ans2 = isSorted(arr, 5);
    cout << ans2 << endl;
}