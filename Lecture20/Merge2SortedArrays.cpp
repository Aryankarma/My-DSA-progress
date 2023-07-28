#include<bits/stdc++.h>
using namespace std;

/*  Problem statement - 88. Merge Sorted Array
    You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and 
    two integers m and n, representing the number of elements in nums1 and nums2 respectively.

    Merge nums1 and nums2 into a single array sorted in non-decreasing order.

    The final sorted array should not be returned by the function, but instead be stored 
    inside the array nums1. To accommodate this, nums1 has a length of m + n, where the 
    first m elements denote the elements that should be merged, and the last n elements are 
    set to 0 and should be ignored. nums2 has a length of n.

*/

// Link to Leetcode [https://leetcode.com/problems/merge-sorted-array/]

class Solution {
public:
    // nums1 = m number of element, nums2 = n number of elements
    // we have to merge them both in out nums1 array and then sort the array
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(nums1.size()-1 > m-1){
            nums1.pop_back();
        }
        if(m==0){
            nums1.clear();
        }
        for(int i=0; i<n; i++){
            nums1.push_back(nums2.at(i)); 
        }
        sort(nums1.begin(), nums1.end());
    }   
};