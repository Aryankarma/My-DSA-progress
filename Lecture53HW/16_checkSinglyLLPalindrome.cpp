// SINGLY LINKED LIST
#include <bits/stdc++.h>
using namespace std;

/* Problem Statement - 

    You are given a singly Linked List of integers. Your task is to return true if the given singly linked 
    list is a palindrome otherwise returns false.

    For example:
    The given linked list is 1 -> 2 -> 3 -> 2-> 1-> NULL.

    It is a palindrome linked list because the given linked list has the same order of elements when 
    traversed forwards and backward​.
    Follow Up:
    Can you solve the problem in O(N) time complexity and O(1) space complexity iteratively?

*/

// Link to codingNinjas [https://www.naukri.com/code360/problems/palindrom-linked-list_799352?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker]


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

void prinsdft(Node* &head){
    Node* current = head;

    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

bool checkPalindrome(Node* head){

    Node* fast = head;
    Node* slow = head;
    bool oddOrNot = false;
    stack<int> numStack;

    while( fast != NULL){

        if( fast->next != NULL ){
            numStack.push( slow->data );
            slow = slow->next;
            fast = fast->next;
        }else{
            oddOrNot = true;
            break;
        }
        fast = fast->next;
    }

    if( oddOrNot ){
        slow = slow->next;
    }
    
    while( slow != NULL ){
        if( slow->data == numStack.top() ){
            slow = slow->next;
            numStack.pop();
        }else{
            return false;
        }
    }

    return true;
};

int main(){
          
    Node* node1 = new Node(1); 
          
    Node *head = node1;
    Node *tail = node1;

    insertattail(tail, 2);
    insertattail(tail, 3);
    insertattail(tail, 6);
    insertattail(tail, 2);
    insertattail(tail, 1);

    bool ans = checkPalindrome(head);

    cout << ans << endl; // if 1 LL is palindrome & vice versa

}