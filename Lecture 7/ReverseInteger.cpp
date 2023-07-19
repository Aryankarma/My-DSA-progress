#include<bits/stdc++.h>
using namespace std;

/*  Problem - 7. Reverse Integer
    Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^(31), 2^(31) - 1], then return 0.
    
    Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

*/

//  Link to LeetCode [https://leetcode.com/problems/reverse-integer/]

class Solution {
public:
    int reverse(int x) {
        int reverse=0;
        while(x!=0){
            int n;
            n = x%10;
            if(reverse > INT_MAX/10 || reverse < INT_MIN/10){
                return 0;
            }
            reverse = (reverse*10) + n ;
            x = x/10;
        }
        return reverse;
    }
};
