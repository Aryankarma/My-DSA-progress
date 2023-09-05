#include<bits/stdc++.h>
using namespace std;

// This technique is adaptable and stable -

/*  Adaptable means that an algorithm that works on the go, which can output half of the 
    progress if we stop somewhere in between the process.  
    Stable means that it doesn't process unnecessary things like swapping same elements 
    in the array, this instability can be found in quick sort, heap sort and selection sort.
*/  
int main(){
    int array[10] = {4,564,5,5,12,32,564,54,0,12};
    int size = sizeof(array)/sizeof(array[0]);
    for(int i=0; i<size; i++){
        int temp = array[i];
        int j= i-1;
        for( ; j>=0; j--){        
             if(array[j] > temp) {
                // aligning the order
                array[j+1] = array[j];
            }
            else { 
                break;
            }
        }
    array[j+1] = temp;
    }
    for(int i=0; i<size; i++){
        cout << array[i] << " ";
    }
}