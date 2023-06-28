#include<bits/stdc++.h>
using namespace std;

/*  Problem - First and Last Position of an Element In Sorted Array 
    You have been given a sorted array/list ARR consisting of ‘N’ elements. You are also given an integer ‘K’. Now, your task is to find the first and last occurrence of ‘K’ in ARR.

    Note :
    1. If ‘K’ is not present in the array, then the first and the last occurrence will be -1. 
    2. ARR may contain duplicate elements.
*/


// Link to CodingNinjas [https://www.codingninjas.com/studio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=0]


#include <bits/stdc++.h> 

int lastOcc(vector<int>& arr, int n, int k){
    int start=0, end=n-1, mid=start+(end-start)/2, ans=-1;
    while(start<=end){
        if(arr[mid]<k){
            start = mid+1;
        }else if(arr[mid] > k){
            end = mid-1;
        }else if(arr[mid] == k){
            start = mid+1;
            ans = mid;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}

int firstOcc(vector<int>& arr, int n, int k){
    int start=0, end=n-1, mid=start+(end-start)/2, ans=-1;
    while(start<=end){
        if(arr[mid]<k){
            start = mid+1;
        }else if(arr[mid] > k){
            end = mid-1;
        }else if(arr[mid] == k){
            end = mid-1;
            ans = mid;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k){
    pair<int,int> p;
    p.first = firstOcc(arr, n, k);
    p.second = lastOcc(arr, n, k);
    return p;
}