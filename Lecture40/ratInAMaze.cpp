#include<bits/stdc++.h>
using namespace std;

bool safeSpot(int xax, int yax, vector<vector<int>> &arr, int n, vector<vector<int>> temp){
    return ((xax>=0 && xax < n) && (yax>=0 && yax < n) && (temp[xax][yax] == 0) && (arr[xax][yax]==1));
}

void solve(vector<vector<int>> &arr, int n, vector<string> &ans, int xax, int yax,
vector<vector<int>> temp, string path){
    // base case
    if((xax == n-1) && (yax == n-1)){
        ans.push_back(path);
        return;
    }

    // label visited
    temp[xax][yax] = 1;
    // down
    if(safeSpot(xax+1, yax, arr, n, temp)){
        path.push_back('D');
        solve(arr, n, ans, xax+1, yax, temp, path);
        path.pop_back();
    }
    // up
    if(safeSpot(xax-1, yax, arr, n, temp)){
        path.push_back('U');
        solve(arr, n, ans, xax-1, yax, temp, path);
        path.pop_back();
    }
    // right
    if(safeSpot(xax, yax+1, arr, n, temp)){
        path.push_back('R');
        solve(arr, n, ans, xax, yax+1, temp, path);
        path.pop_back();
    }
    // left
    if(safeSpot(xax, yax-1, arr, n, temp)){
        path.push_back('L');
        solve(arr, n, ans, xax, yax-1, temp, path);
        path.pop_back();
    }

    // removing label
    temp[xax][yax] = 0;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    vector<string> ans;
    int xax = 0, yax = 0;
    // if the movement is not possible
    if(arr[0][0] == 0){
        return ans;
    }

    vector<vector<int>> temp = arr;

    // temp = 0
    for(int i=0; i<n; i++){
      for (int j = 0; j < n; j++) {
        temp[i][j]=0;
      }
    }

    string path = "";
    solve(arr, n, ans, xax, yax, temp, path);
    sort(ans.begin(), ans.end());
    return ans;
}