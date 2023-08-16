#include<bits/stdc++.h>
using namespace std;

int main(){
    int i=1;
    int *ptr = &i;            // declaring and initializing a pointer variable that is pointing towards the address of i
    cout << ptr << endl;      // prints the address of i -> (0x33f8e8)
    cout << *ptr << endl;     // prints the value at of the address stored in this pointer variable -> (i)
    int **ptr2 = &ptr;        // declaring and initializing a pointer variable that is pointing to the address of another pointer variable hence **(two stars) -> (0x33f8e4)
    cout << ptr2 << endl;     // prints the address of that another pointer variable that we stored while declaring -> (0x33f8e4)
    cout << *ptr2 << endl;    // prints the value of the memory address stored in this pointer variable -> (0x33f8e8)

    cout << endl;

    // if we want to initialize a pointer variable and not declare it -

    int j=1;
    int *ptr3;
    cout << ptr3 << endl;               // prints an unknowing address -> (0x26f950)  |  hence initializing like this is bad practice.
    cout << *ptr3 << endl;              // prints an unknowing value -> (1130117701)  |  hence initializing like this is bad practice.
    
    cout << endl;

    int k=1;
    int *ptr4=0;                        // initialize like this 
    ptr4 = &k;                          // declare like this
    cout << "1 : " <<  ptr4 << endl;    // prints the address stored in ptr4 -> (0)
    cout << "2 : " << *ptr4 << endl;    // prints nothing

    cout << endl;

    // copying a pointer

    int *ptrCpy = ptr;
    cout << ptrCpy << endl;
    cout << *ptrCpy << endl;

    cout << endl;

    // pointer arithmetic addition

    int l=2;
    int *ptrAdd = &l;
    cout << *ptrAdd << endl;        // prints 2
    cout << ptrAdd << endl;         // prints the address of l
    *ptrAdd = *ptrAdd + 1;          // increases the number, note - *ptrAdd++ or (*ptrAdd)++ doesn't work
    cout << *ptrAdd << endl;        // prints the address of l
    ptrAdd = ptrAdd +1;             // increases the address, note - ptrAdd++ or (ptrAdd)++ doesn't work
    cout << ptrAdd << endl;         // prints the increased address of l

    cout << endl;

    // arrays with pointers (works weirdly)

    int arr[10] = {0};
    cout << arr << endl;


}   