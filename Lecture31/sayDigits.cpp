#include<bits/stdc++.h>
using namespace std;

// input - 143, output - one four three (attempt with recursion)

void printDigit(int n, string arr[]){
    // base case
    if(n == 0){
        return ;
    }
    int digit;
    digit = n%10;
    n=n/10;
    printDigit(n, arr);
    cout << arr[digit] << " " ;
}

int main(){
    string arr[10] = {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n;
    cin >> n;
    printDigit(n ,arr);
    cout << endl;
}