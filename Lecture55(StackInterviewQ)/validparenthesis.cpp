#include<bits/stdc++.h>
using namespace std;

/*  Probelem statement - Valid Parentheses

    You're given a string 'S' consisting of "{", "}", "(", ")", "[" and "]" .

    Return true if the given string 'S' is balanced, else return false.

    For example:
    'S' = "{}()".

    There is always an opening brace before a closing brace i.e. '{' before '}', '(' before ').
    So the 'S' is Balanced.

    Link to CodingNinjas [https://www.naukri.com/code360/problems/valid-parenthesis_795104?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio]
*/

int main(){
    string s = "[{()(){[]}{}]"; // balanced

    // approach 1 without stack
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    for (int i = 0; i < s.length(); i++){
        if (s[i] == '{'){
            count1++;
        }else if (s[i] == '}'){
            count1--;
        }else if (s[i] == '('){
            count2++;
        }else if (s[i] == ')'){
            count2--;
        }else if (s[i] == '['){
            count3++;
        }else if (s[i] == ']'){
            count3--;
        }
    }

    if (count1 == 0 && count2 == 0 && count3 == 0){
        return true;
    }else{
        return false;
    }

    // approach 2 using stack

    stack<char> stk;

    for (int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stk.push(s[i]);
        }else if (stk.empty()){
            cout << "unbalanced" << endl;
        }else{
            char top = stk.top();
            if ((s[i] == ')' && top == '(') || 
                (s[i] == ']' && top == '[') || 
                (s[i] == '}' && top == '{') )
                {
                    stk.pop();
            }else{
                cout << "unbalanced 2" << endl;
            }
        }
    }
    if(stk.empty()){
        cout << "balanced" << endl;
    }else{
        cout << "unbalanced" << endl;
    }

}