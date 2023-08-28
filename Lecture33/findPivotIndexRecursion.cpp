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

int findPivot(int arr[], int size, int left, int right, int pivot, int leftSum, int rightSum){
    // cout << "iteratizzon 1" << endl;

    // base case
    if(pivot > size){
        return -1;
    }
    if(left < pivot){   // Sum of left side elements 
        // cout << "leftSum : " << leftSum << " left : " << left << " pivot: " << pivot << endl;
        return findPivot(arr, size, left+1, right, pivot, leftSum + arr[left], rightSum);
    }if(right > pivot){ // Sum of right side elements
        // cout << "rightSum : " << rightSum << " Right : " << right << " pivot: " << pivot << endl;
        // rightSum = rightSum + arr[right];
        return findPivot(arr, size, left, right-1, pivot, leftSum, rightSum + arr[right]);
    }
    if(leftSum == rightSum){
        return pivot;   
    }else{
        // next iteration
        // cout << "iteration 4" << endl;
        return findPivot(arr, size, 0, size, pivot+1, 0, 0);
    }
}

int findPivot(int arr[], int size, int index, int leftSum, int rightSum) {
    if(index == size) {
        if(leftSum == rightSum) {
            return(index - 1);
        }
        return -1;
    }
    
    int pivotIndex = findPivot(arr, size, index + 1, leftSum + arr[index], rightSum);
    return (pivotIndex != -1) ? pivotIndex : findPivot(arr, size, index + 1, leftSum, rightSum + arr[index]);
}

int main(){
    int arr[7] = {1,0,0,0,0,0,0};
    int size = 7-1;
    cout << findPivot(arr, size, 0, size, 0, 0, 0) << endl;
}