#include<bits/stdc++.h>
using namespace std;

/*  Problem - Triplet sum (3 sum)
    You are given an array/list ARR consisting of N integers. Your task is to find all the  distinct triplets present in the array which adds up to a given number K.
    
    An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists  three indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.

    Note:
    1. You can return the list of values in any order. For example, if a valid triplet is  {1, 2, -3}, then {2, -3, 1}, {-3, 2, 1} etc is also valid triplet. Also, the ordering of different triplets can be random i.e if there are more than one valid triplets, you can return them in any order.
    
    2. The elements in the array need not be distinct.
    
    3. If no such triplet is present in the array, then return an empty list, and the output    printed for such a test case will be "-1".

*/


// Link to CodingNinjas [https://www.codingninjas.com/studio/problems/triplets-with-given-sum_893028?source=youtube&campaign=LoveBabbar_Codestudiovideo1&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudiovideo1&leftPanelTab=0]

// this is an incomplete solution (according to codingninjas)

#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
  vector<vector<int>> value;
    for(int i = 0  ; i<n-2; i++){
   	for(int j = i+1; j<n-1; j++){
    for(int k = j+1; k<n; k++){
        if(arr[i] + arr[j] + arr[k] == K) {
            vector<int> temp;
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);
            temp.push_back(arr[k]);
            value.push_back(temp);
          }
        }
      }
    }
    return value;
}