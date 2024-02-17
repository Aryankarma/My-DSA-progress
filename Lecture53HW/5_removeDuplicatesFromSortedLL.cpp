#include<bits/stdc++.h>
using namespace std;

/*  problem statement - Remove duplicates from a sorted Doubly Linked List

    A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have 
    reference to both the previous and the next nodes in the sequence of nodes.

    You are given a sorted doubly linked list of size 'n'.

    Remove all the duplicate nodes present in the linked list.

    Example :
    Input: Linked List: 1 <-> 2 <-> 2 <-> 2 <-> 3

    Output: Modified Linked List: 1 <-> 2 <-> 3

    Explanation: We will delete the duplicate values ‘2’ present in the linked list.
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


Node* removeDuplicates(Node *head) {
    
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
          
    Node* node1 = new Node(10);
          
    Node *head = node1;
    Node *tail = node1;


    insertattail(tail, 20);
    insertattail(tail, 20);
    insertattail(tail, 30);
    insertattail(tail, 40);
    insertattail(tail, 40);

    print(head);

    removeDuplicates(head);

    print(head);

}