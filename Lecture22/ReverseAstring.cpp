#include<bits/stdc++.h>
using namespace std;

/*  Problem Statement - 344. Reverse String
    Write a function that reverses a string. The input string is given as an array of 
    characters s.

    You must do this by modifying the input array in-place with O(1) extra memory.

    Example 1:
    Input: s = ["h","e","l","l","o"]
    Output: ["o","l","l","e","h"]

    Example 2:
    Input: s = ["H","a","n","n","a","h"]
    Output: ["h","a","n","n","a","H"]

*/

// Link to LeetCode [https://leetcode.com/problems/reverse-string/description/]

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start=0, end=s.size()-1;
        while(start <= end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};