#include<bits/stdc++.h>
using namespace std;

// You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1]. Now, in the given array/list, 'M' numbers are present twice and one number is present only once. You need to find and return that number which is unique in the array/list.

// Link to CodingNinjas [https://www.codingninjas.com/studio/problem-details/find-unique_625159]


int findUnique(int *arr, int size){
    // for(int j=0; j<size; j++){
    //     int count=0;
    //     for(int i=0; i<size; i++){
    //         if(i==j){
    //             continue;
    //         }else if(arr[i] == arr[j]){
    //             count++;
    //         }
    //     }
    //     if(count == 0){
    //         return arr[j];
    //     }
    // }
    int n=0;
    for(int i=0; i<size; i++){
        n = (n ^ arr[i]);
    }
    return n;
}