#include<bits/stdc++.h>
using namespace std;

/*  Add two numbers represented by linked lists
    Given two decimal numbers represented by two linked lists of size N and M respectively. 
    The task is to return a linked list that represents the sum of these two numbers.
    
    For example, the number 190 will be represented by the linked list, 1->9->0->null, 
    similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be 
    represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

    Example 1:

    Input:
    N = 2
    valueN[] = {4,5}
    M = 3
    valueM[] = {3,4,5}
    Output: 3 9 0  
    Explanation: For the given two linked
    list (4 5) and (3 4 5), after adding
    the two linked list resultant linked
    list will be (3 9 0)

    Expected Time Complexity: O(N+M)
    Expected Auxiliary Space: O(Max(N,M)) for the resultant list.

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

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL) {
        Node* Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }

    return prev; 
}

// failed approach (I was trying to save space, but couldn't had to apply sooooo many conditions,
// instead we could do this with a lil space complexity and 3 conditions see addApproach2)
Node* add(Node* head, Node* head2){
    Node* curr1 = head;
    Node* curr2 = head2;
    int prevcarry = 0;
    int sum = 0;

    while(true){
        sum = curr1->data + curr2->data + prevcarry;
        if(sum > 9){
            // cout << "sum before: " << sum << " " << sum/10 << endl;
            int tempsum = sum;
            sum = sum%10;
            curr1->data = sum;
            prevcarry = tempsum/10;
            // cout << "if: " << sum << " " << prevcarry << endl;
        }
        else{
            // cout << "else: " << sum << " " << prevcarry << endl;
            curr1->data = sum;
            prevcarry = 0;
        }

        if(curr1->next == NULL){
            if(curr2->next == NULL){
                if(prevcarry > 0){
                    Node* temp = new Node(prevcarry);
                    curr1->next = temp;
                }
                return reverse(head);
            } 
            
            Node* temp = new Node(0);
            curr1->next = temp;
        }if(curr2->next == NULL){
            if(prevcarry > 0){
                if((prevcarry + curr1->data) > 9){
                    sum = curr1->data + prevcarry;
                    int tempsum = sum;
                    sum = sum%10;
                    curr1->next->data = sum;
                    prevcarry = tempsum/10;
                }else{
                    curr1->next->data = curr1->next->data + prevcarry;
                }
            }
            return reverse(head);
        }

        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return head;
}

Node* addApproach2(Node* head, Node* head2){
    Node* curr1 = head;
    Node* curr2 = head2;
    Node* sumNode = new Node(0);
    // return this sumHead from addApproach2
    Node* sumHead = sumNode;
    // send to insertattail
    Node* sumTail = sumNode;
    int prevcarry = 0;
    int sum = 0;

    // recheck this
    while(curr1 != NULL && curr2 != NULL){
        sum = curr1->data + curr2->data + prevcarry;
        if(sum > 9){
            int tempsum = sum;
            sum = sum%10;
            insertattail(sumTail, sum);
            prevcarry = tempsum/10;
        }else{
            insertattail(sumTail, sum);
            prevcarry = 0;
        }

        if(curr1->next == NULL && curr2->next != NULL){
            curr1->data = 0 + prevcarry;
            curr2 = curr2->next;
        }else if(curr2->next == NULL && curr1->next != NULL){
            curr1 = curr1->next;
            curr2->data = 0 + prevcarry;
        }else if(curr1->next != NULL && curr2->next != NULL){
            curr1 = curr1->next;
            curr2 = curr2->next;
        }else if(curr1->next == NULL && curr2->next == NULL){
            if(prevcarry > 0){
                insertattail(sumTail, prevcarry);
            }    
            return reverse(sumHead->next);
        }
    }

};

int main(){

    // 13
    // 9 9 1 1 3 8 6 0 4 3 4 2 8
    // 12
    // 7 7 9 4 6 8 1 8 1 9 0 5

    // Your Code's output is: 
    // 10 6 9 0 8 5 4 2 2 5 3 3 3
    // It's Correct output is: 
    // 1 0 6 9 0 8 5 4 2 2 5 3 3 3

    // 5
    // 7 7 0 3 2
    // 5
    // 2 9 6 6 0

    Node* node1 = new Node(7);

    Node *head = node1;
    Node *tail = node1;

    insertattail(tail, 7);
    insertattail(tail, 0);
    insertattail(tail, 3);
    insertattail(tail, 2);
    
    // int array3[1] = {5};
    // int array4[2] = {4,5};

    // for(int i=1; i<13; i++){
    //     insertattail(tail, array3[i]);
    // }

    // insertattail(tail, 7);
    // insertattail(tail, 8);
    // insertattail(tail, 3);
    // insertattail(tail, 6);
    // insertattail(tail, 9);
    // insertattail(tail, 4);

    // print(head);

    Node* node2 = new Node(2);
    Node *head2 = node2;
    Node *tail2 = node2;

    // for(int i=1; i<12; i++){
    //     insertattail(tail2, array4[i]);
    // }

    insertattail(tail2, 9);
    insertattail(tail2, 6);
    insertattail(tail2, 6);
    insertattail(tail2, 0);

    // cout << "Before reverse: " << endl;
    // print(head);
    // print(head2);

    // head = reverse(head);   
    // head2 = reverse(head2);

    // cout << "After reverse: " << endl;
    // print(head);
    // print(head2);
    // cout << endl;

    // Node* finalAdd = new Node(10);
    // finalAdd = add(head, head2);
    // print(finalAdd);

    // approach 2 

    head = reverse(head);
    head2 = reverse(head2);

    cout << "After reverse: " << endl;
    print(head);
    print(head2);
    cout << endl;

    Node* finalNode = new Node(0);
    finalNode = addApproach2(head, head2);
    print(finalNode);
    
}