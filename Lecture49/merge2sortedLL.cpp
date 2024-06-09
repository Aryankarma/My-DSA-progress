#include<bits/stdc++.h>
using namespace std;

// Merge Two Sorted Lin


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

// 1 73 89 95 -1
// 3 54 86 100 -1

// not working (test cases failed)
Node* mergeList(Node* head1, Node* head2){
    Node* i = head1;
    Node* j = head2;

    while(true){
        if((i->data <= j->data && j->data <= i->next->data) && (i->next != NULL)){
            cout << "inside wherer it should not be 1" << endl;
            
            Node* inext = i->next;
            Node* jnext = j->next;

            i->next = j;
            j->next = inext;
            
            if(jnext != NULL){
                j = jnext;
            }else{
                cout << "head1 data: " << head1->data << " i data : " << i->data << " j data: " << j->data << endl;
                cout << "break condition " << endl;

                break;
            }

            cout << "first condition " << endl;
            cout << i->data << endl;
            cout << j->data << endl;
        }
        if(i->next == NULL){
            cout << "i next null" << endl;
        }

        else if(i->data <= j->data && i->next == NULL){
            cout << "inside wherer it should be" << endl;
            // only one element in first list that is smaller than the first element of second list
            // i is at last element in first list that is smaller than the first element of second list
                        
            i->next = j;
            break;
        }else if(j->data <= i->data){
            cout << "inside wherer it should not be 2" << endl;

            cout << "before else running " << endl;

            Node* jnext = j->next;
            Node* inext = i->next;

            if(j->next == NULL){
                j->next = i;
                break;
            }
            if(j->data <= i->data && i->data <= jnext->data){
                j->next = i;
                if(i->next == NULL){
                    i->next = jnext;
                    break;
                }else{
                    i->next = jnext;
                    i = inext;
                }
            }else if(!(j->data <= i->data && i->data <= jnext->data)){
                j = j->next;
            }
        }else{          
            i = i->next;
            cout << "updating i " << i->data << " j data " << j->data << endl;
        }
        cout << "while running " << endl; 
    }

    cout << "out of while " << endl;

    if(head1->data < head2->data){
        print(head1);
    }else{
        print(head2);
    }
    return head1;
};

// 1 73 89 95 -1
// 3 54 86 100 -1


Node* mergeList2(Node* head1, Node* head2) {
    Node* temp = new Node(0);
    Node* current = temp;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    if (head1 != NULL) {
        current->next = head1;
    } else {
        current->next = head2;
    }

    Node* mergedHead = temp->next;
    delete temp;

    return mergedHead;
}



int main(){
    // creating in heap memory
    Node* node1 = new Node(5);

    Node *head1 = node1;
    Node *tail1 = node1;
    
    Node* node2 = new Node(1);

    Node *head2 = node2;
    Node *tail2 = node2;

    insertattail(tail2, 3);
    insertattail(tail2, 6);
    insertattail(tail2, 10);

    Node* headTemp = mergeList2(head1, head2);
    print(headTemp);                          
}   