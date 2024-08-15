#include <bits/stdc++.h>
using namespace std;

int main(){
    string str = "{}{}";

    if(str.length() % 2 != 0) return -1;

    stack<char> stk;
    for(int i=0; i<str.length(); i++){
        char ch = str[i];

        if (ch == '{') {
            stk.push(ch);
        }else if (!stk.empty() && stk.top() == '{'){
            stk.pop();
        }else{
            stk.push(ch);
        }
    }

    int openBracket = 0;
    int closeBracket = 0;

    while(!stk.empty()){
        if(stk.top() == '{'){
            closeBracket++; 
        }else{
            openBracket++;
        }
        stk.pop();
    }

    cout << (openBracket + 1) / 2 + (closeBracket + 1) / 2 << endl;
}