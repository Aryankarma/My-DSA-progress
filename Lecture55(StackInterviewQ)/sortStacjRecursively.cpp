#include <bits/stdc++.h>
using namespace std;

/*  Problem Statement - Sort a stack

    You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.

    We can only use the following functions on this stack S.

    is_empty(S) : Tests whether stack is empty or not.
    push(S) : Adds a new element to the stack.
    pop(S) : Removes top element from the stack.
    top(S) : Returns value of the top element. Note that this function does not remove elements from the stack.
        
    Note :
    1) Use of any loop constructs like while, for..etc is not allowed.
    2) The stack may contain duplicate integers.
    3) The stack may contain any integer i.e it may either be negative, positive or zero.

    Link to codingNinjas [https://www.naukri.com/code360/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio]
*/

void sortedInsert(stack<int> &stk, int element){
    if ((!stk.empty() && stk.top() <= element) || stk.empty()){
        stk.push(element);
        return; 
    }else{
        int tempEle = stk.top();
        stk.pop();
        sortedInsert(stk, element);
        stk.push(tempEle);
    }
};

void sortStack(stack<int> &stk){
    if(stk.empty()){
        return;
    }

    int topElement = stk.top();
    stk.pop();

    sortStack(stk);

    sortedInsert(stk, topElement);
};

int main(){
    stack<int> s;

    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    sortStack(s);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}