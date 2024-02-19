// SINGLY LINKED LIST
#include<bits/stdc++.h>
using namespace std;

/*  Add Two Numbers || Add two numbers represented by linked lists.
    
    Problem statement:

    You are given two non-negative numbers 'num1' and 'num2' represented in the form of linked lists.
    The digits in the linked lists are stored in reverse order, i.e. starting from least significant digit 
    (LSD) to the most significant digit (MSD), and each of their nodes contains a single digit.
    Calculate the sum of the two numbers and return the head of the sum list.

    Example :
    Input:
    'num1' : 1 -> 2 -> 3 -> NULL
    'num2' : 4 -> 5 -> 6 -> NULL

    Output: 5 -> 7 -> 9 -> NULL

    Explanation: 'num1' represents the number 321 and 'num2' represents 654. Their sum is 975.
*/  

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

void print(Node* &head){
    Node* current = head;

    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
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

    return past;
}

Node* add2LL(Node* head1, Node* head2){

    head1 = reverseLL(head1);
    head2 = reverseLL(head2);
    Node* curr1 = head1;
    Node* curr2 = head2;

    Node* resultLL = new Node(0);
    Node* resultHead = resultLL;
    Node* resultTail = resultLL;
    Node* resultCurr = resultHead;

    int sum = 0;
    int carry = 0;

    while(curr1 != NULL && curr2 != NULL){
        
        sum = curr1->data + curr2->data + carry;

        if(sum > 9){
            carry = sum/10;
            insertattail(resultTail, sum%10);
        }else{
            insertattail(resultTail, sum);
            carry = 0;
        }

        // if(curr2->next == NULL && carry != 0){
        //     sum = curr1->data + carry;

        //     if(sum > 9){
        //         carry = sum/10;
        //         insertattail(resultTail, sum%10);
        //     }else{
        //         insertattail(resultTail, sum);
        //         carry = 0;
        //     }
        // }

        curr1 = curr1->next;
        curr2 = curr2->next;
        if(resultCurr->next != NULL){
            resultCurr = resultCurr->next;
        }
    }

    if(curr1 != NULL){
        resultCurr->next = curr1;
    }
    if(curr2 != NULL){
        resultCurr->next = curr2;
    }

    // removing the 0 on the head of result LL
    Node* temp = resultHead;
    resultHead = resultHead->next;
    delete temp;

    return reverseLL(resultHead);
}

int main(){       
          
    Node* node1 = new Node(2);
    Node *head1 = node1;
    Node *tail1 = node1;
    // insertattail(tail1, 1);
    // insertattail(tail1, 3);
        
    Node* node2 = new Node(9);
    Node *head2 = node2;
    Node *tail2 = node2;
    insertattail(tail2, 9);
    // insertattail(tail2, 6);

    cout << "first LL : ";
    print(head1);
    cout << "second LL : ";
    print(head2);

    Node* result = NULL;
    // we'll go with the reverse LL approach
    result = add2LL(head1, head2);
    cout << "after adding : ";
    print(result);
}