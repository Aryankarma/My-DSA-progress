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

// int search(int arr[], int s, int e, int key){
    
    
//     if(s>e){
//         return 0;
//     }

//     int mid = s + (e-s)/2;

//     if(arr[mid] == key){
//         return true;
//     }if(arr[mid] < key){
//         return binarySearch2(arr, mid+1, e, key);
//     }else{
//         return binarySearch2(arr, s, mid-1, key);
//     }
// }

int main(){
    int arr[8] = {6,7,8,1,2,3,4,5}; // rotated at index 3, pivot would be - 8;
    int size = 8-1;
    cout << findPivot(arr, 0, size) << endl;
    // search(arr, 0, size, 5);
}