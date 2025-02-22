#include <bits/stdc++.h>
#include <queue>
using namespace std;


int main() {
    queue <int> q;
 
    q.push(10);
    cout << "pushed 10" << endl;
    cout << "front of q: " << q.front() << endl;
    
    q.push(20);
    cout << "pushed 20" << endl;
    cout << "front of q: " << q.front() << endl;
    cout << "back of q: " << q.back() << endl;

    cout << "size of q: " << q.size() << endl;

    q.pop();

    cout << "front of q after popping once: " << q.front() << endl;

    cout << "size of q is: " << q.size() << endl;

    if(q.empty()){
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

}