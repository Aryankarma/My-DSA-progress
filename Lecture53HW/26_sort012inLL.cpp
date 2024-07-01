#include <bits/stdc++.h>
using namespace std;

/*  Problem Statement -  Sort linked list of 0s 1s 2s
    Problem statement

    Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. You need to sort the linked list in non-decreasing order and the return the head of the sorted list.

    Example:
    Given linked list is 1 -> 0 -> 2 -> 1 -> 2.
    The sorted list for the given linked list will be 0 -> 1 -> 1 -> 2 -> 2.
*/

// Link to codespace [https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker]

class Node{
public:
    int data;
    Node *next;

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

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
};

Node* seperateLL(Node *head){
    int zeroCount = 0, oneCount = 0, twoCount = 0;

    Node *finalLL = new Node(0);

    Node *zeroLL = new Node(0);
    Node *oneLL = new Node(0);
    Node *twoLL = new Node(0);

    Node *zeroHead = zeroLL;
    Node *oneHead = oneLL;
    Node *twoHead = twoLL;

    Node *zeroTail = zeroLL;
    Node *oneTail = oneLL;
    Node *twoTail = twoLL;

    Node *current = head;

    while (current != NULL){
        if (current->data == 0){
            insertattail(zeroTail, 0);
            zeroCount++;
        }
        else if (current->data == 1){
            insertattail(oneTail, 1);
            oneCount++;
        }
        else{
            insertattail(twoTail, 2);
            twoCount++;
        }

        current = current->next;
    }

    finalLL = zeroHead->next;
    zeroTail->next = oneHead->next;
    oneTail->next = twoHead->next;

    return finalLL;
}

int main(){

    Node *node1 = new Node(2);
    Node *head = node1;
    Node *tail = node1;

    Node *result = NULL;

    insertattail(tail, 1);
    insertattail(tail, 0);
    insertattail(tail, 2);
    insertattail(tail, 1);
    insertattail(tail, 0);
    insertattail(tail, 0);
    insertattail(tail, 2);

    result = seperateLL(head);

    print(result);

    return 0;
}