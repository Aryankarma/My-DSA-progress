#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*  Problem statement
    You are given a doubly-linked list with 'N' nodes, rotate the linked list counter-clockwise by 'K' nodes. 'K' is a 
    positive integer and is smaller than the number of nodes in the linked list, that is 'N'.

    A doubly linked List (DLL) contains an extra pointer, called the previous pointer, together with the next pointer 
    and data which are there in the singly linked list such that both forward and backward navigation is possible.

*/

// Link to codingNinjas [https://www.naukri.com/code360/problems/rotate-dll_1115782?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker]

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

void insertathead(int data, Node *&head, Node *tail){
    Node *temp = new Node(data);

    if (head == nullptr){
        head = temp;
        tail = temp;
    }else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertattail(int data, Node *head, Node *&tail){
    Node *temp = new Node(data);

    if (tail == nullptr){
        head = temp;
        tail = temp;
    }else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

Node *rotateDLL(Node *head, int k){

    Node *firstEnd = head;
    Node *secondStart = head;

    while (firstEnd->next != NULL){
        firstEnd = firstEnd->next;
    }

    int count = k;
    Node *secondEnd = head;
    while (count > 1){
        secondEnd = secondEnd->next;
        count--;
    }   

    // cout << secondEnd->data << endl;
    Node* firstStart = secondEnd->next;
    // cout << firstStart->data << endl;
    // cout << firstEnd->data << endl;
    // cout << secondStart->data << endl;
    // cout << secondEnd->data << endl;


    secondEnd->next = NULL;
    firstStart->prev = NULL;

    firstEnd->next = secondStart;

    return firstStart;
    // return NULL;
};

int main(){
    Node *listhead = new Node(6);

    Node *head = listhead;
    Node *tail = listhead;

    insertattail(2, head, tail);
    insertattail(4, head, tail);
    insertattail(2, head, tail);
    insertattail(1, head, tail);
    insertattail(4, head, tail);

    Node* temp = NULL;

    temp = rotateDLL(head, 2);

    print(temp);
}