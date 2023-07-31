#include<bits/stdc++.h>
using namespace std;

int main(){
    // how to code a string
    char name[10];
    cout << "Enter a name\n";
    cin >> name;
    cout << "Your name is : " << name << endl; 

    // Q.1. Find length of a string
    int i=0;
    while(name[i] != '\0'){
        i++;
    }cout << "Length is : " << i << endl;

    // Q.2. Reverse a string 
    
    while(i>0){
        cout << name[i];
        i--;
    }cout << endl;

}