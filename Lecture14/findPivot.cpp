#include<bits/stdc++.h>
using namespace std;

/*
this is different pivot than the previous one...


                              |...|->line1
array[8] =        {3, 4, 5, 6, 1, 2}
                  |..........| -> line 2


         -----------------------------------------
        .    .    .    .    .    .    .    .    .
         -----------------------------------------
        .    .    .    .   *o  line 2 .    .    .
         ----------------*-----line 2-------------
        .    .    .   *o    .  line 2 .    .    .
         -----------*----------line 2-------------
        .    .    *o    .    . line 2 .    .    .
         ------*---------------line 2-------------
        .   *o     .    .    . line 2 .    .    .
         ---------------------------------line 1--
        .    .    .    .    .    .    *o  line 1 .
         ---------------------------*-----line 1--
        .    .    .    .    pivot[*]  .   line 1 . 
         ---------------------------------line 1--
*/



int main(){
    int arr[8] = {14,18,20,21,28,1,2,3};
    int start=0, end=7;
    int mid = (start+end)/2;
    while(start<end){
        if(arr[mid] >= arr[0]){
            start = mid+1;
        }else{
            end = mid;
        }
        mid = (start+end)/2;
    }
    cout << start << endl;
}



