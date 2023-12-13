#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

void insertathead(Node* &head, int data){

    Node* temp = new Node(data);

    temp->next = head; 
    head = temp;

}

void print(Node* head){
    Node* current = head;

    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
};

int getLength(Node* head){
    Node* temp = head;
    int count = 0;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    return count;
};

int getMiddle(int middle, Node* head){
    // cout << middle << endl;
    Node* current = head;

    while(middle > 0){
        cout << middle << " ";
        current = current->next;
        middle--;
    }

    cout << endl;
    return current->data;
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;

    insertathead(head, 2);
    insertathead(head, 3);
    insertathead(head, 4);
    insertathead(head, 5);
    insertathead(head, 6);

    // cout << getLength(head) << endl;

    int middleElementAt;
    
    // cout << getLength(head) << endl;

    if(getLength(head) % 2 == 0){
        // it's even
        middleElementAt = getLength(head)/2;
    }else{
        middleElementAt = getLength(head)/2;
    }

    cout << getMiddle(middleElementAt, head) << endl;

    print(head);

}