#include<bits/stdc++.h>
using namespace std;

// problem - add one

int main(){
    vector<int> digit;
    digit.push_back(9);
    int num = 0;
    for(int i=0; i< digit.size(); i++){
        num = num*10 + digit[i];
    }
    // adding one
    num = num+1;
    cout << "num : " << num << endl;
    
    // printing single digits from num
    int div = 1;
    if(digit.size()==1){
        div = div*10;
    }
    for(int i=1; i<digit.size(); i++){
        div = div*10;
    }

    cout << "div : " << div << endl;

    vector<int> nums;
    while(div>=1){
        nums.push_back(num/div);
        num = num-(div*(num/div));
        div=div/10;
    }

    for(int i=0; i< nums.size(); i++){
        cout << nums[i] << endl;
    }
}