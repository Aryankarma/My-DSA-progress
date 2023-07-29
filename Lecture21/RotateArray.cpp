#include<bits/stdc++.h>
using namespace std;

// Problem Statement - 189. Rotate Array
/*  Given an integer array nums, rotate the array to the right by k steps, where k 
    is non-negative.

    Example 1:

    Input: nums = [1,2,3,4,5,6,7], k = 3
    Output: [5,6,7,1,2,3,4]
    Explanation:
    rotate 1 steps to the right: [7,1,2,3,4,5,6]
    rotate 2 steps to the right: [6,7,1,2,3,4,5]
    rotate 3 steps to the right: [5,6,7,1,2,3,4]

    Example 2:
    Input: nums = [-1,-100,3,99], k = 2
    Output: [3,99,-1,-100]
    Explanation: 
    rotate 1 steps to the right: [99,-1,-100,3]
    rotate 2 steps to the right: [3,99,-1,-100]
*/

// Link to leetcode [https://leetcode.com/problems/rotate-array/]


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v(n);
        int part2 = n-k;
        int j=0;
        for(int i=0; i<n; i++){
            v[(i+k)%n] = nums[i];
        }
        for(int i=0; i<nums.size(); i++){
            nums[i] = v[i];
        }
    }
};


// failed solution
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n=nums.size();
//         vector<int> v(n);
//         int part2 = n-k;
//         int j=0;
//         for(int i=part2; i<n; i++, j++){
//             v[j] = nums[i];
//         }
//         for(int i=0; i<part2; i++,j++){
//             v[j] = nums[i];
//         }
//         for(int i=0; i<nums.size(); i++){
//             nums[i] = v[i];
//         }
//     }
// };