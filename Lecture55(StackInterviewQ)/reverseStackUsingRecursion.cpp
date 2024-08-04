#include <bits/stdc++.h>
using namespace std;

/*  Problem Statement - Reverse Stack Using Recursion

    Reverse a given stack of 'N' integers using recursion. You are required to make changes in the input parameter itself.

    Note: You are not allowed to use any extra space other than the internal stack space used due to recursion.

    Example:
    Input: [1,2,3,4,5]
    Output: [5,4,3,2,1] 

    Link to codingNinjas [https://www.naukri.com/code360/problems/reverse-stack-using-recursion_631875?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio]
*/

void insertatbottom(stack<int> &stk, int element){
    if(stk.empty()){
        stk.push(element);
        return;
    }

    int n = stk.top();
    stk.pop();

    insertatbottom(stk, element);

    stk.push(n);
};

void reverseStackWRecursion(stack<int> &stk){
    if(stk.empty()){
        return;
    }

    int topElement = stk.top();
    stk.pop();

    reverseStackWRecursion(stk);

    insertatbottom(stk, topElement);
};

int main(){
    stack<int> s;

    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    reverseStackWRecursion(s);
    
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}