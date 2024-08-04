/* Problem statement - two stacks

    Design a data structure, which represents two stacks using only one array common for both stacks. The data structure should support the following operations:

    push1(NUM) - Push ‘NUM’ into stack1.
    push2(NUM) - Push ‘NUM’ into stack2.
    pop1() - Pop out a top element from stack1 and return popped element, in case of underflow return -1.
    pop2() - Pop out a top element from stack2 and return popped element, in case of underflow return -1.
    There are 2 types of queries in the input

    Type 1 - These queries correspond to Push operation.
    Type 2 - These queries correspond to Pop operation.
    Note:

    1. You are given the size of the array.

    2. You need to perform push and pop operations in such a way that we are able to push elements in the stack until there is some empty space available in the array.

    3. While performing Push operations, do nothing in the situation of the overflow of the stack.

    Link to codingNinjas [https://www.naukri.com/code360/problems/two-stacks_983634?leftPanelTabValue=PROBLEM]

*/

// solution

#include <bits/stdc++.h>
class TwoStack{

public:
    int *arr;
    int size;
    int top;
    int top2;

    TwoStack(int s){
        this->size = s;
        this->arr = new int[s];
        this->top = -1;
        this->top2 = size;
    }

    // Push in stack 1.
    void push1(int num)
    {
        if (top2 - top > 1)
        {
            top++;
            arr[top] = num;
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        if (top2 - top > 1)
        {
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        if (top >= 0)
        {
            int element = arr[top];
            top--;
            return element;
        }
        else
        {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        if (top2 < size)
        {
            int element = arr[top2];
            top2++;
            return element;
        }
        else
        {
            return -1;
        }
    }
};