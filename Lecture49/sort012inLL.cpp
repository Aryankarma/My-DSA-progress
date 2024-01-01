#include<bits/stdc++.h>
using namespace std;

// Problem - Sort linked list of 0s 1s 2s

/* 
    Problem Statement - Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. 
    You need to sort the linked list in non-decreasing order and the return the head of the sorted list.
    
    Example:
    Given linked list is 1 -> 0 -> 2 -> 1 -> 2. 
    The sorted list for the given linked list will be 0 -> 1 -> 1 -> 2 -> 2.
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

void sort012(Node* head){
 int count0=0, count1=0, count2=0;
    Node* curr = head;
    // counting 0's 1's & 2's
    while(curr){
        if(curr->data == 0){
            count0++;
        }else if(curr->data == 1){
            count1++;
        }else{
            count2++;
        }
        curr = curr->next;
    }

    // updating linked list
    curr = head;
    while(curr){
        if(count0 > 0){
            curr->data = 0;
            count0--;
        }else if(count1 > 0){
            curr->data = 1;
            count1--;
        }else if(count2 > 0){
            curr->data = 2;
            count2--;
        }
        curr = curr->next;
    }
}

void insertattail(int data, Node* &tail){
    Node* temp = new Node(data);

    tail->next = temp;
    tail = tail->next;
}

Node* mergeThis(Node* &head0, Node* &tail0, Node* &head1, Node* &tail1, Node* &head2, Node* &tail2){
    // removing -1 from first LL
    head0 = head0->next;
    tail0->next = head1->next;
    tail1->next = head2->next;

    return head0;
}

void sort012bymerging(Node* head){
    // creating LL to store 0 1 2
    Node* node0 = new Node(-1);
    Node* node1 = new Node(-1);
    Node* node2 = new Node(-1);

    // tail for linked lists
    Node* tail0 = node0;
    Node* tail1 = node1;
    Node* tail2 = node2;

    // head for linked lists
    Node* head0 = node0;
    Node* head1 = node1;
    Node* head2 = node2;

    // head for main linked list
    Node* current = head;

    while(current != NULL){
        cout << "while running " << endl;
        if(current->data == 0){
            insertattail(0, tail0);
        }else if(current->data == 1){
            insertattail(1, tail1);
        }else if(current->data == 2){
            insertattail(2, tail2);
        }
        current = current->next;
    }
    
    Node* mergedLL = mergeThis(head0, tail0, head1, tail1, head2, tail2);

    // printing mergedLL
    print(mergedLL);

    // print(head0);
    // print(head1);
    // print(head2);

}

int main(){       
          
    // 1 0 2 1 0 2 1

    // creating in heap memory    
    Node* node1 = new Node(1);
          
    Node *head = node1;
    Node *tail = node1;
    insertattail(tail, 0);
    insertattail(tail, 2);
    insertattail(tail, 1);
    insertattail(tail, 0);
    insertattail(tail, 2);
    insertattail(tail, 1);
    
    // sort012(head);

    // print(head);

    // second approach - creating different linked list for 0's 1's and 2's then merging them all

    sort012bymerging(head);

}