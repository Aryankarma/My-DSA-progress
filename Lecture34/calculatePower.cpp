#include<bits/stdc++.h>
using namespace std;

// i/p - a=2, b=5 
// o/p - 2^5 = 32


// solution 1
int power(int a, int b, int multiply){
    if(b == 1){
        return a;
    }
    return power(a*multiply, b-1, multiply); 
}

// optimized approach (half number of iterations)
int power2(int a, int b){
    // base case
    if(b==0){
        return 1;
    }

    if(b%2 == 0){   // even
        return ((power2(a, b/2))*(power2(a, b/2)));
    }else{
        return (a*(power2(a, b/2))*(power2(a, b/2)));
    }
}

int main(){
    int a=4, b=4;
    cout << "Ans : " << power(a,b,a) << endl;
    cout << "Ans 2 : " << power2(a,b) << endl;
}