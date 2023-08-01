#include<bits/stdc++.h>
using namespace std;

/*  Problem Statement - Replace Spaces

    You have been given a string 'STR' of words. You need to replace all the 
    spaces between words with “@40”.

    Sample Input 1:
    2
    Coding Ninjas Is A Coding Platform
    Hello World

    Sample Output 1:
    Coding@40Ninjas@40Is@40A@40Coding@40Platform
    Hello@40World
*/
// Link to codingNinjas [https://www.codingninjas.com/studio/problems/replace-spaces_1172172?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_5&leftPanelTab=0]



// VS code solution
int main(){
    string main = "ARYAN KARMA IS THE BEST";
    string ans = "";
    for(int i=0; i<main.length(); i++){
        if(main[i] == ' '){
            ans.push_back('@');
            ans.push_back('4');
            ans.push_back('0');
            i++;
        }
        ans.push_back(main[i]); 
    }

    cout << main << endl;
    cout << ans << endl;
}

// coding ninjas solution
#include <bits/stdc++.h> 
string replaceSpaces(string &str){
string ans = "";
    for(int i=0; i<str.length(); i++){
        if(str[i] == ' '){
            ans.push_back('@');
            ans.push_back('4');
            ans.push_back('0');
            i++;
        }
        ans.push_back(str[i]); 
    }
	return ans;
