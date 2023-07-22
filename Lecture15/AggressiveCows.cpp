#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
using namespace std;

/*  Problem Statement
    You are given an array 'arr' consisting of 'n' integers which denote the position of a 
    stall.
    You are also given an integer 'k' which denotes the number of aggressive cows.
    You are given the task of assigning stalls to 'k' cows such that the minimum distance 
    between any two of them is the maximum possible.

    Print the maximum possible minimum distance.
    Example:
    Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}
    
    Output: 2
    Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at 
    positions {1, 3}. Here distance between cows is 2.
*/

// Link to CodingNinjas [https://www.codingninjas.com/studio/problems/aggressive-cows_1082559?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2]
// Link to LeetCode [ ]



bool possibleSolution(vector<int> &stalls, int k, int mid){
    int position=stalls[0];
    int count=1; 

    for(int i=0; i<stalls.size();i++){
        if(stalls[i]-position >= mid){
            count++;
            if(count == k){
            return true;
        }
            position = stalls[i];
        }
    }    
    return false;  
}


int aggressiveCows(vector<int> &stalls, int k){
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int start = 0; 
    int maximum =-1, ans;

    for(int i=0; i<stalls.size(); i++){
        // if(stalls[i] > end){
        //     end = stalls[i];
        // }
        maximum = max(maximum, stalls[i]);
    }
    int end = maximum;

    int mid = start + (end-start)/2;


    while(start<=end){
        if(possibleSolution(stalls, k, mid)){
            start = mid+1;
            ans = mid;
        }else{
            end = mid-1;
        }
        mid = start+(end-start)/2;
    }
    return ans;
}
