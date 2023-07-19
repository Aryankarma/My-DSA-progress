#include<bits/stdc++.h>
using namespace std;

/*  Problem - 1009 Complement of Base 10 Integer

    The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

    For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
    Given an integer n, return its complement.

*/

// Link to Leetcode [https://leetcode.com/problems/complement-of-base-10-integer/]

/*
    Solution breakdown - we need to change only the last few digits of n, which we can simply do by using the not operator (~). the catch is, what could be done to only change some last digits of the binary representation.
    Step 1 - well have to create a mask where the value will be - 0000000000...00111 (if t's 5) or 0000000000...01111 (if t's 15), basically to create this mask we'll follow step 2 - initialise mask with 0, left shift it to add more 0's and then OR(|) it by 1 to make the last digit 1.
    step 3 - repeat this untill our copy of main decimal number gets 0, to do that we can simply right shift it by 1;
    step 4 - when we have our mask, we can simply AND(&) it by the NOT(~) of decimal number = ~decimal & mask; 
*/

class Solution {
public:
    int bitwiseComplement(int n) {
        int m=n;
        int mask=0;
        if(n == 0){
            return 1;
        }
        while(m!=0){
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
        int ans = (~n) & mask;
        return ans;
    }
};