#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "a+b+(c+(d*))";

    // wrote this algo but..! this algo can't work on the last test case... 
    int counter = 0;
    map<int, bool> mapping;

    for (int i = 0; i < s.length(); i++){
        if (s[i] == '('){
            counter++;
            mapping[counter] = false;
        }else if (s[i] == ')'){
            counter--;
        }else if (s[i] == '/' || s[i] == '*' || s[i] == '-' || s[i] == '+'){
            if(counter != 0){
                mapping[counter] = true;
            }
        }
    }

    for(int i=1; i<= mapping.size(); i++){
        if(mapping[i] == false){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;

    // approach 2 (using stack)

}