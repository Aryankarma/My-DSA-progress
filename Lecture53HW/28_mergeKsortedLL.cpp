// SINGLY LINKED LIST
#include <bits/stdc++.h>
using namespace std;

/*  Problem Statement -

    Given 'k' sorted linked lists, each list is sorted in increasing order. You need to merge all these
    lists into one single sorted list. You need to return the head of the final linked list.

    For example:
    Input:
    3
    3
    4 6 8
    3
    2 5 7
    2
    1 9

    Output:
    1 2 4 5 6 7 8 9

    Explanation:
    First list is: 4 -> 6 -> 8 -> NULL
    Second list is: 2 -> 5 -> 7 -> NULL
    Third list is: 1 -> 9 -> NULL
    The final list would be: 1 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> NULL

    Link to CodingNinjas [https://www.naukri.com/code360/problems/merge-k-sorted-lists_992772?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker]
*/

// direct solution (approach better than 65%)

#include <queue>

void insertattail(Node *&tail, int data)
{
    Node *temp = new Node(data);

    tail->next = temp;
    tail = temp;
}

Node *mergeKLists(vector<Node *> &listArray)
{

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < listArray.size(); i++)
    {
        Node *temp = listArray[i];

        while (temp != NULL)
        {
            pq.push(temp->data);
            temp = temp->next;
        }
    }

    Node *finalLL = new Node(pq.top());
    pq.pop();
    Node *finalHead = finalLL;
    Node *finalTail = finalLL;

    while (!pq.empty())
    {
        insertattail(finalTail, pq.top());
        pq.pop();
    }

    return finalHead;
}


// approach 2 better than 80%

#include <bits/stdc++.h>
class compare{
public:
    bool operator()(Node *a, Node *b){
        return a->data > b->data;
    }
};

Node *mergeKLists(vector<Node *> &listArray){

    priority_queue<Node *, vector<Node *>, compare> pq;
    int k = listArray.size();
    if (k == 0){
        return NULL;
    }

    // step1: push the heads of all lists into pq
    for (int i = 0; i < k; i++){
        if (listArray[i] != NULL){
            pq.push(listArray[i]);
        }
    }

    Node *head = NULL;
    Node *tail = NULL;

    while (!pq.empty()){

        Node *top = pq.top();
        pq.pop();

        // Add the next node from the popped list to pq
        if (top->next != NULL){
            pq.push(top->next);
        }

        // Update the head and tail pointers of the merged list
        if (head == NULL){
            head = top;
            tail = top;
        }

        else{
            tail->next = top;
            tail = top;
        }
    }
    return head;
}


// approach 3 better than 95%

Node *mergeKLists(vector<Node *> &listArray){
    vector<int> v;

    for (Node *i : listArray){
        while (i){
            v.push_back(i->data);
            i = i->next;
        }
    }

    sort(v.begin(), v.end());
    Node *ans = new Node(0);
    Node *t = ans;

    for (int i : v){
        t->next = new Node(i);
        t = t->next;
    }

    return ans->next;
}