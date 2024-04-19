#include<bits/stdc++.h>
using namespace std;

/*  Problem Statement - Reverse A Doubly Linked List

    You are given a doubly-linked list of size 'N', consisting of positive integers. Now your task is to reverse it and return the head of the modified list.

    Note:
    A doubly linked list is a kind of linked list that is bidirectional, meaning it can be traversed in both forward and backward directions.
    
    Example:
    Input: 
    4
    4 3 2 1

    This means you have been given doubly linked list of size 4 = 4 <-> 3 <-> 2 <-> 1.
    Output: 
    1 2 3 4

    This means after reversing the doubly linked list it becomes 1 <-> 2 <-> 3 <-> 4.
*/

// Link to codingNinjas [https://www.naukri.com/code360/problems/reverse-a-doubly-linked-list_1116098?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker]

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    // constructor
    Node(int value){
        this->data = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
    ~Node(){
        int value = this->data;
        if(next != nullptr){
            delete next;
            next = NULL;
        }
        cout << "Node with value : " << value << " got deleted. " << endl;
    }
};

int getLength(Node* &head){
    
    Node* temp = head;
    int count = 0;

    while(temp != nullptr){
        count++;
    }

    return count;
}

void print(Node* &head){
    Node* temp = head;

    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void printtail(Node* &tail){
    Node* temp = tail;

    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}

void insertathead(int data, Node* &head, Node* tail){
    Node* temp = new Node(data);

    // if the list is empty
    if(head == nullptr){
        head = temp;
        tail = temp;
    }else{
    // the list is not empty

        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertattail(int data, Node* head, Node* &tail){
    Node* temp = new Node(data);

    // if the list is empty
    if(tail == nullptr){

        head = temp;
        tail = temp;
    }else {
    // the list is not empty

        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

Node* reverseDLL(Node* head){
    Node* curr = head;
    Node* prevptr = nullptr;
    Node* nextptr = curr->next;

    while(curr != nullptr){
        nextptr = curr->next;
        curr->next = prevptr;
        prevptr = curr;
        if(nextptr != nullptr){
            curr = nextptr;
        }else{
            break;
        }
    }

    return prevptr;
}

int main(){
    Node* listhead = new Node(1);

    Node* head = listhead;
    Node* tail = listhead;

    insertattail(2, head, tail);
    insertattail(3, head, tail);
    insertattail(4, head, tail);
    insertattail(5, head, tail);

    head = reverseDLL(head);

    print(head);
}