#include <bits/stdc++.h>
using namespace std;

/*  Problem statement - Delete middle element from a stack

    You are having a stack "ARR" of size 'N+1', your task is to delete the middlemost element so that the size of resulting stack is 'N'.

    A stack is a linear data structure where both insertion and deletion of elements take place at the top. It follows FILO (First In Last Out) or LIFO (Last In First Out) approaches. Books piled on top of each other is an example of a stack, where you can only remove a single book at a time, which is at the top of the stack. Likewise, you can only add a single book at a time, on the top of the stack only.

    Example :-
    INPUT : ARR [ ] = [ 1 , 2 , 3 , 4 , 5 ] , N = 4
    OUTPUT: ARR [ ] = [ 1 , 2 , 4,  5 ]

    The above example contains an odd number of elements, hence the middle element is clearly the (N+1) / 2th element, which is removed from the stack in the output.

    INPUT : ARR [ ] = [ 5, 6, 7, 8 ] , N = 3
    OUTPUT: ARR [ ] = [ 5, 7, 8 ]

    The above example contains an even number of elements, so out of the two middle elements, we consider the one which occurs first. Hence, the middle element would be ((N+1) / 2 - 1) element, which is 6 and is removed from the stack in the output.

    Link to codingninjas [https://www.naukri.com/code360/problems/delete-middle-element-from-stack_985246?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio]

*/

// a bit confusing if we run this on both vs & codingNinjas, the way arrays are being constructed is different.

int main(){
    stack<int> s;
    stack<int> temp;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    int middleElement = ((s.size() + 1) / 2 - 1);

    for (int i = 0; i < middleElement; i++){
        temp.push(s.top());
        s.pop();
    }

    s.pop();

    while (!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }

    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}