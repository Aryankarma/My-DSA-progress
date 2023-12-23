#include<bits/stdc++.h>
using namespace std;


/*  Problem Statement - A doubly-linked list is a data structure that consists of sequentially linked nodes, 
    and the nodes have reference to both the previous and the next nodes in the sequence of nodes. You are given a sorted doubly linked list of size 'n',Remove all the duplicate nodes present in the linked list.

    Example - Input: Linked List: 1 <-> 2 <-> 2 <-> 2 <-> 3
    Output: Modified Linked List: 1 <-> 2 <-> 3
    Explanation: We will delete the duplicate values ‘2’ present in the linked list.

*/


class Node{
    public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};


void insertattail(int data, Node* &tail){
        Node *temp = new Node(data);
    
        tail->next = temp;  // connect tail's next to temp
        temp->prev = tail;  // connect temp's prev to tail
        tail = temp;        // update tail 
};


void print(Node* &head){
    Node* temp  = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
};

Node *removeDuplicated(Node *head) {
    Node* current = head;
    
    while(current != NULL && current->next != NULL){
        if(current->data == current->next->data){
            
            Node* deletenode = current->next;
            current->next = current->next->next;
            delete(deletenode);

        }else{
            current = current->next;
        }
    }
    return head;
}

int main(){

    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    
    insertattail(2, tail);   
    insertattail(2, tail);   
    insertattail(2, tail);  
    insertattail(3, tail);  

    // before removing duplicates
    print(head);

    removeDuplicated(head);    
    // after removing duplicates
    print(head);
}   