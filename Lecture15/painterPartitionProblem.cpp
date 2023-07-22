#include<bits/stdc++.h>
using namespace std;

/*  Given an array/list of length ‘N’, where the array/list represents the boards and each 
    element of the given array/list represents the length of each board. Some ‘K’ numbers of 
    painters are available to paint these boards. Consider that each unit of a board takes 1 
    unit of time to paint.

    You are supposed to return the area of the minimum time to get this job done of 
    painting all the ‘N’ boards under a constraint that any painter will only paint the 
    continuous sections of boards.

    example-

    sample input- 

    4(size of array) 2(number of painters)
    10 20 30 40 (array)

    output -
    60 (minimum time to paint all boxes)
*/

//  description by codingNinjas
// Link to CodingNinjas [https://www.codingninjas.com/studio/problems/painter's-partition-problem_1089557?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=2]
// Link to LeetCode [not same but similar - 1482. Minimum Number of Days to Make m Bouquets]

bool possibleSoln(vector<int> &boards, int size, int k, int mid){
    int painterCounter=1;
    int sum=0;
    for(int i=0; i<size; i++){
        if(boards[i] + sum <= mid){
            sum = sum + boards[i];
        }else{
            painterCounter++;
            sum = boards[i];
            if(painterCounter > k || boards[i] > mid){
                return false;
            }
        }
    }
    return true;
}


int findLargestMinDistance(vector<int> &boards, int k){
    int size = boards.size();
    int sum=0;
    for(int i=0; i<size; i++){
        sum = sum + boards[i];
    }
    int start=0, end = sum, mid=start+(end-start)/2;
    int ans;
    while(start<=end){
        if(size<k){
            return -1;
        }
        if(possibleSoln(boards, size, k, mid)){
            end = mid-1;
            ans = mid;
        }else{
            start = mid+1;
        }
        mid = start + (end - mid)/2;
    }
    return ans;
}