#include<bits/stdc++.h>
using namespace std;

// same memory location different names to access it

void updatebyValue(int x){ 
    x++;
    // this function takes extra memory
}
void updatebyReferenceVariable(int &x){
    x++;
    // this function doesn't takes extra memory
}

// similar concept but it doesn't work (bad practice)
// int& returnAddressVariable(int x){
//     int num = x;
//     int& ans = num;
//     return ans;
// }

int main(){
    int i=10;
    int &j = i; // creating a reference variable of i (named - j)

    cout << "i before " << i << endl;
    cout << "j before " << j << endl;

    i++;

    cout << "i after " << i << endl;
    cout << "j after " << j << endl;
    // i=11 & j=11

    // sending reference variable to functions 
    updatebyValue(i);
    cout << "after updating by value " << i << endl; // doesn't update cause it was sent as a copy.
    updatebyReferenceVariable(j);
    cout << "after updating by reference " << j << endl; // prints an updates value cause in function we took input as a reference variable

    // cout << i << endl;
    // // creating return Address Variable function 
    // int x = returnAddressVariable(i); // i = 11
    // cout << x << endl;

    // new keyword - we use new keyword when we want to use the heap memory, [there are two types of memory stack 
    // and heap and the compiler takes some memory from the heap memory to run the code (heap memory >>> stack memory)] so when we 
    // use new keyword it sends the address of the variable that is in the heap memory and we can save it using a pointer variable.
    char *ptr = new char;
    // this creates a pointer variable that stores the address of a int variable tha is located in the heap memory so whenever we 
    // try to modify ptr, we are basically modifying a value in the heap. here the pointer variable that is located in the stack 
    // memory takes 8bytes (size of address) and the actual variable that is located in the heap memory takes 1byte (size of char) 
    // so the overall memory usage is 9 bytes;
    int *ptrInt = new int;
    *ptrInt = 5;
    cout << *ptrInt << endl;
    // takes total of 12 bytes 8 in stack and 4 in heap

/*  this concept is used in dynamic memory allocation, when we create an array that takes the input as size of array in the runtime 
    and as we know the compiler takes some stack memory from the heap let's say we have stack memory of 1000bytes and then on runtime 
    we are asking the user to input the size of array so that the compiler can create an array of that size. and if by some chance the 
    user input a size of array that is more that the stack memory. The PROGRAM CAN CRASH. hence taking the size of array on runtime is 
    a bad practice. instead we can use dynamic memory allocation to create an array, that takes space from the heap.        
    ex.

    cin >> n; 
    int *arr = new int[n];
    mow we can take an input n to allocate that size of array in the heap memory.
    if n = 20; the array takes 8 bytes of memory from the stack and the 20*4 bytes from the heap.
*/

/*
    Note - in static allocation the memory gets free every time the compiler goes out of the block scope 
    but in heap we have to manually release the memory by using delete keyword
    use delete []ptrInt to delete arrays and delete i to delete integer from heap
*/


}