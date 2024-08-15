#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n){
    stack<int> stk;
    vector<int> result;

    for(int i = n-1; i >= 0; i--){
        if(i == n-1){
            stk.push(arr[i]);
            result.push_back(-1);
            continue;
        }

        if(arr[i] > stk.top()){
            result.push_back(stk.top());
            stk.push(arr[i]);
        }else{
            stk.push(arr[i]);
            result.push_back(-1);
        }
    }

    for(int i = 0, j = result.size() - 1; i < j; i++, j--){
        int temp = result[i];
        result[i] = result[j]; 
        result[j] = temp;
    }
   
    return result;
};  

int main(){
    // 5 4 3 2 1
    vector<int> vect = {5, 4, 3, 2, 1};
    vector<int> result = nextSmallerElement(vect, 5);

    for (int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }

    cout << endl;
}