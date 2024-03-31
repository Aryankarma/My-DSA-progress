#include<bits/stdc++.h>
using namespace std;

/*  MergeSort Linked List

    Problem statement:
    For a given Singly Linked List of integers, sort the list using the 'Merge Sort' algorithm.

*/

// Link to CodingNinjas [https://www.codingninjas.com/studio/problems/mergesort-linked-list_630514?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_CodestudioLovebabbar5thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_CodestudioLovebabbar5thfeb]

class Node{
    public:
    int data;   // integer data
    Node *next;  // pointer variable "add" that stores the address of object

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertattail(Node* &tail, int data){
    Node* temp = new Node(data);    
    tail->next = temp;
    tail = temp;
}

void print(Node* &head){
    Node* current = head;

    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// working
Node* splitlist(Node* &head){
        
    Node* ptr1 = head;
    Node* ptr2 = head->next;

    while(ptr2->next != NULL){
        ptr2 = ptr2->next;

        if(ptr2->next != NULL){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    return ptr1;
}

Node* merge(Node* &leftpart, Node* &rightpart){
    Node* leftptr = leftpart;
    Node* rightptr = rightpart;

    Node* resultLL = new Node(0);
    Node* temptail = resultLL;

    while(leftptr != NULL && rightptr != NULL){
        if(leftptr->data <= rightptr->data){
            insertattail(temptail, leftptr->data);
            leftptr = leftptr->next;
        }else{
            insertattail(temptail, rightptr->data);
            rightptr = rightptr->next;
        }
    }

    while(leftptr != NULL){
        insertattail(temptail, leftptr->data);
        leftptr = leftptr->next;
    }

    while(rightptr != NULL){
        insertattail(temptail, rightptr->data);
        rightptr = rightptr->next;
    }

    return resultLL->next;    
}

Node* mergesort(Node* &head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* leftPart = head;
    Node* mid = splitlist(head);
    Node* rightPart = mid->next;
    mid->next = NULL;
    
    leftPart = mergesort(leftPart);
    rightPart = mergesort(rightPart);
    
    return merge(leftPart, rightPart);
}

int main(){
    Node* node1 = new Node(60);
          
    Node *head = node1;
    Node *tail = node1;

    // adding nodes to linked list
    insertattail(tail, 50);
    insertattail(tail, 20);
    insertattail(tail, 40);
    insertattail(tail, 30);
    insertattail(tail, 70);
    insertattail(tail, 80);
    insertattail(tail, 10);

    Node* temp = NULL;
    temp = mergesort(head);
    print(temp);
}