#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<char> original;
    stack<char> reverse;
    string name = "1";  
    string reverseString = "";

    int length = name.length();

    for (int i = length-1; i >= 0; i--){
        original.push(name[i]);
    };

    while (!original.empty()){
        reverse.push(original.top());
        original.pop(); 
    }

    while(!reverse.empty()){
        reverseString = reverseString + reverse.top();
        reverse.pop();
    }

    cout << reverseString << endl;
}