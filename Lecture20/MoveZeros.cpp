#include<bits/stdc++.h>
using namespace std;

// Problem Statement - 283. Move Zeroes
/*  Given an integer array nums, move all 0's to the end of it while maintaining the 
    relative order of the non-zero elements.
    Note that you must do this in-place without making a copy of the array.

    Example 1:
    Input: nums = [0,1,0,3,12]
    Output: [1,3,12,0,0]

    Example 2:
    Input: nums = [0]
    Output: [0]
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0, last = nums.size()-1;
        for(int i=0; i<=last; i++){
            if(nums.at(i) != 0){
                swap(nums.at(i), nums.at(count));
                count++;
            }
        }
    }
};