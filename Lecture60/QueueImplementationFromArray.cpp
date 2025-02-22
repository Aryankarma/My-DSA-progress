#include <bits/stdc++.h> 
class Queue {
    int* arr;
    int qfront;
    int rear;
    int size;

public:
    Queue() {
        arr = new int[100000];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty() {
        if(qfront == rear){
            return true;
        }else{
            return false;
        }
    }

    // push
    void enqueue(int data) {
        if(rear == size){
            cout << "Queue is full" << endl;
        }else{
            arr[rear] = data;
            rear++;
        }
    }

    // pop
    int dequeue() {
        if(qfront == rear){ // means it's empty
            return -1;
        } else {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear){
                qfront = 0;
                rear = 0;
            }
            
            return ans;
        }
    }

    int front() {1
        if(qfront == rear){
            return -1;
        }else{
            return arr[qfront];
        }
    }
};