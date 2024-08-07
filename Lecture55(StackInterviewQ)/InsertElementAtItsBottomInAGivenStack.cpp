#include <bits/stdc++.h>
using namespace std;

/*  Problem statement - Insert An Element At Its Bottom In A Given Stack

    You are given a stack/deque of integers 'MY-STACK' and an integer ‘X’. Your task is to insert ‘X’ to the bottom of ‘MY-STACK’ and return the updated stack/deque.

    Note :
    If ‘MY_STACK’ = [7, 1, 4, 5], then the first element represents the element at the bottom of the stack and the last element represents the element at the top of the stack.
    For Example :
    Let ‘MY_STACK’ = [7, 1, 4, 5] and ‘X’ = 9. So, ‘MY_STACK’ after insertion becomes [9, 7, 1, 4, 5].

    Link to codingNinjas [https://www.naukri.com/code360/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio]
*/

void insertEleAtBottomRecursion(stack<int> &stk, int element){
    if(stk.empty()){
        stk.push(element);
        return;
    }

    int n = stk.top();
    stk.pop();

    insertEleAtBottom(stk, element);

    stk.push(n);
};

// simple!
int main(){
    stack<int> temp;

    temp.push(1);
    temp.push(2);
    temp.push(3);
    temp.push(4);
    temp.push(5);

    stack<int> temp2 = temp;

    // push all the elements into a temporary/auxilary stack
    while (!myStack.empty()){
        temp.push(myStack.top());
        myStack.pop();
    }

    // push the element (that we wanted to insert at the bottom) into the original stack
    myStack.push(x);

    // push all the elements back from temporary/auxilary stack to the original stack
    while (!temp.empty()){
        myStack.push(temp.top());
        temp.pop();
    }

    return myStack;

    // approach 2 - using recursion
    insertEleAtBottomRecursion(temp2, 9);
    while(!temp2.empty()){
        cout << temp2.top() << " ";
        temp2.pop();
    }
}