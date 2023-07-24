/*  Problem Statement

    In Ninja Land, there is a famous restaurant named ‘CookingNinjas’. There are ‘N’ cooks 
    in ‘CookingNinjas’ numbered from 0 to N-1. Each cook has rank ‘R’ (1 <= R <= 10).
    A cook with a rank ‘R’ can prepare 1 dish in the first ‘R’ minutes, 1 more dish in the 
    next ‘2R’ minutes, 1 more dish in next ‘3R’ minutes, and so on (A cook can only make 
    complete dishes) For example if a cook is ranked 2. He will prepare one dish in 2 
    minutes, one more dish in the next 4 mins and one more in the next 6 minutes hence in a 
    total of 12 minutes he can make 3 dishes, Note, In 13 minutes also he can make only 3 
    dishes as he does not have enough time for the 4th dish).

    One day ‘CookingNinjas’ receive an order of ‘M’ dishes that they need to complete as 
    early as possible. You are given an integer array ‘rank’ of size ‘N’ in which ‘rank[i]’ 
    gives ‘rank’ of ith cook and an integer ‘M’, You need to find out the minimum times 
    required to complete this order of ’M’ dishes.

    Note
    One dish can be prepared by only one cook, however, two or more cooks can simultaneously 
    prepare different dishes.

    For Example
    Let ‘N’ = 4,  ‘ranks’ = [1, 2, 3, 4] and ‘M’ = 11.  Then the minimum time required to 
    cook 11 dishes will be 12 minutes.  The cooks should prepare dishes in the following 
    manner -:
    
    Cook-0 prepare 4 dishes in 10 minutes i.e (1 dish in 1 minute, 1 more dish in next 2 
    minutes, 1 more dish in next 3 minutes, 1 more dish in next 4 minutes).
    
    Cook-1 prepare 3 dishes in 12 minutes i.e (1 dish in 2 minutes, 1 more dish in 4 minutes, 
    1 more dish in 6 minutes).
    
    Cook-2 prepare 2 dishes in 9 minutes i.e (1 dish in 3 minutes, 1 more dish in the 
    next 6 minutes).
    
    Cook-3 prepare 2 dishes in 12 minutes i.e (1 dish in 4 minutes, 1 more dish in the next 
    8 minutes).

    If all four cooks work simultaneously then they can prepare(4 + 3 + 2 + 2 = 11) dishes 
    in 12 minutes. And it is the minimum possible time.

    example 2:

    input-          output
    1 1             10
    10              
    
    example 3:  

    input-                                                output
    4 (size of array) 11 (number of dishes)               12 (minimum time in minutes)
    1 2 3 4 (array representing the rank of ith cook)        
*/

// CodingNinja Link - [https://www.codingninjas.com/studio/problems/cooking-ninjas_1164174?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2]



#include <bits/stdc++.h>

bool isPossible(vector<int> rank, int m, int mid){
    int dishes = 0;
    for (int i = 0; i < rank.size(); i++){
        int time = 0;
        int nextTime = rank[i];
        while(time+nextTime<=mid){
            dishes++;
            time += nextTime;
            nextTime = nextTime + rank[i];
            if (dishes >= m)
                return true;
        }
    }
    return false;
}

int minCookTime(vector<int> &rank, int m){
    int ans = -1;
    sort(rank.begin(), rank.end());
    int s = 0, e = (rank[0]*m*(m+1)/2);
    while (s <= e){
        int mid = s + (e - s) / 2;
        if (isPossible(rank, m, mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}











// #include<bits/stdc++.h>
// using namespace std;

// bool possibleChance(vector<int> rnk, int mid, int m){
//     int sum=0, i=0, rank=0, dishes=0;
//     while(sum <= mid){
//     cout << "check recursive "<< endl;
//         i++;
//         sum = (i*rnk.at(rank)) + sum;
//         cout << "This is rank : " << rnk.at(rank) << endl;
//         if(sum > mid){
//             if(rank == rnk.size()-1){
//                 cout << "This is false                 case..."<< endl;
//                 rank++,i=0,sum=0;
//                 return false;
//             }
//             dishes = dishes+i;
//             if(dishes >= m){
//                 cout << "This is true               case..."<< endl;
//                 return true;
//             }
//                 rank++,i=0,sum=0;
//         }
//     }
//     return false;
// }

// int main(){
//     vector<int> rnk;
//     rnk.push_back(1);
//     rnk.push_back(2);
//     rnk.push_back(3);
//     rnk.push_back(4);
//     sort(rnk.begin(), rnk.end());
//     int m = 11;
//     int end  =  (rnk[0]*m*(m+1)/2);
//     int start=0, mid=start+(end-start)/2, ans;
//     while(start<=end){
//         if(possibleChance(rnk, mid, m)){
//             ans = mid;
//             end = mid-1;
//         }else{
//             start = mid+1;
//         }
//         mid = start+(end-start)/2;
//     }
//     cout << ans << " ";
// }

