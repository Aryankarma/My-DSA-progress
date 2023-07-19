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

// int binary(vector<int> vect, int size,int n){
//     int start=0, end=size, mid=start+(end-start)/2, num=n;

//     while(start<end){
//         if(((vect[mid]*vect[mid]) < num) && ((vect[mid+1]*vect[mid+1]) > num)){
//             return vect[mid];
//             break;    
//         }else if((vect[mid]*vect[mid]) > num){
//             end = mid;
//         }else if((vect[mid]*vect[mid]) < num){
//             start = mid+1;
//         }else if((vect[mid]*vect[mid]) == num){
//             return vect[mid];
//             break;
//         }
//         mid = start + (end-start)/2;
//     }
//     return 0;
// };


// int main(){
//     int n = 5;
//     vector<int> vect;

//     for(int i=0;i<=n;i++){
//         vect.push_back(i);
//     }
//     int ans = binary(vect, vect.size(), n);
//     cout << ans;
// }



// new code (better code)
int binary(int n){
    int start = 0, end=n, mid=start+(end-start)/2, ans;

    while(start<=end){
        if((mid*mid) > n){
            end = mid-1;
        }else if((mid*mid) < n){
            start = mid+1;
            ans = mid;
        }else if((mid*mid) == n){
            ans = mid;
            break;
        }
        mid = start + (end-start)/2;
    }
    return ans;
};

int main(){
    int n=144;
    int ans = binary(n);
    cout << ans;

}


// code for more precision in our answer (improper)
// #include <iostream>
// using namespace std;

// int main() {
//     double i = 0.1, store, value = 4, count = 0 ,n=17;
    
//     while(count < 10) {
//     // while(value * value != (n-0.01)) {
//         if (value * value < n) {
//             store = value;
//             count++;
//             if( ((value+i)*(value+i)) < n){
//                 value = value +  i;
//             }else
//             // (value*value > 5)
//             {
//               i = i/10;  
//               value = value + i;
//             }
//         }
//     }
//     cout << store << " ";
//     return 0;
// }