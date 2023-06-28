#include<bits/stdc++.h>
using namespace std;

/*  Problem -  Intersection of two sorted arrays...

    You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order. You have to find the intersection of these two arrays.

    Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.
    Note :

    1. The length of each array is greater than zero.
    2. Both the arrays are sorted in non-decreasing order.
    3. The output should be in the order of elements that occur in the original arrays.
    4. If there is no intersection present then return an empty array.
*/

// Link to CodingNinjas [https://www.codingninjas.com/studio/problems/intersection-of-2-arrays_1082149?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1]

#include<vector>
using namespace std;
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m){
	int i=0, j=0;
    vector<int> ans;
    while(i<n && j<m){
    if(arr1[i]>arr2[j]){
      j++;
    }else if (arr1[i]<arr2[j]){
  		i++;
    }else{
    	ans.push_back(arr1[i]);
      i++;
      j++;
    } 
  }    
    return ans;
}