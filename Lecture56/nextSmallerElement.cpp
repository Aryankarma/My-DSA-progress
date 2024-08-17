#include <bits/stdc++.h>
using namespace std;

// my approach - working ( a lil complicated :< )
vector<int> nextSmallerElement(vector<int> &arr, int n){
    stack<int> stk;
    vector<int> result;
    stk.push(-1);

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
            while (stk.top() >= arr[i]) {
                stk.pop();
            }
            result.push_back(stk.top());
            stk.push(arr[i]);
        }
    }

    for(int i = 0, j = result.size() - 1; i < j; i++, j--){
        int temp = result[i];
        result[i] = result[j]; 
        result[j] = temp;
    }
   
    return result;
};  

// original approach
vector<int> nextSmallerElement2(vector<int> &arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1; i>=0; i--) {
        int curr = arr[i];
        while (s.top() >= curr) {
          s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main(){
    vector<int> vect = {3,3,1,1};
    vector<int> result = nextSmallerElement2(vect, vect.size());

    for (int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }

    cout << endl;
}