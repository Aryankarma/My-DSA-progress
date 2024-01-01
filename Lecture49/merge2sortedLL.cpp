#include<bits/stdc++.h>
using namespace std;

// Merge Two Sorted Linked Lists
/*  
    Problem Statement - You are given two sorted linked lists. You have to merge them to produce a 
    combined sorted linked list. You need to return the head of the final linked list.
    
    Note:

    The given linked lists may or may not be null.
    For example:
    If the first list is: 1 -> 4 -> 5 -> NULL and the second list is: 2 -> 3 -> 5 -> NULL
    The final list would be: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> NULL
    Link to codespace [https://www.codingninjas.com/studio/problems/merge-two-sorted-linked-lists_800332?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_Lovebabbar31stJan2021&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar31stJan2021]

*/


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
    Node *temp = new Node(data);
    tail -> next = temp;
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

Node* mergeList(Node* head1, Node* head2){
    Node* i = head1;
    Node* j = head2;

    while(true){
        if(i->data <= j->data && j->data <= i->next->data){
            Node* inext = i->next;
            Node* jnext = j->next;

            i->next = j;
            j->next = inext;
            j = jnext;

            cout << "first condition " << endl;
            cout << i->data << endl;
            cout << j->data << endl;
        }else if(i->next == NULL && i->data <= j->data){
            i->next = j;
            j->next = NULL;

            cout << "second condition " << endl;
        }else if(i == NULL || j == NULL){
            cout << "out of list pointer " << endl;
            break;
        }else if(i->next == NULL || j->next == NULL){
            cout << "last statement " << endl;
            break;
        }else{
            i = i->next;
            cout << "updating i " << endl;
        }
        cout << "while running " << endl; 
    }

    cout << "out of while " << endl;

    print(head1);
    return head1;
};

int main(){
    // creating in heap memory    
    Node* node1 = new Node(12);
          
    Node *head1 = node1;
    Node *tail1 = node1;
    insertattail(tail1, 20);
    insertattail(tail1, 30);

    Node* node2 = new Node(12);

    Node *head2 = node2;
    Node *tail2 = node2;
    insertattail(tail2, 14);
    insertattail(tail2, 17);

    mergeList(head1, head2);

}