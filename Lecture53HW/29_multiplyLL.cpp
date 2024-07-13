#include <bits/stdc++.h>
using namespace std;

/*  Problem Statement - Multiply Linked Lists

    Given two numbers represented by linked lists. Your task is to find the multiplied list and return the
    head of the multiplied list.

    The multiplied list is a linked list representation of the multiplication of two numbers.


    Link to CodingNinjas [https://www.naukri.com/code360/problems/multiply-linked-lists_983603?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker]
*/

// solution is not working on CN on a test case but on vs code

class Node
{
public:
    int data;   // integer data
    Node *next; // pointer variable "add" that stores the address of object

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertattail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head)
{
    Node *current = head;

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
};

Node *multiplyLLwithDigit(Node *head, int digit)
{
    Node *prodLL = new Node(-1);
    Node *prodPtr = prodLL;
    Node *prodHead = prodLL;
    Node *mainptr = head;
    int carry = 0;

    while (mainptr != NULL)
    {
        int sum = carry + (mainptr->data) * digit;
        int ansDigit = sum % 10;
        carry = sum / 10;

        prodPtr->next = new Node(ansDigit);

        mainptr = mainptr->next;
        prodPtr = prodPtr->next;

        if (mainptr == NULL && carry != 0)
        {
            prodPtr->next = new Node(carry);
        }
    }

    return prodHead->next;
}

Node *reverseLL(Node *head)
{
    Node *headNew = head;

    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        Node *foreward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = foreward;
    }

    return prev;
};

void add2LL(Node *&head1, Node *head2)
{
    Node *curr1 = head1;
    Node *curr2 = head2;

    int carry = 0;

    while (curr1 != NULL || curr2 != NULL)
    {
        int sum = carry + curr1->data + curr2->data;
        int ansDigit = sum % 10;
        carry = sum / 10;

        curr1->data = ansDigit;

        // cout << curr1->next << endl;

        if (curr1->next != NULL)
        {
            curr1 = curr1->next;
        }
        else if (curr1->next == NULL && curr2->next != NULL)
        {
            curr1->next = curr2;
        }

        if (curr2->next != NULL)
        {
            curr2 = curr2->next;
        }
        else if (curr1->next != NULL && curr2->next == NULL)
        {
            curr1->data = curr1->data + carry;
            break;
        }
        // in case both linked list ends and a carry still remains
        if (curr1 == NULL && curr2 == NULL && carry != 0)
        {
            curr1->next = new Node(carry);
        }
    }

    // return head1;
}

Node *add2LL2(Node *head1, Node *head2)
{
    if (head1->data == -1 && head1->next == NULL)
    {
        return head2;
    }

    Node *curr1 = head1;
    Node *curr2 = head2;

    int carry = 0;

    while (curr1 != NULL || curr2 != NULL)
    {
        int sum = carry + curr1->data + curr2->data;
        int ansDigit = sum % 10;
        carry = sum / 10;

        curr1->data = ansDigit;

        if (curr1->next != NULL && curr2->next != NULL)
        {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        else if (curr1->next == NULL)
        {
            curr1->next = curr2->next;
            break;
        }
        else if (curr2->next == NULL)
        {
            break;
        }
    }

    if (carry != 0)
    {
        if (curr1->next != NULL)
        {
            curr1->next->data += carry;
        }
        else
        {
            curr1->next = new Node(carry);
        }
    }

    return head1;
}

Node *multiply(Node *head1, Node *head2)
{
    head1 = reverseLL(head1);
    head2 = reverseLL(head2);

    Node *curr1 = head1;
    Node *curr2 = head2;
    Node *ansList = new Node(-1);
    Node *ansPtr = ansList;

    while (curr2 != NULL)
    {
        // cout << "ansptr " << ansPtr->data << endl;
        // cout << "fault 1" << endl;
        Node *addList = multiplyLLwithDigit(curr1, curr2->data);
        // print(addList);
        // cout << "fault 2" << endl;
        // cout << "fault 3, curr2 data : " << curr2->data << endl;
        ansPtr = add2LL2(ansPtr, addList);
        curr2 = curr2->next;
        // cout << "fault 4" << endl;
        ansPtr = ansPtr->next;
        // cout << "fault 5" << endl;
    }

    return reverseLL(ansList);
};

Node *removeLeadingZeroes(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr->data == 0)
    {
        prev = curr;
        if (curr->next == NULL)
        {
            return NULL;
        }
        else
        {
            curr = curr->next;
        }
        delete prev;
    }

    // cout << curr->data << endl;

    return curr;
}

