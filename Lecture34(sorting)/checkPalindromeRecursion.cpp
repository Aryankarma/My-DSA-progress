#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string name,int i ,int size){
    if(i>=size){
        return true;
    }
    if(name[i] != name[size]){
        return false;
    }
    return checkPalindrome(name, ++i, --size);
}

int main(){
    string name = "aaa3vbvaaa";
    int size = name.length()-1;
    cout << checkPalindrome(name, 0, size) << endl;
}
