#include<bits/stdc++.h>
using namespace std;

/*  Problem Statement - Check If The String Is A Palindrome

    You are given a string 'S'. Your task is to check whether the string is palindrome 
    or not. For checking palindrome, consider alphabets and numbers only and ignore the 
    symbols and whitespaces.

    Note :String 'S' is NOT case sensitive.
*/

// Link to CodingNinjas [https://www.codingninjas.com/studio/problems/check-if-the-string-is-a-palindrome_1062633?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_5]


int main(){
    char name[10];
    cout << "Enter a name : ";
    cin >> name;

    // taking length
    int i=0;
    while(name[i] != '\0'){
        i++;
    }

    cout << "length is " << i << endl;

    int start=0, end=i-1; 
    while(start <= end){
        if(name[start] == name[end]){
            start++;
            end--;
        }else{
            cout << "This is not palindrome " << endl;
            break;
        }
    }
    cout << "This is palindrome " << endl;
}