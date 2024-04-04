#include<bits/stdc++.h>
using namespace std;

int findIndex(int arr[], int start, int end){
    int pivot = start, count=0;

    // counting elements smaller than pivot index
    for(int i=start+1; i<=end; i++){
        if(arr[i] <= arr[pivot]){
            count++;
        }
    }
    
    // cout << "Start, count " << start << " " << count << endl;
    // swap pivot to start+count index and update pivot
    
    pivot = start + count;
    swap(arr[pivot], arr[start]);
    int i=start, j=end;
    
    while(i<pivot && j>pivot){
        if(arr[i] < arr[pivot]){
            i++;
        }else if(arr[j] > arr[pivot]){
            j--;
        }else{
            swap(arr[i], arr[j]);
        }
    }

    return pivot;
}   

void quickSort(int *arr, int start, int end){
    // base case
    if(start>=end){
        return ;
    }

    int index=0;
    index = findIndex(arr, start, end);
    
    // left part of the array
    quickSort(arr, start, index-1);
    
    // right part of the array
    quickSort(arr, index+1, end);
}

int main(){
    int size = 6;
    int arr[size] = {6,3,5,4,1,2};
    
    quickSort(arr, 0, size-1);

    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}