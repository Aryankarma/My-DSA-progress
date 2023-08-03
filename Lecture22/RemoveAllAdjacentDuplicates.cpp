#include<bits/stdc++.h>
using namespace std;

/*  problem statement - 1047. Remove All Adjacent Duplicates In String
    
    You are given a string s consisting of lowercase English letters. A duplicate 
    removal consists of choosing two adjacent and equal letters and removing them.

    We repeatedly make duplicate removals on s until we no longer can.

    Return the final string after all such duplicate removals have been made. It 
    can be proven that the answer is unique.

    Example 1:
    Input: s = "abbaca"
    Output: "ca"
    Explanation: 
    For example, in "abbaca" we could remove "bb" since the letters are adjacent 
    and equal, and this is the only possible move.  The result of this move is 
    that the string is "aaca", of which only "aa" is possible, so the final 
    string is "ca".
    
    Example 2:
    Input: s = "azxxzy"
    Output: "ay"

*/

// Link to LeetCode [https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/]

// Leetcode solution

// using stack
class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        int i=0;

        while(i<s.length()){
            if(ans.empty() || s[i] != ans.back()){
                ans.push_back(s[i]);
            }else{
                ans.pop_back();
            }
            i++;
        }
    return ans;
    }
};




// Wrong approach
// bool checkAdj(string a, int i ,int j, char temp){
//     while(i<j){
//         if(temp == a[j]){
//             j--;
//         }else{
//             return false;
//         }
//         if(i>=j){
//             return true;
//         }
//     }
//     return false;
// }

// int main(){
//     string a = "abbbaca";
//     int i=0, j=a.length();
//     int count=0;
//     while(i<j){
//         if(a[i] == a[j]){
//             char temp = a[i];
//             if(checkAdj(a, i, j, temp)){
//                 a.erase(i,j);
//                 cout << a << endl;
//             }else{
//                 count++;
//                 i++;
//             }
//         }else{
//             j--;
//         }
//     }
// }


