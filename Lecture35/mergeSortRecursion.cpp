#include<bits/stdc++.h>
using namespace std;

// merge sort using recursion

/*  Here are some other sorting algorithms and their time complexities:
    Merge sort: O(n log n)
    Heapsort: O(n log n)
    Counting sort: O(n + k), where k is the range of the input values
    Radix sort: O(kn), where k is the number of digits in the input values

working -
    
    Merge function
    1. calculate mid
    2. calculate length of left and right side sub arrays
    3. create 2 temporary sub arrays in the heap with lengths that we calculated     
    4. copy the values from the main array to the new arrays 
    5. merge both of this new array back into main array
    6. deallocate the memory

    MergeSort function
    1. create base case that checks if s >= e i.e. if the array is already sorted or has 1 or 0 elements
    2. calculate mid and recursively call left and right halves of the array with the same function
    3. call merge function 

    Time complexity - O(n*log(n));
*/

void merge(int *arr, int start, int end){
    int mid = (start+end)/2;
    
    // calculating length of new sub arrays
    int len1 = mid-start+1;
    int len2 = end - mid;

    // creating sub arrays in the heap
    int *first = new int[len1];
    int *second = new int[len2];

    // copying the values
    int mainIndex = start;
    for(int i=0; i<len1; i++){
        first[i] = arr[mainIndex++];
    }
    mainIndex = mid + 1;
    for(int i=0; i<len2; i++){
        second[i] = arr[mainIndex++];
    }

    // creating indexes for
    int index1=0, index2=0;
    mainIndex=start;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainIndex++] = first[index1++];
        }else{
            arr[mainIndex++] = second[index2++];
        }
    }

    while(index1 < len1){
        arr[mainIndex++] = first[index1++];
    }

    while(index2 < len2){
        arr[mainIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int *arr, int start, int end){
    if(start >= end){
        return ;
    }
    int mid = (start+end)/2;

    mergeSort(arr, 0, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, end);
}

int main(){
    int size = 10;
    int arr[size] = {1,5,565,87,87,12,12,32,4,47};
    mergeSort(arr, 0, size-1);
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
