#include<bits/stdc++.h>
using namespace std;

/*  Problem statement - return the sum of all elements of array
*/

// My approach
int sumCalc(int arr[], int size, int sum){
    if(size == 0){
        return sum;
    }
    sum = sum + arr[0];
    return sumCalc(arr+1, size-1, sum);
}

// final approach
int sumCalc2(int arr[], int size){
    if(size == 0){
        return 0;
    }if(size == 1){
        return arr[0];
    }

    int oldSum = sumCalc2(arr+1, size-1);
    int sum = arr[0] + oldSum;
    return sum;
} 

int main(){
    int sum=0;
    int arr[5] = {1,2,3,4,5};
    int ans = sumCalc(arr, 5, sum);
    cout << ans << endl;
    
}