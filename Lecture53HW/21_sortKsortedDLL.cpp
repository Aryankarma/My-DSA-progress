#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*  Problem Statement -  You’re given a doubly-linked list with N nodes, where each node deviates at max K position from its position in the sorted list. Your task is to sort this given doubly linked list.

    For example :
    Let us consider K is 3, an element at position 4 in the sorted doubly linked list, can be at positions 1, 2, 3, 4, 5, 6, 7 in the given linked list because the absolute difference of all these indices with 4 is at most 3.
    
    Note :
    All elements are distinct.

*/

// Link to codingNinjas [https://www.naukri.com/code360/problems/sort-a-k-sorted-doubly-linked-list_1118118?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM]

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

    Node *temp =     head;
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

    // if the list is empty
    if (head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        // the list is not empty

        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertattail(int data, Node *head, Node *&tail)
{
    Node *temp = new Node(data);

    // if the list is empty
    if (tail == nullptr)
    {

        head = temp;
        tail = temp;
    }
    else
    {
        // the list is not empty

        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

#include <bits/stdc++.h>
Node *sortDLL(Node *head, int k)
{
    vector<int> storingNumbers;

    Node *temp = head;

    while (temp != NULL)
    {
        storingNumbers.push_back(temp->data);
        temp = temp->next;
    }

    sort(storingNumbers.begin(), storingNumbers.end());
    Node *first = NULL;
    Node *second = NULL;

    for (int i = 0; i < storingNumbers.size(); i++)
    {

        Node *tempNode = new Node(storingNumbers[i]);

        if (first == NULL)
        {
            first = tempNode;
            second = first;
            first->next = NULL;
            first->prev = NULL;
        }
        else
        {
            first->next = tempNode;
            tempNode->prev = first;
            first = tempNode;
        }
    }

    return second;
}

int main()
{
    Node *listhead = new Node(6);

    Node *head = listhead;
    Node *tail = listhead;

    insertattail(5, head, tail);
    insertattail(3, head, tail);
    insertattail(2, head, tail);
    insertattail(8, head, tail);
    insertattail(10, head, tail);
    insertattail(9, head, tail);

    head = sortDLL(head, 4);

    print(head);
}