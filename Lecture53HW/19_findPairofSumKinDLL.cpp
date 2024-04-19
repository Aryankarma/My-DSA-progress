#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*  Problem Statement -  Find pairs with given sum in doubly linked list
    A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have 
    reference to both the previous and the next nodes in the sequence of nodes.

    You are given a sorted doubly linked list of size 'n', consisting of distinct positive integers, and a number 'k'.

    Find out all the pairs in the doubly linked list with sum equal to 'k'

    Example :
    Input: Linked List: 1 <-> 2 <-> 3 <-> 4 <-> 9 and 'k' = 5
    Output: (1, 4) and (2, 3)

*/

// Link to codingNinjas [https://www.naukri.com/code360/problems/find-pair-with-a-given-sum-in-a-doubly-linked-list_1164172?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker]


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

Node* findPairInDLL(Node* head){
    vector<pair<int, int>> pairs;

    pairs.push_back({1,2});

    cout << pairs[0] << endl;

    return NULL;
}

int main(){
    Node* listhead = new Node(1);

    Node* head = listhead;
    Node* tail = listhead;

    insertattail(2, head, tail);
    insertattail(3, head, tail);
    insertattail(4, head, tail);
    insertattail(5, head, tail);

    head = findPairInDLL(head);

    print(head);
}