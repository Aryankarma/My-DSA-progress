#include<bits/stdc++.h>
#include<stdio.h>
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

int binary(vector<int> vect, int size,int n){
    int start=0, end=size, mid=start+(end-start)/2, num=n;

    while(start<end){
        if(((vect[mid]*vect[mid]) < num) && ((vect[mid+1]*vect[mid+1]) > num)){
            return vect[mid];
            break;    
        }else if((vect[mid]*vect[mid]) > num){
            end = mid;
        }else if((vect[mid]*vect[mid]) < num){
            start = mid+1;
        }else if((vect[mid]*vect[mid]) == num){
            return vect[mid];
            break;
        }
        mid = start + (end-start)/2;
    }
    return 0;
};


int main(){
    int n = 26;
    vector<int> vect;

    for(int i=0;i<=n/2;i++){
        vect.push_back(i);
    }
    int ans = binary(vect, vect.size(), n);
    cout << ans;
}