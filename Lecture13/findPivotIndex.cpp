#include<bits/stdc++.h>
using namespace std;

/*  Problem = Find Pivot Element (sum of it's left == sum of it's right)

    Given an array of integers nums, calculate the pivot index of this array.

    The pivot index is the index where the sum of all the numbers strictly to the left of 
    the index is equal to the sum of all the numbers strictly to the index's right.

    If the index is on the left edge of the array, then the left sum is 0 because there 
    are no elements to the left. This also applies to the right edge of the array.

    Return the leftmost pivot index. If no such index exists, return -1.
*/


// Link to LeetCode [https://leetcode.com/problems/find-pivot-index/description/]

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size=nums.size()-1;
        int total=0, check=0;
        for(int i=0; i<=size; i++){
            total = total + nums[i];
        }
        for(int i=0; i<=size; i++){
            total = total - nums[i];
            if(check == total){
                return i;
            }
            check = check + nums[i];
        }
    return -1;
    }
};