Node *multiply2(Node *head1, Node *head2)
{
    head1 = removeLeadingZeroes(head1);
    head2 = removeLeadingZeroes(head2);
    Node *temp = new Node(0);

    if (head1 == NULL)
    { // multiplying with 0
        return temp;
    }
    else if (head2 == NULL)
    { // multiplying with 0
        return temp;
    }
    else if (head1->data == 1 && head1->next == NULL)
    {
        return head2;
    }
    else if (head2->data == 1 && head2->next == NULL)
    {
        return head1;
    }

    head1 = reverseLL(head1);
    head2 = reverseLL(head2);

    Node *curr2 = head2;
    Node *result = new Node(0);
    Node *resultPtr = result;

    while (curr2 != NULL)
    {
        Node *addList = multiplyLLwithDigit(head1, curr2->data);
        result = add2LL2(result, addList);

        curr2 = curr2->next;

        if (result->next == NULL)
        {
            result->next = new Node(0);
        }
        result = result->next;
    }

    return reverseLL(resultPtr);
}

int main()
{
    Node *node1 = new Node(0);

    Node *head = node1;
    Node *tail = node1;

    insertattail(tail, 2);
    insertattail(tail, 3);
    insertattail(tail, 4);
    insertattail(tail, 0);

    Node *node2 = new Node(0);

    Node *head2 = node2;
    Node *tail2 = node2;

    insertattail(tail2, 0);
    insertattail(tail2, 1);

    Node *ans = multiply2(head2, head);
    print(ans);
}

// Node *multiplyWithDigit(Node *head, int digit){
//     Node *dummy = new Node(-1);
//     Node *dummyA = dummy;
//     Node *curr = head;
//     int carry = 0;
//     while (curr != NULL || carry != 0){
//         int sum = carry + (curr != NULL ? curr->data : 0) * digit;
//         int digitt = sum % 10;
//         carry = sum / 10;
//         dummyA->next = new Node(digitt);
//         if (curr != NULL)
//             curr = curr->next;
//         dummyA = dummyA->next;
//     }

//     return dummy->next;
// }

// void addTwoLL(Node *&head, Node *&ansList){
//     Node *c1 = head;
//     Node *c2 = ansList;
//     int carry = 0;
//     while (c1 != NULL || carry != 0{
//         int sum = carry + (c1 != NULL ? c1->data : 0) + (c2->next != NULL ? c2->next->data : 0);
//         int digitt = sum % 10;
//         carry = sum / 10;
//         if (c2->next != NULL)
//             c2->next->data = digitt;
//         else
//             c2->next = new Node(digitt);
//         if (c1 != NULL)
//             c1 = c1->next;

//         c2 = c2->next;
//     }
// }

// // *****************************************************************

// Node *reverseLinkedList(Node *head){
//     if (head == NULL || head->next == NULL){
//         return head;
//     }
//     Node *prev = NULL;
//     Node *curr = head;
//     Node *next = NULL;
//     while (curr != NULL){
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }
//     return prev;
// }
// // ****************************************************************

// Node *multiplyLL(Node *head1, Node *head2){
//     head1 = reverseLinkedList(head1);
//     head2 = reverseLinkedList(head2);
//     Node *curr2 = head2;
//     Node *dummy = new Node(-1);
//     Node *ansList = dummy;
//     while (curr2 != NULL){
//         Node *prod = multiplyWithDigit(head1, curr2->data);
//         curr2 = curr2->next;
//         addTwoLL(prod, ansList);
//         ansList = ansList->next;
//     }
//     Node *answer = reverseLinkedList(dummy->next);
//    // we need to eliminate left side 0's from ans
//     Node *zero_hatao = answer;
//     while (zero_hatao != NULL && zero_hatao->next != NULL){
//         if (zero_hatao->data == 0){
//             zero_hatao = zero_hatao->next;
//         }else{
//             break;
//         }
//     }
//     return zero_hatao;
// }