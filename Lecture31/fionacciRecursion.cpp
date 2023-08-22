#include<bits/stdc++.h>
using namespace std;

/*  Problem statement - 509. Fibonacci Number
    The Fibonacci numbers, commonly denoted F(n) form a sequence, called the 
    Fibonacci sequence, such that each number is the sum of the two preceding ones, 
    starting from 0 and 1. That is,

    F(0) = 0, F(1) = 1
    F(n) = F(n - 1) + F(n - 2), for n > 1.
    Given n, calculate F(n).
*/

// Link to Leetcode: [https://leetcode.com/problems/fibonacci-number/description/]

// Leetcode solution

class Solution {
private:
    int fibo(int n){
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        
        return fibo(n-1) + fibo(n-2);
    }
public:
    int fib(int n) {
        return fibo(n);
    }
};