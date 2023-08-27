#include<bits/stdc++.h>
using namespace std;

/*  Problem - First and Last Position of an Element In Sorted Array 
    You have been given a sorted array/list ARR consisting of ‘N’ elements. You are also 
    given an integer ‘K’. Now, your task is to find the first and last occurrence of ‘K’ 
    in ARR.

    Note :
    1. If ‘K’ is not present in the array, then the first and the last occurrence will be -1. 
    2. ARR may contain duplicate elements.

    ex. 
    1.  0 5 5 6 6 6 (find 3)
        output = -1 -1

    2. 0 0 1 1 2 2 2 2 
        output = 4 7

    3. 0 0 0 0
        output = 0 3


*/

// Note - this solutions from lecture33 are based on binarySearch approach which I am tackling through recursion and are not the solution to the link given below

// Link to CodingNinjas [https://www.codingninjas.com/studio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=0]

int firstIndex(int arr[], int start, int end, int key){
    if(start>end){
        return -1;
    }
    // int Index=-1;
    int mid = start + (end-start)/2; 
    if(arr[mid] == key){
        if(arr[mid] == arr[mid-1]){
            return firstIndex(arr, start, mid-1, key);
        }else{
            // firstIndex = mid;
            return mid;
        }    
    }else if(arr[mid] < key){
        return firstIndex(arr, mid+1, end, key);
    }else{
        return firstIndex(arr, start, mid-1, key);
    }
    // return Index;
}

int lastIndex(int arr[], int start, int end, int key){
    if(start>end){
        return -1;
    }
    // int Index = -1;
    int mid = start + (end-start)/2; 
    if(arr[mid] == key){
        if(arr[mid] == arr[mid+1]){
            return lastIndex(arr, mid+1, end, key);
        }else{
            // lastIndex = mid;
            return mid;
        }
    }else if(arr[mid] < key){
        return lastIndex(arr, mid+1, end, key);
    }else{
        return lastIndex(arr, start, mid-1, key);
    }
    // return Index;
}

// int firstLastIndex(int arr[], int start, int end, int key){
//     // int firstIndex, lastIndex;
//     int mid = start + (end-start)/2; 
//     if(arr[mid] == key){
//         if(arr[mid] == arr[mid-1]){
//             return firstLastIndex(arr, start, mid-1, key);
//         }else{
//             // firstIndex = mid;
//             return mid;
//         }if(arr[mid] == arr[mid+1]){
//             return firstLastIndex(arr, mid+1, end, key);
//         }else{
//             // lastIndex = mid;
//             return mid;
//         }
//     }else if(arr[mid] < key){
//         return firstLastIndex(arr, mid+1, end, key);
//     }else{
//         return firstLastIndex(arr, start, mid-1, key);
//     }
// }

int main(){
    int arr[8] = {0,0,1,1,2,2,2,2}; // 2 5
    cout << "First index " << firstIndex(arr, 0, 7, 1) << endl;
    cout << "Last index " << lastIndex(arr, 0, 7, 1) << endl;
}