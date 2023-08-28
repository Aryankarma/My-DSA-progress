#include<bits/stdc++.h>
using namespace std;

/*  Problem - Find square root using binary search or in time complexity O(logn)

    Given a non-negative integer x, return the square root of x rounded down to the 
    nearest integer. The returned integer should be non-negative as well.

    You must not use any built-in exponent function or operator.

    For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
*/

// Link to coding ninjas [https://www.codingninjas.com/studio/problems/square-root_893351?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2]
// Link to LeetCode [https://leetcode.com/problems/sqrtx/]

// Note - this is a self made begin-to-code solution, it does not show the exact square root value but working

int squareRoot(int n, int start, int end){
    int mid = (start + (end-start)/2);
    if((mid*mid) > n){
        return squareRoot(n, start, mid);
    }else if((mid*mid) < n){
        return squareRoot(n, mid, end);
    }else if((mid*mid) == n){
        return mid;
    }else {
        return -1;
    }
}

int main(){
    int n = 144;
    cout << squareRoot(n, 0, n) << endl;
}