#include<bits/stdc++.h>
using namespace std;

/*  Problem - Search In Rotated Sorted Array 
    There is an integer array nums sorted in ascending order (with distinct values).

    Prior to being passed to your function, nums is possibly rotated at an unknown pivot 
    index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ...,
    nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] 
    might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

    Given the array nums after the possible rotation and an integer target, return the index 
    of target if it is in nums, or -1 if it is not in nums.

    You must write an algorithm with O(log n) runtime complexity.
    (details captured from leetCode)
    (same question available on leetcode but solved on coding ninjas)
*/

int findPivot(int arr[], int start, int end){
    int mid = start + (end-start)/2;
    // base case
    if(start > end){
        return end;
    }

    if(mid > arr[0]){
        return findPivot(arr, mid-1, end);
    }else{
        return findPivot(arr, start+1, mid);
    }
}

int searchEle(int arr[], int s, int e, int key, int pivot){
    if(pivot != 0){
        if(key > arr[0] && key < arr[pivot]){
        searchEle(arr, 0, pivot, key, 0);
    }else{
        searchEle(arr, pivot, e, key, 0);
    }}
    if(s>e){
        return 0;
    }
    int mid = s + (e-s)/2;
    if(arr[mid] == key){
        return mid;
    }if(arr[mid] < key){
        return searchEle(arr, mid+1, e, key, 0);
    }else{
        return searchEle(arr, s, mid-1, key, 0);
    }
}

int main(){
    int arr[8] = {8,1,2,3,4,5,6,7}; // rotated at index 3, pivot would be - 8;
    int size = 8-1;
    int pivotIndex = findPivot(arr, 0, size);
    int key = 5;
    cout << searchEle(arr, 0, size, 8, pivotIndex) << endl;
}