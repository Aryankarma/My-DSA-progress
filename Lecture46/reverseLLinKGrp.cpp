#include<bits/stdc++.h>
using namespace std;

/*  Problem - Reverse Linked List

    Given a singly linked list of integers. Your task is to return the head of the reversed linked list.

    The given linked list is 1 -> 2 -> 3 -> 4-> NULL. Then the reverse linked list is 4 -> 3 -> 2 -> 1 -> 
    NULL and the head of the reversed linked list will be 4.

    Link to CodingNinjas [https://www.codingninjas.com/studio/problems/reverse-the-singly-linked-list_799897?source=
    youtube&campaign=Lovebabbarcodestudio_24thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=
    Lovebabbarcodestudio_24thJan]
*/

// class Node{
//     public:
//     int data;
//     Node *next;

//     // constructor
//     Node(int data){
//         this->data = data;
//         this->next = NULL;
//     };

//     // deconstructor
//     ~Node(){
        
//     }
// };

// void inserthead(int data, Node* &head){
//     Node* temp = new Node(data);

//     temp->next = head;
//     head = temp;

// };

// void print(Node* &head){
//     Node *temp = head;
    
//     while(temp != NULL){
//         cout << temp->data << " ";
//         temp = temp->next;
//     };
//     cout << endl;
// };

// void reverse(Node* &start, Node* &final, Node* &finalprev, Node* &prev){
//     Node* current = start;

//     while(current != finalprev){
//         Node* foreword = current->next;

//         current->next = prev;
//         prev = current;
//         current = foreword;
//     }
//     start = final;
//     finalprev = finalprev->next;
// };

// void recursive(Node* &final, Node* &start, Node* &finalprev, Node* &prev, int k){ 
//     if(final == NULL){
//         return ;
//     }

//     for(int i=0; i<k; i++){
//         final = final->next;
//         if(i>0){
//             finalprev = finalprev->next;
//         }
//     }
    
//     reverse(start, final, finalprev, prev);
//     recursive(final, start, finalprev, prev, k);
// };

// int main(){

//     Node *node1 = new Node(1);
//     Node *head = node1;
//     Node *tail = node1;

//     inserthead(2, head);
//     inserthead(3, head);
//     inserthead(4, head);
//     inserthead(5, head);
//     inserthead(6, head);

//     Node* final = head;
//     Node* finalprev = head;
//     Node* start = head;
//     Node* prev = NULL;

//     int k = 2;     

//     recursive(final, start, finalprev, prev, k);
//     print(head);
// };





// next/correct approach

class Node{
    public:
    int data;
    Node *next;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    };

    // deconstructor
    ~Node(){
        
    }
};

void insertattail(int data, Node* &tail){
    Node* temp = new Node(data);

    tail->next = temp;
    tail = temp;

};

void print(Node* &head){
    Node *temp = head;
    
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    };
    cout << endl;
};

Node* recursive(Node* &head, int k){  
    // base case
    // if(head == NULL){
    //     return NULL;
    // }

    Node* current = head;
    Node* prev = NULL;
    Node* foreword = NULL;
    int count = 0;

    while(current != NULL && count < k){
        foreword = current->next;
        current->next = prev;
        prev = current;
        current = foreword;

        count++;
    }

    if(foreword != NULL){
        cout << "head : " << head->data << endl;
        head->next = recursive(foreword, k);
    }

    return prev;
};

int main(){

    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    insertattail(2, tail);
    insertattail(3, tail);
    insertattail(4, tail);
    insertattail(5, tail);
    insertattail(6, tail);
    insertattail(7, tail);
    insertattail(8, tail);
    
    print(head);

    int k = 2;     

    recursive(head, k);
    print(head);
};