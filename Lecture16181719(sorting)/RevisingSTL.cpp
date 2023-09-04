#include<bits/stdc++.h>
#include<set>
using namespace std;



/*  STL -

    The Standard Template Library (STL) is a set of C++ template classes to provide 
    common programming data structures and functions such as lists, stacks, arrays, etc. 
    It is a library of container classes, algorithms, and iterators.

*/



int main(){
    // Arrays:
    // cout << "Array: "<< endl;
    
    // their is a different initialisation of array if we do it through STL
    array <int,6> arr = {1,2,3,4,5,6};
    
    // to get the size of this STL array;
    int size = arr.size();

    // to print the value of a particular index:
    cout << arr.at(0) << " ";

    // use this keywords :
    // .front() - to get the first element of the array
    // .back() - to get the last element of the array
    // .empty() - to check if the array is empty (returns bool - 0 for not empty and 1 for empty);


    // Vector
/*  Vector is same as array but it's size automatically dynamically increases based on the number of inputs in that vector(array)
    initially the capacity of the vector is 1 then if we push 2 elements in it, it doubles the capacity
    again if the capacity is full then the vector doubles it's capacity than what is was
    capacity shows how much memory is reserved & size will show you the total size 
    allotted tp the vector; 
*/
    // initialisation of vector
    vector<int> vect;

    // to push elements in the vector use .push_back();
    vect.push_back(0);
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);
    // at this point the size of this vector should be 5 and capacity should be 8
    // checking capacity 
    cout << "Capacity of the vector" << vect.capacity() << endl;
    // checking size 
    cout << "Size of the vector" << vect.size()<< endl;

    // use this keywords -
    // .front() - to print the first element 
    // .back() - to print the last element 
    // .at() - to print element at a particular index
    // .pop_back() - to pops last element of the vector
    // .clear() - to clear the vector 

    // Note - if you already know the size of the vector you can try this -
    
    vector<int> vect2(5,0);
    // first parameter represents the capacity of vector and second represents 
    // the initial value of all the elements
    int size3 = vect2.size();
    // printing all elements

    cout << "Printing the vector: " << endl;
    for(int i=0; i<size3; i++){
        cout << vect2.at(i) << " ";
    } cout << endl << endl;

    // to copy a vector to a new one use this 
    vector<int> newVect(vect2); 
    // now newVect is same as vect2
    
    
    // Queue
    cout << "Queue" << endl;

    // initialisation
    queue <string> q;

    // to push elements in this queue we'have to use .push keyword;
    q.push("Aryan ");
    q.push("is ");
    q.push("revising ");
    q.push("STL "); 

    // use this keywords -
    // .front() - to *print* the topmost element (checks element)
    // .back() - to *print* the bottom most element (checks element)
    // .pop() - to eject the element from the top (removes an element from the top)
    // .size() - to get the size;
    // use pop along with front so that you can print and remove element at the same time

    
    /* PRIORITY QUEUE */
    // in a priority queue it pops elements in order (ascending - minHeap, descending - maxHeap) 
    // In a Min-Heap, the smallest element is the first to be popped from the heap. In a Max-Heap, the largest element 
    // is the first to be popped from the heap

    // initialising a maxHeap

    cout << "Priority Queue (maxHeap)" << endl;
    priority_queue<int> maxheap;
    
    maxheap.push(5);
    maxheap.push(21);
    maxheap.push(12);
    maxheap.push(4);
    maxheap.push(6);

    int size1 = maxheap.size();

    for(int i=0; i<size1; i++){
        cout << maxheap.top() << " ";
        maxheap.pop();
    }cout << endl;
    // output = 21,12,6,5,4


    // initialising a minHeap
    // priority_queue <Type, vector<Type>, ComparisonType > min_heap;    priority_queue<int, vector<int>, greater<int>> maxheap;
    cout << "Priority Queue (minHeap)" << endl;

    priority_queue<int, vector<int>, greater<int>> minheap;

    minheap.push(5);
    minheap.push(21);
    minheap.push(12);
    minheap.push(4);
    minheap.push(6);

    int size2 = minheap.size();

    for(int i=0; i<size2; i++){
        cout << minheap.top() << " ";
        minheap.pop();
    }cout << endl;
    // output = 4,5,6,12,21



    // dequeue
    // deQueue - a generalized version of Queue data structure that allows insert and delete at both ends.
    cout << "deQueue : " << endl;
    // same keywords
    // .push_back();
    // .push_front();
    // .pop_back();
    // .pop_front():
    // .erase(from, to);
    // while using erase function remember that in braces you have two inputs where you have to provide indexes to erase them
    // don't need to use .to while printing
    // dq.erase(dq.begin(),dq.begin()+2);

    // list also works the same (you can try it)
    // for stack - first In Last Out data structure. operations : top push pop  (others might be same as queue)
    


    // Set
    cout << "Set : " <<endl;
    // two types : ordered and unordered
    // set doesn't print duplicate inputs
    // ordered set prints sorted elements
    // operators : insert erase count begin 
    // use .count(1) to check if 1 is present or not
    // use .find(1) to get the reference of the value
    
    // insert find erase count - time complexity - O(logn)
    // size begin end empty - time complexity - O(1)

    // initialise 
    // set<int> s;
    // s.insert(1);
    // s.insert(3);
    // s.insert(2);
    // s.insert(54);
    // s.insert(6);
    // s.insert(5);
    // s.insert(8);

    // cout << s << endl;



    // Map
    // in map they store a sorted pair of key and the value of that key mapped to it, in map each key is unique it can be initialised or deleted but cannot be altered  
    cout << "Map :\n";
    map<int,string> m;

    m[0]= "string1";
    m[1]= "string2";
    m[2]= "string3";
    m[3]= "string4";
    // even if this initialisation are unordered, the output is sorted 

    int size4 = m.size();
    for(int i=0; i<size4; i++){
        cout << "value at " << i << " is : " << m.at(i) << endl;
    }
    // erase(key)
    // insert erase find count - time complexity - O(logn) because this implementation is based on the use of red black tree or balanced tree which has the time complexity of O(logn)  
    // in unordered the time complexity is O(1);




    // STL Algorithms
    cout<< "STL Algorithms : " << endl;

    // Stl algorithms are pre build algorithms eg. binary search etc;

    vector<int> vecForAlgo;

    // this inputs must be sorted
    vecForAlgo.push_back(2);
    vecForAlgo.push_back(3);
    vecForAlgo.push_back(12);
    vecForAlgo.push_back(43);
    vecForAlgo.push_back(45);
    vecForAlgo.push_back(56);
    vecForAlgo.push_back(78);

    // sort(vecForAlgo.begin(), vecForAlgo.end());
    // this sort function works on an sorting concept called introsort which is a combination of quick, heap and insertion sort

    cout << "Finding 5 in this vector : " << binary_search(vecForAlgo.begin(),vecForAlgo.end(),5) <<  endl;
    cout << "Finding 3 in this vector : " << binary_search(vecForAlgo.begin(),vecForAlgo.end(),3) << endl;
    
    // Upper/lower bound 
    /*  upper_bound() returns an iterator pointing to the first element in the range [first, last) that is greater than the value. If no such an element is found, return end().
        lower_bound() returns an iterator pointing to the first element in the range [first, last) which is greater or equal to the value. If no such an element is found, return end().
    
    */
    cout << "Finding lower bound of 3 in this vector : " << lower_bound(vecForAlgo.begin(),vecForAlgo.end(),3)-vecForAlgo.begin() << endl;
    cout << "Finding upper bound of 45 in this vector : " << upper_bound(vecForAlgo.begin(),vecForAlgo.end(),45)-vecForAlgo.begin() << endl;

    // get Min and Max from the array

    // Find the min element
    cout << "\nMin Element = " << *min_element(vecForAlgo.begin(), vecForAlgo.end()) << endl;
    cout << "\nMax Element = " << *max_element(vecForAlgo.begin(), vecForAlgo.end()) << endl;

    // reverse an array;
    reverse(vecForAlgo.begin(),vecForAlgo.end());
    for(int i=0; i<vecForAlgo.size(); i++){
        cout << vecForAlgo.at(i) << " ";
    } cout << endl;

    // rotate an array;
    rotate(vecForAlgo.begin(),vecForAlgo.begin()+2, vecForAlgo.end());

    for(int i=0; i<vecForAlgo.size(); i++){
        cout << vecForAlgo.at(i) << " ";
    } cout << endl;

}