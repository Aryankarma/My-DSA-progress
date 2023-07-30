#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

/*  Problem statement - Sum of two arrays
    Problem Statement
    You are given two numbers 'A' and 'B' in the form of two arrays (A[] and B[]) of 
    lengths 'N' and 'M' respectively, where each array element represents a digit. You 
    need to find the sum of these two numbers and return this sum in the form of an array.
    Note:

    1. The length of each array is greater than zero.
    
    2. The first index of each array is the most significant digit of the number. For 
    example, if the array A[] = {4, 5, 1}, then the integer represented by this array is 
    451 and array B[] = {3, 4, 5} so the sum will be 451 + 345 = 796. So you need to 
    return {7, 9, 6}.

    3. Both numbers do not have any leading zeros in them. And subsequently, the sum 
    should not contain any leading zeros.
*/

// Link to CodingNinjas [https://www.codingninjas.com/studio/problems/sum-of-two-arrays_893186?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_4&leftPanelTab=0]


// Official solution
#include <bits/stdc++.h>
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
    int num1=0, num2=0, numSol=0,ans;
    vector<int> vect;
    for(int i=0; i<n; i++){
        num1 = num1*10 + a[i];
    }
    for(int i=0; i<m; i++){
        num2 = num2*10 + b[i];
    }
    numSol = num1 + num2;
    while(numSol > 0){
        ans = numSol%10;
        vect.push_back(ans);
        numSol = numSol/10;
    }
    reverse(vect.begin(), vect.end());
    return vect;
}




// int main(){
//     vector<int> a;
//     vector<int> b;

//     a.push_back(1);
//     a.push_back(1);
//     a.push_back(2);
//     a.push_back(2);

//     b.push_back(3);
//     b.push_back(3);
//     b.push_back(4);
//     b.push_back(4);

//     vector<int> vect;

//     int num1=0, num2=0, numSol=0,ans;
//     for(int i=0; i<a.size(); i++){
//         num1 = num1*10 + a[i];
//     }
//     for(int i=0; i<b.size(); i++){
//         num2 = num2*10 + b[i];
//     }
//     numSol = num1 + num2;

//     while(numSol > 0){
//         cout << "this is infinite :" << endl;
//         ans = numSol%10;
//         vect.push_back(ans);
//         numSol = numSol/10;
//     }
//     reverse(vect.begin(), vect.end());

//     for(int i=0; i<vect.size(); i++){
//         cout << vect[i] << " ";
//     }
// }