#include<bits/stdc++.h>
using namespace std;

/*  Problem - 852. Peak Index in a Mountain Array

    An array arr a mountain if the following properties hold:

    arr.length >= 3
    There exists some i with 0 < i < arr.length - 1 such that:
        arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
        arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

    Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < 
    arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
    You must solve it in O(log(arr.length)) time complexity.

    Example 1:
    
    Input: arr = [0,1,0]
    Output: 1
    Example 2:
    
    Input: arr = [0,2,1,0]
    Output: 1
    Example 3:
    
    Input: arr = [0,10,5,2]
    Output: 1
    
*/

// Note - this solutions from lecture33 are based on binarySearch approach which I am tackling through recursion and are not the solution to the link given below

// Link to Leetcode [https://leetcode.com/problems/peak-index-in-a-mountain-array/description/]

int returnPeak(int arr[], int start, int end){
    int mid = start + (end-start)/2;

    // base case
    if(start>end){
        return 1000;
    }

    if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
        return mid;
    }else if(arr[mid] < arr[mid-1]){   // decreasing line, update end
        return returnPeak(arr, start, mid-1);
    }else if(arr[mid] < arr[mid+1]){   // increasing line, update start
        return returnPeak(arr, mid+1, end);
    }
}

int main(){
    // int arr[9] = {1,3,5,5,6,8,25,325,58};
    // int arr[9] = {1,3,5,365,300,250,100,80,58};
    int arr[5] = {1,2,2,4,8};
    cout << returnPeak(arr, 0, 4);
}