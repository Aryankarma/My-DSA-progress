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



void inserthead(int data, Node* &head){
    Node* temp = new Node(data);

    temp->next = head;
    head = temp;

};

void print(Node* &head){
    Node *temp = head;
    
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    };
    cout << endl;
};

// reversing with loop
void reverseLinkedList(Node* &head){

    Node* current = head;           
    Node* prev = NULL;          

    while(current != NULL){
        Node* foreward = current->next;
        current->next = prev;
        prev = current;
        current = foreward;
    };
    // return prev // for codestudio
    head = prev;
};

// reversing with recursion
void reverseLinkedListbyRecursion(Node* &head, Node* &current, Node* &prev){

    if(current == NULL){
        return;
    }

    Node* foreward = current->next;
    current->next = prev;
    prev = current;
    current = foreward;
    head = prev;
    reverseLinkedListbyRecursion(head, current, prev);
}

Node* reverseLinkedListbyRecursion2(Node* head){

    if(head == NULL || head->next == NULL){
        return head;
    };

    Node* cropList = reverseLinkedListbyRecursion2(head->next);

    head->next->next = head;
    head->next = NULL;

    return cropList;

}

int main(){

    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    // print(head);
    inserthead(10, head);
    // print(head);
    inserthead(100, head);
    // print(head);
    inserthead(1000, head);
    print(head);                    

    // approach 1 TC - O(n) SC - O(1)
    reverseLinkedList(head);
    print(head);

    // approach 2 (recursive solution)
    // define two pointers outside
    Node* current = head;
    Node* prev = NULL;
    reverseLinkedListbyRecursion(head, current, prev);
    print(head);
    
    // approach 3 (recursive solution 2)
    reverseLinkedListbyRecursion2(head);
    print(head);

};