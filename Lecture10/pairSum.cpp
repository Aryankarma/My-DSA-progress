#include<bits/stdc++.h>
using namespace std;

/*  Problem - Pair sum

    You are given an array/list ‘ARR’ consisting of ‘N’ distinct integers arranged in ascending order. You are also given an integer ‘TARGET’. Your task is to count all the distinct pairs in ‘ARR’ such that their sum is equal to ‘TARGET’.

    Note:
    1. Pair (x,y) and Pair(y,x) are considered as the same pair. 
    2. If there exists no such pair with sum equals to 'TARGET', then return -1.

*/


// Link to CodingNinjas [https://www.codingninjas.com/studio/problems/pair-sum_697295?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1&leftPanelTab=0]

#include <bits/stdc++.h>
vector<vector<int>> pairSum(vector<int> &arr, int s){
   int i=0, j=arr.size();
   vector< vector<int> > value;
      for(int i=0;i<arr.size(); i++ ){
   		for(int j = i+1; j<arr.size(); j++) {
                  if (arr[i] + arr[j] == s) {
                    vector<int> temp;
                    temp.push_back(min(arr[i], arr[j]));
                    temp.push_back(max(arr[i], arr[j]));
                    value.push_back(temp);
                  }
                }
      }
      sort(value.begin(), value.end());
      return value;
}

// #include <bits/stdc++.h>
// vector<vector<int>> pairSum(vector<int> &arr, int s){
//    int i=0, j=arr.size();
//    vector<int> value;
//    while(int i<j){
//       if(arr[i] + arr[j] < s){
//          i++;
//       }
//       else if(arr[i] + arr[j] > s){
//         j--;
//       }
//       else if(arr[i] + arr[j] == s){
//          vector<int> dump;
//          dump.push_back(min(arr[i], arr[j] ));
//          dump.push_back(max(arr[i], arr[j] ));
//          value.push_back(dump);
//       }
//    }


//    sort(value.begin(), value.end());
//    return value;
// }

// #include <bits/stdc++.h>
// vector<vector<int>> pairSum(vector<int> &arr, int s){
//    vector<vector<int>> value;
//    for(int i=0; i<arr.size(); i++){
//       for(int j=i+1; j<arr.size(); j++){ 
//          if(arr[i] + arr[j] == s){
//             vector<int> temp;
//             temp.push_back(min(arr[i], arr[j]));
//             temp.push_back(max(arr[i], arr[j]));
//             value.push_back(temp);
//          }
//       }
//    }
//    sort(value.begin(), value.end());
//    return value;
// }