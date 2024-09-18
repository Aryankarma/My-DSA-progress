#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;   // integer data
    Node *next; // pointer variable "add" that stores the address of object

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertattail(Node *&tail, int data){
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head){
    Node *current = head;

    while (current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// stack with array
class Stack{

public:
    int *arr;
    int curr;
    int size;

    Stack(int size){
        this->arr = new int[size];
        this->size = size;
        this->curr = -1;
    }

    void push(int element){
        if (curr >= size - 1){
            cout << "stack overflow" << endl;
        }else{
            curr++;
            arr[curr] = element;
        }
    };

    void pop(){
        if (curr == -1){
            cout << "stack underflow" << endl;
        }else{
            curr--;
        }
    }

    int top(){
        if (curr == -1){
            cout << "stack is empty" << endl;
            return 0;
        }else{
            return arr[curr];
        }
    }

    bool empty(){
        if (curr == -1){
            return true;
        }else{
            return false;
        }
    }
};

// stack with vector
class StackV{
public:
    vector<int> vect;

    void push(int element){
        vect.push_back(element);
    }

    void pop(){
        if (vect.empty()){
            cout << "stack is empty, can't pop" << endl;
        }else{
            vect.pop_back();
        }
    }

    bool empty(){
        if (vect.empty()){
            return true;
        }
        else{
            return false;
        }
    }

    int top(){
        if (vect.empty()){
            return -999;
        }
        else{
            return vect.back();
        }
    }
};

// stack with LinkedList
class StackL{
private:
    Node *topNode;
    Node *bottomNode;

public:
    StackL(){
        topNode = nullptr;
        bottomNode = nullptr;
    };

    void push(int number){
        if (topNode == NULL && bottomNode == NULL){
            Node *temp = new Node(number);
            topNode = temp;
            bottomNode = temp;
        }else{
            Node *temp = new Node(number);
            temp->next = topNode;
            topNode = temp;
        }
    }

    void pop(){
        if (topNode == NULL && bottomNode == NULL){
            cout << "stack underflow" << endl;
        }else{
            Node *temp = topNode;
            topNode = topNode->next;
            delete temp;
            if (topNode == NULL){
                bottomNode = nullptr;
            }
        }
    }

    int top(){
        if (topNode == NULL && bottomNode == NULL){
            cout << "stack is empty" << endl;
            return 0;
        }else{
            return topNode->data;
        }
    }

    bool empty(){
        if (topNode == NULL && bottomNode == NULL){
            return true;
        }
        else{
            return false;
        }
    }
};

void stackDeclaration(){

    // initializing a stack
    stack<int> s;

    // pushing elements into stack
    s.push(1);
    s.push(2);
    s.push(3);

    // printing the element on top
    cout << "top element on stack : " << s.top() << endl;

    // popping elements from stack
    s.pop();

    cout << "top element on stack after pop : " << s.top() << endl;

    // empty check: 0 -> false, 1 -> true
    cout << s.empty() << endl;
};

void stackImplementation(){

    StackL myOwnStack;

    myOwnStack.push(1);
    myOwnStack.push(2);
    myOwnStack.push(3);
    myOwnStack.push(4);
    myOwnStack.push(5);
    // myOwnStack.push(8); //  for stack overflow

    myOwnStack.pop();
    myOwnStack.pop();
    myOwnStack.pop();
    myOwnStack.pop();
    myOwnStack.pop();
    myOwnStack.pop(); // for stack underflow

    cout << myOwnStack.top() << endl;

    cout << myOwnStack.empty() << endl;
};

int main(){
    // Stacks are a type of container adaptors with LIFO(Last In First Out) type of working, where a new element is added at one end(top) and an element is removed from that end only.Stack uses an encapsulated object of either vector or deque(by default) or list(sequential container class) as its underlying container, providing a specific set of member functions to access its elements.

    // using stack - operations - push, pop, empty, top
    // stackDeclaration()

    // now let's see how we can create our own data structure just like stack, the stack class you see above is an example of it (array based implementation, can also be done by LL, vector, dequeue)
    stackImplementation();
}