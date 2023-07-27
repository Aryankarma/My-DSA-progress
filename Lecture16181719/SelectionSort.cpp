#include<bits/stdc++.h>
using namespace std;


// Simple selection sort Program

int main(){ 
  int array[15] = {564,5,1542,564,987,987,12,48,84,9,56,1,12,5,48};
  int size = sizeof(array)/sizeof(array[0]);

  for(int i=0; i<size; i++){
    int minIndex = i;
    for(int j=i+1; j<size; j++){
        if(array[j] < array[minIndex])
            swap(array[j], array[minIndex]);
    }
  }
    for(int i=0; i<size; i++){
        cout << array[i] << " ";
    }
}