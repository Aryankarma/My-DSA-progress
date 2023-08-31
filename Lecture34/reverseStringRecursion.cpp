#include<bits/stdc++.h>
using namespace std;

string reverse(string name,int i,int j){
    if(i>=j){
        return name;
    }
    char temp = name[i];
    name[i] = name[j];
    name[j] = temp;
    // swap(name[i], name[j])
    return reverse(name, ++i, --j);
}

int main(){
    string name = "Aryan";
    int size = name.length();
    cout << reverse(name, 0, size-1) << endl;
}