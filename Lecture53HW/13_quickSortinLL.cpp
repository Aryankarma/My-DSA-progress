#include<bits/stdc++.h>
using namespace std;

// pretty class
class Node{
    public:
    int data;
    Node* next = NULL;

    // pretty constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertattail(Node* &tail, int data){
    Node* tempLL = new Node(data);

    tail->next = tempLL;
    tail = tempLL;
}

void print( Node* head ){
    
    while(head!= NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


Node* quickSort3(Node* head){

    // base case
    if( head == NULL || head->next == NULL ){
        return head;
    }

    Node* pivot = head; // assuming head is pivot
    Node* curr = head->next; // curr ptr to iterate original list
    
    Node* leftList = new Node(-1); // list to chain elements smaller than pivot
    Node* rightList = new Node(-1); // list to chain elements greater than pivot

    Node* left = leftList; // ptr for chaining nodes
    Node* right = rightList; // ptr for chaining nodes

    // told you na iterate krenge curr se
    while( curr != NULL ){

        if( curr->data <= pivot->data ){ // check if curr element is smaller than pivot element
            left->next = curr;
            left = left->next;
        }else{
            right->next = curr;
            right = right->next;
        }
        curr = curr->next;
    }

    // now we have left and right lists but one of them may contain unnecessary elements in the end, unlink them 
    left->next = NULL;
    right->next = NULL;

    // clearing pivot
    pivot->next = NULL;

    // send the current left and right list to apply this algo recursively (dividing them untill 1 element remains in the list)
    Node* leftptr = quickSort3(leftList->next); // sending next node to unlink -1  
    Node* rightptr = quickSort3(rightList->next); // sending next node to unlink -1  

    // common the rest is understandable (dry code)
    
    if ( leftptr == NULL && rightptr != NULL ) {

        pivot->next = rightptr;
        return pivot;
    
    } else if ( rightptr == NULL && leftptr != NULL ) {
    
        Node* till = leftptr;
        
        while (till -> next != NULL){
            till = till -> next;
        }

        till->next = NULL;
        till->next = pivot;
        // pivot->next=NULL;
        return leftptr;
    
    } else {
    
        Node* till=leftptr;
        
        while( till->next != NULL ){
            till = till->next;   
        }                
        
        till->next = NULL;
        till->next = pivot;
        pivot->next = rightptr;
        return leftptr;
    }
}


int main(){
    Node* LinkedList = new Node(5);
    Node* tail = LinkedList;
    Node* head = LinkedList;

    insertattail( tail, 4);
    insertattail( tail, 6);
    insertattail( tail, 12);
    insertattail( tail, 5);
    insertattail( tail, 6);
    insertattail( tail, 1);

    // quickSort(head); // failed

    cout << "printing original list: " << endl;
    print(head);

    Node* final = NULL;
    final = quickSort3(head);

    cout << "printing sorted list: " << endl;
    print(final);   

}