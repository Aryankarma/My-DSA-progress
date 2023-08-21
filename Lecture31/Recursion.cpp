#include<bits/stdc++.h>
using namespace std;

// Recursion part 1 (5x4x3x2x1)

int power(int n){
    if(n==0)
        return 1;
    return 2*power(n-1);
}

int fact(int n){
    if(n == 0){
        return 1;
    }
    return n * fact(n-1);
}

void printCount(int n){
    if(n == 0){
        return ;
    }
    printCount(n-1); 
    cout << n << endl;
    // if the recursion calling is at the end (after processing), this is tail recursion. if recursive relation is before the processing then it is called head recursion. Note - try altering the recursive relation and processing statement, the output can change.
}

int main(){

    // factorial with recursion
    int n=7;
    int ans = fact(n);
    cout << ans << endl;

    // power of 2 with recursion
    int ans2 = power(n);
    cout << ans2 << endl;

    // printCount with recursion
    printCount(n);
}