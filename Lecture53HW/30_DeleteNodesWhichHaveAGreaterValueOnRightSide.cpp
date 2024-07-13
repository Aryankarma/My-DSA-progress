#include <bits/stdc++.h>
using namespace std;

/*  Problem Statement - Delete Nodes Which Have A Greater Value On Right Side

    You are given a linked list of integers where each node has two fields: data field which contains a value, 'next'
    field which points to its adjacent node to the right or NULL if it is the last node. Your task is to delete all such
     nodes X, whose adjacent nodes to the right have strictly greater value than the value of X.

    A singly linked list is a linear data structure in which we can traverse only in one direction i.e. from Head to
    Tail. It consists of several nodes where each node contains some data and a reference to the next node.

    A sample Linked List-

    Follow Up:
    Can you solve this in linear time and constant space complexity?

    Link to CodingNinjas [https://www.naukri.com/code360/problems/delete-nodes-which-have-a-greater-value-on-right-side_1115785?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM]

*/

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

Node* deleteNodes(Node* head){
    Node *curr = head;
    Node *prev = NULL;
    bool retry = false;

    while (curr != NULL && curr->next != NULL){
        if (curr->data < curr->next->data){
            Node *temp = curr;
            curr = curr->next;
            if (prev != NULL){
                prev->next = curr;
            }else{
                head = curr;
            }
            delete temp;
            retry = true;
        }else{
            prev = curr;
            curr = curr->next;
        }
        if (curr->next == NULL && retry == true){
            curr = head;
            prev = NULL;
            retry = false;
        }
    }

    return head;
}

int main(){
    Node *node = new Node(10);

    Node *head = node;
    Node *tail = node;

    insertattail(tail, 8);
    insertattail(tail, 7);
    insertattail(tail, 12);
    insertattail(tail, 5);

    Node* temp = deleteNodes(head);
    print(temp);
}