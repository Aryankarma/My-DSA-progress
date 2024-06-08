#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;

/*  Problem statement

    You are given a Doubly Linked List of integers and a positive integer 'K' representing the group size. Modify the linked list by reversing every group of 'K' nodes in the linked list.

    A doubly linked list is a type of linked list that is bidirectional, that is, it can be traversed in both directions, forward and backward.

    Note:
    If the number of nodes in the list or in the last group is less than K, just reverse the remaining nodes.

    Example:

    Linked list: 8 9 10 11 12
    K: 3
    Output: 10 9 8 12 11

    We reverse the first K (3) nodes. Now, since the number of nodes remaining in the list (2) is less than K, we just reverse the remaining nodes (11 and 12).

    just apply simple reverse algo in groups, that's it -> add a condition if the pointer reaches null it assumes as the end of the group

*/

// Link to codingNinjas [https://www.naukri.com/code360/problems/reverse-dll-nodes-in-groups_920399?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker]

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int value)
    {
        this->data = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
    ~Node()
    {
        int value = this->data;
        if (next != nullptr)
        {
            delete next;
            next = NULL;
        }
        cout << "Node with value : " << value << " got deleted. " << endl;
    }
};

int getLength(Node *&head)
{

    Node *temp = head;
    int count = 0;

    while (temp != nullptr)
    {
        count++;
    }

    return count;
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void printtail(Node *&tail)
{
    Node *temp = tail;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}

void insertathead(int data, Node *&head, Node *tail)
{
    Node *temp = new Node(data);

    if (head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertattail(int data, Node *head, Node *&tail)
{
    Node *temp = new Node(data);

    if (tail == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void reverseDLL(Node *&head)
{
    if (!head)
        return;

    Node *current = head;
    Node *temp = nullptr;

    while (current != nullptr)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr)
    {
        head = temp->prev;
    }
}

Node *findTail(Node *head){

    if (!head)
        return nullptr;

    Node *current = head;
    while (current->next != nullptr){
        current = current->next;
    }

    return current;
}

Node* findHead(Node* temp){
    if (!temp || temp->prev == NULL)
        return temp;

    Node *current = temp;
    while (current->prev != nullptr){
        current = current->prev;
    }

    return current;
}

Node *reverseDLLinGroups(Node *head, int k){

    Node *firstNode = head;

    reverseDLL(head);

    int count = 1;
    Node *temp = findTail(head);
    map<int, Node*> mapping;
    Node *finalHead = NULL;

    while(temp != NULL){
        cout << "inside this loop 1 " << endl;
        if (temp == firstNode){
            mapping[mapping.size() + 1] = temp;
            finalHead = temp;
            for (int i = 1; i < k; i++){
                if (!finalHead->prev){
                    return finalHead;
                }
                    finalHead = finalHead->prev;
            }
            cout << "infinite " ;
            temp = temp->prev;
            count++;
        }

        if(count == k){
            if(!temp->prev)
                break;
            temp = temp->prev;
            temp->next->prev = NULL;
            temp->next = NULL;
            count = 1;
            mapping[mapping.size() + 1] = temp;
            // Node *current = NULL;4
            // for (int i = 1; i <= mapping.size(); i++){
            //     printtail(mapping[i]); // shows correct groups
            // }
            // cout << endl;
        }else{
            temp = temp->prev;
            count++;
        }
    }

    for (int i = 1; (i <= mapping.size()) && (mapping[i + 1]); i++){
        Node *nextNode = findHead(mapping[i+1]);
        mapping[i]->next = nextNode;
        nextNode->prev = mapping[i];
    }

    print(finalHead);

    return NULL;
};

int main(){
    Node *listhead = new Node(1);

    Node *head = listhead;
    Node *tail = listhead;

    insertattail(2, head, tail);
    insertattail(3, head, tail);
    insertattail(4, head, tail);
    insertattail(5, head, tail);
    insertattail(6, head, tail);

    Node *temp = NULL;

    // -19 -13 -5 -5 -12 9 7 -4 -11 3 -1

    reverseDLLinGroups(head, 3333);
}