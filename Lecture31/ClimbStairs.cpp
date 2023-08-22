#include<bits/stdc++.h>
using namespace std;

/*  Problem statement - 
    You have been given a number of stairs. Initially, you are at the 0th stair, and you need 
    to reach the Nth stair. Each time you can either climb one step or two steps. You are 
    supposed to return the number of distinct ways in which you can climb from the 0th step 
    to Nth step.
    
    Example : We can climb one step at a time i.e. {(0,1),(1,2),(2,3)} or we can climb the first 
    two-step and then one step i.e. {(0,1),(1,3)} or we can climb the first one step and then 
    two step i.e. {(0,1),(1,3)}.
*/

// Link to codingNinjas - [https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_10]

// codingNinjas solution

#include <bits/stdc++.h>
int countDistinctWays(int nStairs) {
  // base case
  if (nStairs == 0)
    return 1;
  if (nStairs < 0)
    return 0;

  return countDistinctWays(nStairs-1) + countDistinctWays(nStairs-2);
}