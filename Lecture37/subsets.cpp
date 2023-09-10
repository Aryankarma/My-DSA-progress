#include<bits/stdc++.h>
using namespace std;

/*  problem - 78. Subsets
    Given an integer array nums of unique elements, return all possible subsets (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.

    Example 1:
    Input: nums = [1,2,3]
    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

    Example 2:
    Input: nums = [0]
    Output: [[],[0]]
*/

// Problem link [https://leetcode.com/problems/subsets/description/]
// LeetCode solution
class Solution {
private:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int> >& answer) {
        // base case
        if(index >= nums.size()) {
            answer.push_back(output);
            return ;
        }
        
        // for exclude
        solve(nums, output, index+1, answer);

        // for include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, answer);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > answer;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, answer);
        return answer;
    }
};


// vs code
void solveSubsets(vector<int> arr, vector<vector<int>> &outer, vector<int> &inner, int index){
    // base case
    if(index >= arr.size()){
        outer.push_back(inner);
        return ;    
    }

    // for exclude
    solveSubsets(arr, outer, inner, index+1);

    // for include
    int elememt = arr[index];
    inner.push_back(elememt);
    solveSubsets(arr, outer, inner, index+1);
}

int main(){
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    vector<vector<int>> outer;
    vector<int> inner;
    int index=0;
    solveSubsets(arr, outer, inner, index);
    for (int i = 0; i < outer.size(); i++) {
        for (int j = 0; j < outer[i].size(); j++) {
            cout << outer[i][j] << " ";
        }
        cout << endl;
    }
}