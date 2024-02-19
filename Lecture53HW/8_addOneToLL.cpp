// SINGLY LINKED LIST
#include<bits/stdc++.h>
using namespace std;

/*  Problem statement -  Add One to Linked List

    Ninja has been given a number that is represented in the form of a linked list such that each digit 
    corresponds to a node. He has been asked to add 1 to it and return the updated list.

    For Example:

    1234 is represented as (1 -> 2 -> 3 -> 4) and adding 1 to it should change it to (1 -> 2 -> 3 -> 5).
    Note:

    The input Linked list does not have any trailing zeros.

*/

// CodingNinjas [https://www.codingninjas.com/studio/problems/add-one-to-linked-list_920456?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM]
// GFG [https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1]

class Node{
    public:
    int data;   // integer data
    Node *next;  // pointer variable "add" that stores the address of object

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


void insertattail(Node* &tail, int data){
    Node *temp = new Node(data);    
    tail -> next = temp;
    tail = temp;
}

void insertathead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void print(Node* &head){
    Node* current = head;

    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// time - O(n), space - O(n)
Node* addOneinLL(Node* head){
    
    Node* curr = head;
    unsigned long long int number = 0;

    while(curr != NULL){
        number = number*10 + curr->data;
        curr = curr->next;
    }   

    number = number + 1;

    Node* templist = new Node(0);
    Node* temphead = templist;

    while(number > 0){
        unsigned long long int number2 = number%10;
        // cout << number2 << endl;
        insertathead(temphead, number2);
        number = number/10;
    }

    Node* tempcurr = temphead;

    while(true){
        if(tempcurr->next->next == NULL){
            tempcurr->next = NULL;
            break;
        }
        tempcurr = tempcurr->next;
    }
    return temphead;
}

Node* reverseLL(Node* &head){
    Node* curr = head;
    Node* past = NULL;
    Node* future = NULL;

    while(curr != NULL){
        future = curr->next;
        curr->next = past;
        past = curr;
        curr = future;
    }

    return head = past;
}


// time - O(n), space - O(1)
Node* addOneinLL2(Node* head){

    reverseLL(head);

    Node* curr = head;
    int carry = 1;

    while(curr != NULL){

        if(curr->data + carry > 9){
            curr->data = 0;
        }else if(carry == 1){
            curr->data = curr->data + carry;
            carry = 0;
        }else{
            return reverseLL(head);
        }

        if((curr->next == NULL) && (carry == 1)){
            Node* temp = new Node(carry);
            curr->next = temp;
            return reverseLL(head);
        }

        curr = curr->next;
        
    }

    return reverseLL(head);
}

int main(){       
          
    Node* node1 = new Node(9);
          
    Node *head = node1;
    Node *tail = node1;

    insertattail(tail, 9);

    print(head);

    Node* temphead = NULL;
    Node* temphead2 = NULL;

    // approach 1 (doesn't work with all test cases because we can't store integers greater than 
    // 2^64(18446744073709551616)[unsigned long long int], and the test cases contains numbers that are 
    // greater number than this, but the approach works han, with numbers below 2^64 :)
    // gfg test case 33, 42880368048999999999
    
    temphead = addOneinLL(head);
    cout << "first approach : ";
    print(temphead);

    /*  Second approach following the below steps :

        1.  Reverse given linked list. For example, 1-> 9-> 9 -> 9 is converted to 9-> 9 -> 9 ->1.
        2.  Start traversing linked list from leftmost node and add 1 to it. If there is a carry, move 
            to the next node. Keep moving to the next node while there is a carry.
        3.  Reverse modified linked list and return head.
    */

    cout << "second approach : ";
    temphead2 = addOneinLL2(head);
    print(temphead2);

}