#include<bits/stdc++.h>
using namespace std;

// splitting a circular linked list into 2 halves (HomeWork)

class Node{
    public:
    Node* next;
    int data;

    Node(int value){
        this->data = value;
        this->next = NULL;
    }
};

void insertattail(Node* &head, Node* &tail, int data){
    Node* temp = new Node(data);

    tail->next = temp;
    tail = temp;

    tail->next = head;
}

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
        if(temp == head){
            break;
        }
    }
    cout << endl;
}

void splitList(Node* &head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != head && fast->next != head){

        slow = slow->next;
        fast = fast->next;
        if(fast->next != head){
            fast = fast->next;
        }
    }

    cout << "head: " << head->data << endl;
    cout << "Slow: " << slow->data << endl;    
    cout << "fast: " << fast->data << endl << endl;

    Node* temp = head;
    Node* temp2 = slow->next;

    Node* listone = new Node(head->data);
    Node* listtwo = new Node(slow->data);

    Node* ptr1 = listone;
    Node* ptr2 = listtwo;

    Node* headone = listone;
    Node* headtwo = listtwo;

    int count=0;
    while(temp != slow){
        count++;
        temp = temp->next;
    }

    cout << "count: " << count << endl << endl;
    temp = head;

    while(count>0){
        ptr1->next = temp->next;
        ptr1 = ptr1->next;
        temp = temp->next;


        if(ptr2->next == head){
            break;
        }

        ptr2->next = temp2->next;
        ptr2 = ptr2->next;
        temp2 = temp2->next;

        // cout << "ptr1: " << ptr1->data << endl;   
        // cout << "ptr2: " << ptr2->data << endl;
        
        // cout << "ptr1 next: " << ptr1->data << endl;    
        // cout << "ptr2 next: " << ptr2->data << endl;   

        count--;
    }

    cout << endl;

    ptr1->next = NULL;
    ptr2->next = NULL;

    cout << "printing listone : " << endl;
    print(headone);
    cout << "printing listtwo : " << endl;
    print(headtwo);

}

int main(){
    
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertattail(head, tail, 20);
    insertattail(head, tail, 30);
    insertattail(head, tail, 40);
    insertattail(head, tail, 50);
    insertattail(head, tail, 60);
    insertattail(head, tail, 70);
    insertattail(head, tail, 80);

    cout << "nodelist: ";
    print(head);

    cout << endl;

    splitList(head);

}