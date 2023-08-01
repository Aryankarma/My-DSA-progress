#include<bits/stdc++.h>
using namespace std;

/*  Problem statement - Maximum Occuring Character
    
    Given a string str of lowercase alphabets. The task is to find the maximum occurring 
    character in the string str. If more than one character occurs the maximum number of 
    time then print the lexicographically smaller character.

    Example 1:

    Input:
    str = testsample
    Output: e
    Explanation: e is the character which
    is having the highest frequency.
    Example 2:

    Input:
    str = output
    Output: t
    Explanation:  t and u are the characters
    with the same frequency, but t is
    lexicographically smaller.

*/

int main(){ 
    string str = "asfaabasfeeeebcasfftvcgdqd";
    cout << "The name is : " << str << endl;

    int array[26] = {0};
    int temp = 0;
    for(int i=0; i<str.length(); i++){
        temp = str[i] - 97;
        array[temp]++;
    }

    int max = -1;
    for(int i=0; i<26; i++){
        if(array[i] > max){
            // cout << i << " ";
            max = i;
        }
    }
    cout << endl;
    char ans = 'a' + max;
    cout << ans << endl;


    // int i=0;
    // i = str[0] + i;
    // cout <<" i : " << i << endl;
    // i=0;
    // i = str[1] + i;
    // cout <<" i : " << i << endl;

    // for(int i=0; i<str.length(); i++){
    //     int x = str[i] - 97;
    //     arr[x] = arr[x] + 1;
    // }
    // for(int i=0; i<26; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // int maxi =0, position;
    // for(int i=0; i<26; i++){
    //     maxi = max(maxi, arr[i]);
    // }
    // // int ans = position;
    // cout << maxi << endl;
}   

