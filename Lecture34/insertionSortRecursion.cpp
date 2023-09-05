#include<bits/stdc++.h>
using namespace std;

// insertion sort using recursion 

void insertion(int *arr, int size, int start){

    if(start >= size){
        return ;
    }
    
    int temp = arr[start];
    int i = start-1;

    for(  ; i>=0; i--){
        if(arr[i] > temp){
            arr[i+1] = arr[i];
        }else{
            break;
        }
    }

    arr[i+1] = temp;
    return insertion(arr, size, start+1);

}

int main(){
    int arr[5] = {54,32,847,5,2};
    insertion(arr, 5, 0);
    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}