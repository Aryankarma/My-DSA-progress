#include<bits/stdc++.h>
using namespace std;

/*  Problem statement - linear search using recursion
*/

bool search(int arr[], int size, int key){
//    base case
    // if(size == 1){
    //     if(arr[0] != key){
    //         return false;
    //     }
    // }
    if(size == 0){
        return false;
    }

    if(arr[0] == key){
        return true;
    }else{
        return search(arr+1, size-1, key);
    }
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int ans = search(arr, 5, 4);
    cout << ans << endl;
}