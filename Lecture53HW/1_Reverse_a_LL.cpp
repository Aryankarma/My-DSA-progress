#include <bits/stdc++.h>
using namespace std;

/*  Problem statement

    [In Coding Ninjas]
    Ninjas is practicing problems on the linked list. He came across a problem in which he has given a 
    linked list of ‘N’ nodes and two integers, ‘LOW’ and ‘HIGH’. He has to return the linked list ‘HEAD’ 
    after reversing the nodes between ‘LOW’ and ‘HIGH’, including the nodes at positions ‘LOW’ and ‘HIGH’.

    [LOW and HIGH's are basically the indexes which we have to reverse + nodes in b/w those indexes too]

    Example:

    1 3 2 4 6 5 -1
    2 3

    1 3 7 4 -1
    2 4

    For first test case :
    Reversing nodes 2 and 3 : 2 3
    Resultant linked list : 1 2 3 4 6 5   

    For second test case :
    Reversing nodes 2 and 4 : 4 7 3
    Resultant linked list : 1 4 7 3

    Sample Output 1 :
    1 2 3 4 6 5
    1 4 7 3
*/

// Link to coding ninjas [https://www.codingninjas.com/studio/problems/reverse-a-ll_2271431?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker] 

class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        this->data = value;
        this->next = NULL;
    }

    ~Node(){
        Node* curr = this;
        while(curr != NULL){
            Node* nextptr = curr->next;
            delete curr;
            curr = nextptr;
        }
    }

};

void insertattail(Node* &tail, int data){
    Node* temp = new Node(data);

    tail->next = temp;
    tail = tail->next;    
}

void print(Node* head){
    Node* curr = head;

    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    } 
    cout << endl;
}

Node* reverseList(Node* &head, int low, int high){

    if(head == NULL || low >= high) // Edge cases: empty list or invalid range
        return head;


    // creating pointers 
    Node* leftEnd = NULL;
    Node* lowNode = NULL;
    Node* rightEnd = NULL;
    Node* highNode = NULL;
    
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    // updating pointers
    while(curr != NULL){
        low--;
        high--;

        if(low == 0){
            lowNode = curr;
            leftEnd = prev;
        }

        if(high == 0){
            highNode = curr;
            rightEnd = curr->next;
        }

        // increasing all pointers
        prev = curr;
        curr = curr->next;
    }
    
    // if low = 1;
    if(lowNode == head){
        prev = NULL;
        curr = lowNode;
        while(curr != rightEnd){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = highNode;
        lowNode->next = rightEnd;
        return head;
    }

    prev = NULL;
    curr = lowNode;
    while(curr != rightEnd){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    cout << "printing head ";
    print(head);

    leftEnd->next = highNode;
    lowNode->next = rightEnd;

    return head;
}

int main(){
    Node* node1 = new Node(20);

    Node* tail = node1;
    Node* head = node1;

    insertattail(tail, 10);
    insertattail(tail, 30);
    insertattail(tail, 40);
    insertattail(tail, 50);
    insertattail(tail, 60);
    insertattail(tail, 70);
    insertattail(tail, 80);

    print(head);

    int low = 1; 
    int high = 2;
    Node* temp = NULL;

    temp = reverseList(head, low, high);

    cout << "printing temp " << endl;
    print(temp);

}