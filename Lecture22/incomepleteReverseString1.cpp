#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "This is my java code";
    string temp, s2;
    int i=0;
    while(s[i] != '\0'){
        if(s[i] == ' '){
            s2 = temp + s2;
            temp = " ";
            i++;
        }
        temp = temp + s[i];
        i++;
    }
    cout << s2 << endl;
    // cout << temp << endl;
}