#include <bits/stdc++.h>
#include <map>
using namespace std;

/*  Problem Statement - Segregate Even And Odd Nodes In a Linked List
    You are given the head node of a singly linked list 'head'. Your task is to modify
    the linked list in such a way that all the even valued nodes appear before the all odd valued node and
    order of nodes remain the same.

    Sample Input 1
    2 1 3 5 6 4 7 -1
    Sample Output 1
    2 6 4 1 3 5 7

    The modified linked list should have all even values in starting and odd values in the end.

    Link to CodingNinjs [https://www.naukri.com/code360/problems/segregate-even-and-odd-nodes-in-a-linked-list_1116100?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker]
*/

class Node
{
public:
    int data;   // integer data
    Node *next; // pointer variable "add" that stores the address of object

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertattail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head)
{
    Node *current = head;

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node *seperateEvenOdd(Node *head){
    Node *curr = head;
    Node *end = head;
    Node *prev = NULL;
    map<Node *, bool> mapping;

    while (end->next != NULL){
        end = end->next;
        mapping[end] = false;
    }

    while (curr != NULL){
        if (curr->data % 2 == 0 || mapping[curr] == true){ // even
            prev = curr;
            curr = curr->next;
        }

        else if (curr->data % 2 != 0){ // odd
            if (prev != NULL){
                prev->next = curr->next;
                Node *temp = curr;
                mapping[curr] = true;
                curr = curr->next;
                temp->next = end->next;
                end->next = temp;
                end = temp;
            }else{
                cout << "running 2" << endl;
                Node *tempprev = curr;
                head = head->next;
                mapping[curr] = true;
                curr = curr->next;
                tempprev->next = end->next;
                end->next = tempprev;
                end = tempprev;
            }
        }
    }

    return head;
}

int main(){
    Node *node = new Node(1);

    Node *head = node;
    Node *tail = node;

    insertattail(tail, 3);
    insertattail(tail, 2);
    insertattail(tail, 5);
    insertattail(tail, 4);
    
    Node *temp = seperateEvenOdd(head);
    print(temp);
}