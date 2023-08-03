#include<bits/stdc++.h>
using namespace std;

/*  problem statement - 567. Permutation in String
    Given two strings s1 and s2, return true if s2 contains a permutation of s1, 
    or false otherwise.

    In other words, return true if one of s1's permutations is the substring of s2.

    Example 1:
    Input: s1 = "ab", s2 = "eidbaooo"
    Output: true
    Explanation: s2 contains one permutation of s1 ("ba")

    Example 2:
    Input: s1 = "ab", s2 = "eidboaoo"
    Output: false
*/

// Link to LeetCode [https://leetcode.com/problems/permutation-in-string/]

// Leetcode solution


class Solution {
bool checkEqual(int arr1[26], int arr2[26]){
    for(int i=0; i<26; i++){
        if(arr1[i] != arr2[i]){
            return 0;
        }
    }
    return 1;
}

public:
  bool checkInclusion(string s1, string s2) {
    int arr1[26] = {0};

    for(int i=0; i<s1.length(); i++){
        int index = s1[i] - 'a';
        arr1[index]++;
    }

    int arr2[26] = {0};
    int windowSize = s1.length(); 
    int i=0; 

    while(i<windowSize && i<s2.length()){
        int index = s2[i] - 'a';
        arr2[index]++;
        i++;
    }

    if(checkEqual(arr1, arr2)){
        return 1;
    }
    
    while(i < s2.length()){
        int index = s2[i] - 'a';
        arr2[index]++;

        int old = s2[i- windowSize];
        index = old - 'a';
        arr2[index]--;   
        i++;
        
        if(checkEqual(arr1, arr2)){
        return 1;
    }
    }
    return 0;
  }
};





// VS code solution
bool arrayIsEqual(int arr1[26], int arr2[26]){
    for(int i=0; i<26; i++){
        if(arr1[i] != arr2[i]){
            return false;
        }
    }
    return true;
}

int main(){
    string s1="ab";
    string s2="eidbsabooo";
    int arr1[26] = {0};

    for(int i=0; i<s1.length(); i++){
        int index = s1[i] - 'a';
        // cout << index << endl;
        arr1[index]++;
    }

    int arr2[26] = {0};
    int windowSize = s1.length();
    string s3;
    
    for(int i=0; i<s2.length(); i++){
        s3 = s2.substr(i, windowSize);

        for(int i=0; i<windowSize; i++){
            int index = s3[i] -'a';
            // cout << s3[i] << " This is arr2 : " << index << endl;
            arr2[index]++;
            // cout << s3[i] << " This is arr2 : " << arr2[index] << endl;
        }

        // cout << "This is s3 : " << s3 << endl;
        // cout << " arr2 : " << arr2[i] << endl;

        // for(int i=0; i<26; i++){
        //     cout << "arr1 : " << arr1[i] << " arr2 : " << arr2[i] << endl;
        // }

        if(arrayIsEqual(arr1, arr2)){
            cout << "It is present" << endl;
            return true;
        }else{
            // arr2[26] = 0;
            for(int i=0; i<26; i++) {
                arr2[i]=0;
            }
            s3="";
            // cout << "It is not present right now" << endl;
        }
    }
    return 0;
}