/*  Problem statement - Stack Implementation Using Array

    Stack is a data structure that follows the LIFO (Last in First out) principle. Design and implement 
    a stack to implement the following functions:

    1. Push(num): Push the given number in the stack if the stack is not full.
    2. Pop: Remove and print the top element from the stack if present, else print -1.
    3. Top: Print the top element of the stack if present, else print -1.
    4. isEmpty: Print 1 if the stack is empty, else print 0.
    5. isFull: Print 1 if the stack is full, else print 0.

    You have been given ‘m’ operations which you need to perform in the stack. Your task is to 
    implement all the functions of the stack.

    Example:
    We perform the following operations on an empty stack which has capacity 2:
    When operation 1 1 is performed, we insert 1 in the stack.
    When operation 1 2  is performed, we insert 2 in the stack. 
    When operation 2 is performed, we remove the top element from the stack and print 2.
    When operation 3 is performed, we print the top element of the stack, i.e., 3.
    When operation 4 is performed, we print 0 because the stack is not empty.
    When operation 5 is performed, we print 0 because the stack is size 1, which is not equal to its capacity.
*/
// Link to codingNinjas [https://www.naukri.com/code360/problems/stack-implementation-using-array_3210209?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=SUBMISSION]

// Stack class.
class Stack {

public:
  int *arr;
  int curr;
  int size;

  Stack(int capacity) {
    this->arr = new int[capacity];
    this->size = capacity;
    this->curr = -1;
  }

  void push(int num) {
    if (curr >= size - 1) {
      return;
    } else {
      curr++;
      arr[curr] = num;
    }
  }

  int pop() {
    if (curr == -1) {
      return -1;
    } else {
      int temp = arr[curr];
      curr--;
      return temp;
    }
  }

  int top() {
    if (curr == -1) {
      return -1;
    } else {
      return arr[curr];
    }
  }

  int isEmpty() {
    if (curr == -1) {
      return 1;
    } else {
      return 0;
    }
  }

  int isFull() {
    if (curr >= size - 1) {
      return 1;
    } else {
      return 0;
    }
  }
};
