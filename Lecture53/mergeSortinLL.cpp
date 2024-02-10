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
    // defining pointers
    Node* midNode = head;
    Node* endNode = head->next;

    while(endNode->next != NULL){
        endNode = endNode->next;

        if(endNode->next != NULL){
            midNode = midNode->next;
            endNode = endNode->next;
        }
    }

    return midNode;
}

Node* merge(Node* &leftpart, Node* &rightpart){

    Node* leftcurr = leftpart;
    Node* rightcurr = rightpart;

    Node* temp = new Node(0);
    Node* temptail = temp;

    while(leftcurr != NULL && rightcurr != NULL){
        if(leftcurr->data <= rightcurr->data){
            insertattail(temptail, leftcurr->data);
            leftcurr = leftcurr->next;
        }else{
            insertattail(temptail, rightcurr->data);
            rightcurr = rightcurr->next;
        }
        // print(temp);
    }


    // Merge remaining elements if any
    while(leftcurr != NULL){
        insertattail(temptail, leftcurr->data);
        leftcurr = leftcurr->next;
    }

    while(rightcurr != NULL){
        insertattail(temptail, rightcurr->data);
        rightcurr = rightcurr->next;
    }


    Node* result = temp->next;
    delete temp;  // Freeing the memory allocated for the dummy node
    return result;
}

Node* mergesort(Node* &head){

    if(head == NULL || head->next == NULL){
        return head;
    }
    
    Node* leftpart = head;
    Node* rightpart = head;
    Node* midnode = head;

    midnode = splitlist(head);
    rightpart = midnode->next;
    midnode->next = NULL;

    // print check
    // print(leftpart);
    // print(rightpart);

    // recursive calls for half of the linked lists of both sides
    leftpart = mergesort(leftpart);
    rightpart = mergesort(rightpart);

    // merge 2 sorted linked lists
    head = merge(leftpart, rightpart);
    return head;
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

    // sending list head to the merge sort function that splits the lists till low level and then merges them! 
    mergesort(head);
    print(head);
}