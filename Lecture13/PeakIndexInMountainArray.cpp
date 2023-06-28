#include<bits/stdc++.h>
using namespace std;

/*  Problem - 852. Peak Index in a Mountain Array

    An array arr a mountain if the following properties hold:

    arr.length >= 3
    There exists some i with 0 < i < arr.length - 1 such that:
        arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
        arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

    Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
    You must solve it in O(log(arr.length)) time complexity.

*/

// Link to Leetcode [https://leetcode.com/problems/peak-index-in-a-mountain-array/description/]


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0, end=arr.size()-1, mid = start + (end-start)/2;
        while(start<end){
            if(arr[mid] <arr[mid+1]){
                start = mid+1;
            }else{
                end = mid;
            }
            mid = start + (end - start)/2;
        }
        return mid;
    }
};