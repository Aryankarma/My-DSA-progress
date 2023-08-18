#include<bits/stdc++.h>
using namespace std;

void printPtr(int *num){
    cout << num << endl;    // prints the address of var
    cout << *num << endl;   // prints the value of var
}

void updtPtr(int *num){
    *num = *num+1;          // updates the value from reference
}

int getSum(int arr[], int size){    // int arr[] works same as *arr because of the reason stated below
    cout << sizeof(arr) << endl;    // prints the size of array (prints 4/8) reason - In C++, when you pass an array to a function, you're actually passing a pointer to the first element of the array. Therefore, the sizeof(arr) in your code will return the size of a pointer, which is typically 4 bytes on a 32-bit system and 8 bytes on a 64-bit system. This is why you're getting 4 as the output.
    int sum = 0;
    for(int i=0; i<size; i++){
        sum = sum + arr[i];
    }
    return sum;
}

int main(){

    int i=1;
    int *ptr = &i;            // declaring and initializing a pointer variable that is pointing towards the address of i
    cout << ptr << endl;      // prints the address of i -> (0x33f8e8)
    cout << *ptr << endl;     // prints the value at of the address stored in this pointer variable -> (i)
    int **D = &ptr;        // declaring and initializing a pointer variable that is pointing to the address of another pointer variable hence **(two stars) -> (0x33f8e4)
    cout << D << endl;     // prints the address of that another pointer variable that we stored while declaring -> (0x33f8e4)
    cout << *D << endl;    // prints the value of the memory address stored in this pointer variable -> (0x33f8e8)

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
    cout << *ptrAdd << endl;            // prints 2
    cout << ptrAdd << endl;             // prints the address of l
    *ptrAdd = *ptrAdd +  1;             // increases the number, note - *ptrAdd++ or (*ptrAdd)++ doesn't work
    cout << *ptrAdd << endl;            // prints the address of l
    ptrAdd = ptrAdd + 1;                // increases the address, note - ptrAdd++ or (ptrAdd)++ doesn't work
    cout << ptrAdd << endl;             // prints the increased address of l

    cout << endl;

// {imp concepts} arrays with pointers (works weirdly) [part 2 - pointers] 

    int arr[10] = {16,21,13,14,25,63,47,85,94,10};
    cout << arr << endl;                // prints the memory address of first location of the array we can verify with &arr[0]
    cout << *arr << endl;               // prints the value of the 0th location of array
    cout << *arr + 1 << endl;           // adds 1 to the value of 0th location of array
    cout << *arr + 2 << endl;           // adds 2 to the value of 0th location of array
    cout << *(arr+2) << endl;           // prints the value of (0+ith) memory location in the array
    
/*  with the last practice we got, arr[2] == *(arr+2) hence, arr[i] is calculated as *(arr + i). what happens if we 
    replace [arr] and [i] let's say we want the value of arr[i], is it equivalent to i[arr]? Yes, we can conclude that 
    by the formula we found lately. i[arr] == *(i + arr) == *(arr + i) == arr[i]. Let's verify it.
*/
    cout << arr[1] << endl;             // prints 21
    cout << 1[arr] << endl;             // prints 21

    int *p = &arr[0];
    cout << sizeof(arr) << endl;        // prints 40 i.e. (size of array * 4)
    cout << sizeof(p) << endl;      
    // This prints the size in bytes of the pointer p. The size of a pointer generally depends on the 
    // architecture of the system. On a 32-bit system, it's 4 bytes, and on a 64-bit system, it's usually 8 bytes.

    int arr1[5] = {1,2,3,54,5};
    cout << &arr1 << endl;              // prints the address of first location of array
    int *p1 = &arr1[0];                 // stores the address of first element of array
    cout << &p1 << endl;                // prints the address of pointer variable p1 that contains the memory address of a array element (&p1 would be different from &arr1)
    
    // cout << endl;
    // cout << p1 << endl;      
    // p1 = p1 + 1;             /*      perfectly valid     */
    // cout << p1 << endl;
    // cout << endl;

    int arr2[5] = {1,2,3,4,5};
    cout << arr2 << endl;
    cout << arr2+1 << endl;
/*  arr2 = arr2 + 1;  we can't do this while we can increase p1=p1+1 (even after it's a pointer variable) 
    cause in memory the first location of arr2 is mapped with it's name (arr2) so that the computer can understand which location
    to hit when we try to access or modify any value of the array, assume we increase the memory address of the first value of arr2,
    it won't happen cause the memory address after the memory address of arr2's first element is already occupied.
*/
    cout << endl;

// character arrays

    char ch[6] = "Aryan";   // for storing n characters in a character array it's size has to be n+1 (extra 1 for null character)
    char *c = &ch[0];
    cout << c << endl << endl;      // prints the whole string (prints everything unless it finds null character) cause the initial ch is an string not a character 

/*  Reason - In C++, when you use the << operator with cout to print a char* pointer, it treats the pointer as a C-style null-terminated string and prints the characters from the memory 
    location pointed to by the pointer until it encounters a null character ('\0'). This is known as "pointer dereferencing" and is a common behavior in C++ when working with strings.
*/

    // bad practice
    // char *c1 = "aryan";




// functions

    int var = 56;
    int *varPtr = &var;

    printPtr(varPtr);           // see above int main
    cout << *varPtr << endl;    // initial value of var
    updtPtr(varPtr);            // prints updated value of var
    cout << *varPtr << endl;    // prints updated value of var

    // working with arrays in pointers
    int arr3[5] = {1,2,3,4,5};
    int value = getSum(arr3,5); // to understand the size difference when we pass an array to a function. we can also pass getSum(arr3 + i,5) where i represents the starting value of the passing function
    cout << value << endl;

// Double pointer in detail

    int n = 5;                   
    int *ptr1 = &n;             // single pointer variable pointing towards the address of n 
    int **ptrD = &ptr1;         // double pointer variable pointing towards the address of pointer variable ptr1

    cout << n << endl;
    cout << ptr1 << endl;       // prints the memory address of n 
    ptr1 += 1;
    cout << "after : " 
    << ptr1 << endl;            // increases the value by 4 bits 
    cout << ptrD << endl;       // prints the memory address of a variable that already contains a memory address of another variable 
    cout << **ptrD << endl;     // prints the value of n cause memory address that recites in ptrD points to ptr1, and ptr1 has the address that points to n
    cout << *ptrD << endl;
    *ptrD += 1;     
    cout << "after " 
    << *ptrD << endl;           // increasing the value of ptr1 with reference
    
    int ***ptrT = &ptrD;
    cout << ptrT << endl;       // prints the memory address of a double pointer variable
    cout << ***ptrT << endl<< endl;    // prints the value of n, as it is a three pointer variable it jumps to the value three times... (from ptrT -> ptrD -> ptr1 -> n{5})

// when we update a pointer variable in a function it updates the value but we don't get the updated value outside that function, function xyz(*ptr){ ptr = ptr+1 }   this function updates the value of ptr but it doesn't change the value by reference if we want to change the value by reference we can use the * function xyz(*ptr){ *ptr = *ptr+1 } this function updates the value by reference, outsize the function we can find the updated value. 

/*   for MCQ's watch lecture 27 from 31:00    */
/*
    int num1 = 8;
    int *ptrr = &num1;
    cout << (*ptrr)++ << endl; 
    cout << num1 << endl << endl;
    // you might think that the output will be {9 9}, but the exact output will be {8 9} cause (*ptrr)++ first prints the value and then increments it. if we use *ptrr++ it doesn't work never increases the value.

    int arR[] = {11,12,13};
    int *r = arR;
    cout << *r[2] << endl;
    // *r[2] basically means *(r+2) i.e. tha address of 13

    int arr[] = {11,12,13,14};
    int *s = arr++;
    cout << *s << endl;
    // this should throw an error cause arr++ is trying to update the memory address of the first value of the array

    char arr[] = "charArrayHasDiffenetFunctioning";
    char *t = &arr[0];
    cout << t << endl;
    // this will simply print the full character array

    char arr[] = "charArrayHasDiffenetFunctioning";
    char *t = &arr[0];
    t = t + 2;
    cout << t << endl;
    // this should print the array from the second element
*/

    int First = 110;
    int *P = &First;
    int **Q = &P;
    int Second = (**Q)++ + 9;
    cout << First << " " << Second << endl;  
    // doubt = should print 111 and 120 but it prints 111 119  


}