#include<bits/stdc++.h>
using namespace std;


// Simple selection sort Program

/*  in selection sort we use two pointers, the first one is set to the zeroth element of the array
    and the second one is set to one element ahead of the first element. the second element 
    tries to find the smallest number in the array while the first pointer is fixed at the 
    first element of the array, when it finally finds the smallest number in the array except 
    first element the loop breaks and it gets swapped with the first pointer, in the next step the first 
    pointer get's updated (hence the second pointer also gets updated according to the condition as it always 
    1 index ahead of first index) and the process goes on
*/

int main(){ 
  int array[15] = {564,5,1542,564,987,987,12,48,84,9,56,1,12,5,48};
  int size = sizeof(array)/sizeof(array[0]);

  // for(int i=0; i<size; i++){
  //   int minIndex = i;
  //   for(int j=i+1; j<size; j++){
  //       if(array[j] < array[minIndex])
  //           swap(array[j], array[minIndex]);
  //   }
  // }
  //   for(int i=0; i<size; i++){
  //       cout << array[i] << " ";
  //   }

  for(int i=0; i<size; i++){
    int minIndex = i;
    for(int j=i+1; j<size; j++){
        if(array[j] < array[minIndex])
        minIndex = j;
    }
    swap(array[i], array[minIndex]);
  }
    for(int i=0; i<size; i++){
        cout << array[i] << " ";
    }
}