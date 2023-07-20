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


// Link to CodingNinjas [https://www.codingninjas.com/studio/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=0]
// Link to LeetCode [https://leetcode.com/problems/search-in-rotated-sorted-array/]

int binarySearch(vector<int>& arr, int start, int end, int k){
    int s = start, e = end;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(arr[mid] == k){
            return mid;
            break;
        }
        if(arr[mid] < k){
            s = mid + 1;
        }else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
        return -1;
}

int findpivot(vector<int>& arr, int n){
    int start=0, end=n-1;
    int mid = start + (end-start)/2;
    // int i=0;
    // while(i<end){
    //     if(arr[i] < arr[i+1]){
    //         i++;
    //     }else if(arr[i] > arr[i+1]){
    //         break;
    //     }
    //     if(i==end){
    //         return 0;
    //         break;
    //     }
    // }
    while(start<end){
        if(arr[mid] >= arr[0]){
            start = mid+1;
        }else{
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    return start;
}

int search(vector<int>& arr, int n, int k){
    int pivot = findpivot(arr, n);
    
    if(arr[pivot] <= k <= arr[n-1]){
    // if(k >= arr[pivot] && k <= arr[n-1]){
        return binarySearch(arr, pivot, n-1, k);
    }else{
        return binarySearch(arr, 0, pivot-1, k);
    }
}





// leetcode updated code


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int pivot = findpivot(nums, n);
        // if(nums[pivot] <= target <= nums[n-1]){
        if(target >= nums[pivot] && target <= nums[n-1]){
            return binarySearch(nums, pivot, n-1, target);
        }else{
            return binarySearch(nums, 0, pivot-1, target);
        }
    }

    int binarySearch(vector<int>& arr, int start, int end, int k){
    int s = start, e = end;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(arr[mid] == k){
            return mid;
            break;
        }
        if(arr[mid] < k){
            s = mid + 1;
        }else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
        return -1;
}

int findpivot(vector<int>& arr, int n){
    int start=0, end=n-1;
    int mid = start + (end-start)/2;
    while(start<end){
        if(arr[mid] >= arr[0]){
            start = mid+1;
        }else{
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    return start;
}

};