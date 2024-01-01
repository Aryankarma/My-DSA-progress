#include<bits/stdc++.h>
using namespace std;

// Circular Linked
/*  Problem Statement - You are given the head of a linked list containing integers, You need to find out whether 
    the given linked list is circular or not.

    Note :

    1. A linked list is said to be circular if it has no node having its next pointer equal to NULL and all the 
    nodes form a circle i.e. the next pointer of last node points to the first node.
    2. An empty linked will also be considered as circular.
    3. All the integers in the linked list are unique.
    4. In the input, the next pointer of a node with i’th integer is linked to the node with data (i+1)’th 
    integer (If (i+1)’th node exists). If there is no such (i+1)’th integer then the next pointer of such node 
    is set to NULL.

    Link to codespace [https://www.codingninjas.com/studio/problems/circularly-linked_1070232?source=youtube&campaign=Lovebabbar_codestudio_26thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar_codestudio_26thjan]
*/


class Node{

    public:
    int data;
    Node* next;
    Node* prev;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

bool checkCircular(Node* &head){
    Node* current = head->next;

    // if 0 elements are there
    if(head == NULL){
        return true;
    }

    // if there is 1 node
    if(head->next == head){        
        return true; // circular with 1 node only
    }else if(head->next == NULL){
        return false; // not a circular LL
    }

    while(current != NULL && current != head){
        if(current->next == NULL){
            // it is not a circular LL
            return false;
        }else if(current->next == head){
            // it is a circular LL
            return true;
        }else{
            current = current->next;
        }
    }

    return true;
};

void insertattail(Node* &tail, int data){
    Node* temp = new Node(data);

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
};

int main(){

    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insertattail(tail, 2);
    // insertattail(tail, 3);
    // insertattail(tail, 4);
    // insertattail(tail, 5);
    // insertattail(tail, 6);

    cout << checkCircular(head) << endl;

}