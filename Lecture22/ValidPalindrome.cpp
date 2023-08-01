#include<bits/stdc++.h>
using namespace std;

/*  Problem Statement - 125. Valid Palindrome

    A phrase is a palindrome if, after converting all uppercase 
    letters into lowercase letters and removing all non-alphanumeric 
    characters, it reads the same forward and backward. Alphanumeric 
    characters include letters and numbers.

    Given a string s, return true if it is a palindrome, or false otherwise.

    Example 1:
    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.

    Example 2:
    Input: s = "race a car"
    Output: false
    Explanation: "raceacar" is not a palindrome.

    Example 3:
    Input: s = " "
    Output: true
    Explanation: s is an empty string "" after removing n
    on-alphanumeric characters.
    Since an empty string reads the same forward and backward, 
    it is a palindrome.

*/

// Link to Leetcode [https://leetcode.com/problems/valid-palindrome/description/]

class Solution {
public:
    bool isPalindrome(string s) {

        int start=0, end = s.length()-1;
        while(start<=end){
                // in special character condition
        // if(s[start] < '0' || s[start] > '9' && s[start] < 'A'||s[start]>'Z' && s[start]<'a'  || s[start] > 'z'){
        if(!((s[start]>='a'&&s[start]<='z')||(s[start]>='A'&&s[start]<='Z')||(s[start] >='0'&& s[start]<='9'))){
            start++;
            continue;
        }
        // if(s[end]<'0'||s[end]>'9'&&s[end]<'A'||s[end]>'Z'&& s[end]<'a'||s[end]>'z'){
        if(!((s[end]>='a'&&s[end]<='z')||(s[end]>='A'&&s[end]<='Z')||(s[end] >='0'&& s[end]<='9'))){
            end--;
            continue;
        }
        
        // convert uppercase to lowercase
        if(s[start] <= 'Z' && s[start] >= 'A'){
            s[start] = s[start] + 'a' - 'A';
        }if(s[end] <= 'Z' && s[end] >= 'A'){
            s[end] = s[end] + 'a' - 'A';
        }
        // check similar elements
        if(s[start] != s[end]){
            return false;
        }else{
            start++;
            end--;
        }

        }
        return true;
    }
};


// class Solution {
// public:
//     bool isPalindrome(string s) {
//        int start=0;
//        int end=s.size()-1;
//        while(start<=end){
//            if(!isalnum(s[start])){start++; continue;}
//            if(!isalnum(s[end])){end--;continue;}
//            if(tolower(s[start])!=tolower(s[end]))return false;
//            else{
//                start++;
//                end--;
//            }
//        }
//        return true;
// }
// };