#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void splitList(Node* source, Node** front, Node** back) {
    if (source == nullptr || source->next == nullptr) {
        *front = source;
        *back = nullptr;
        return;
    }

    Node* slow = source;
    Node* fast = source->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    
    std::cout << "back list: " << slow->next->data << endl;
    std::cout << "front list: " << source->data << endl;   

    slow->next = nullptr;
}

Node* merge(Node* a, Node* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;

    Node* result = nullptr;

    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

void mergeSort(Node** head) {
    Node* current = *head;
    Node* a;
    Node* b;

    if (current == nullptr || current->next == nullptr) {
        return;
    }

    splitList(current, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *head = merge(a, b);
}

void printList(Node* node) {
    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    Node* head = new Node(12);
    head->next = new Node(11);
    head->next->next = new Node(13);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(6);

    std::cout << "Original Linked List: ";
    printList(head);

    mergeSort(&head);

    std::cout << "Sorted Linked List: ";
    printList(head);

    return 0;
}