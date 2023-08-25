#include<bits/stdc++.h>
using namespace std;

/*  Problem statement - binary search using recursion  */

// my approach (direct array update approach)
bool binarySearch(int arr[], int size, int key){
    int mid = (0 + size-1)/2;

    if((size == 1 || size == 0) && (arr[0] != key)){
        return false;
    }

    if(arr[mid] == key){
        return true;
    }else if(arr[mid] < key){
        return binarySearch(arr+mid+1, size-mid-1, key);
    }else if(arr[mid] > key){
        return binarySearch(arr, mid, key);
    }else{
        return false;
    }
}

// final approach (same binary concept, mid update)
bool binarySearch2(int arr[], int s, int e, int key){
    if(s>e){
        return false;
    }

    int mid = s + (e-s)/2;

    if(arr[mid] == key){
        return true;
    }if(arr[mid] < key){
        return binarySearch2(arr, mid+1, e, key);
    }else{
        
        return binarySearch2(arr, s, mid-1, key);
    }
}

int main(){
    int arr[8] = {1,12,13,14,15,16,18,19};
    // arra, size, key
    int ans = binarySearch(arr, 8, 16);
    // array, start, end, key
    int ans2 = binarySearch2(arr, 0, 5, 16);
    cout << ans << endl << ans2 << endl;
}