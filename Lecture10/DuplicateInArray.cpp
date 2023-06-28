#include<bits/stdc++.h>
using namespace std;

/*  Problem -  Duplicate in Array

    You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once. There is a single integer value that is present in the array twice. Your task is to find the duplicate integer value present in the array.

    For example:
    Consider ARR = [1, 2, 3, 4, 4], the duplicate integer value present in the array is Hence, the answer is 4 in this case.

*/

// Link to CodingNinjas [https://www.codingninjas.com/studio/problems/duplicate-in-array_893397?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1]


int findDuplicate(vector<int> &arr) {
    // for(int j=0; j<arr.size()/2; j++){
    //     for(int i=0; i<arr.size()/2; i++){
    //         if(i == j){
    //             continue;
    //         }else if(arr[i] == arr[j]){
    //             return arr[i];
    //         }
    //     }
    // }
    int n=0;

    for(int i=0; i<arr.size(); i++){
        n = (n^arr[i]);
    }
    for(int i=1; i<arr.size(); i++){
        n = (n^i);
    }
    return n;
}