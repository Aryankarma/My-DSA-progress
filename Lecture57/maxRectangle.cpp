#include <bits/stdc++.h>
using namespace std;

/*  Problem Statement - Max Rectangle

    Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.
    Example 1:

    Input:
    n = 4, m = 4
    M[][] = {{0 1 1 0},
            {1 1 1 1},
            {1 1 1 1},
            {1 1 0 0}}

    Output: 8
    Explanation: For the above test case the matrix will look like

    0 1 1 0
    1 1 1 1
    1 1 1 1
    1 1 0 0

    the max size rectangle is 

    1 1 1 1
    1 1 1 1
    and area is 4 *2 = 8.

    Link to GFG [https://geeksforgeeks.org/problems/max-rectangle/1]
*/

     
// we are storing the indexes here and not the actual value
vector<int> rightSmallerElement(int *arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1; i>=0; i--) {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

// we are storing the indexes here and not the actual value
vector<int> leftSmallerElement(int *arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=0; i<n; i++) {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

// approach 2, time complexity O(n), optimized approach
int largestRectangleArea(int *heights, int s ) {

    vector<int> leftSmallerElements = leftSmallerElement(heights, s);
    vector<int> rightSmallerElements = rightSmallerElement(heights, s);

    int area = 0;

    for(int i=0; i<s; i++){  

        int length = heights[i];
        if(rightSmallerElements[i] == -1){
            rightSmallerElements[i] = s;
        }

        int breadth = rightSmallerElements[i] - leftSmallerElements[i] - 1;
        area = max(area, length * breadth);
    }

    return area;
}


int maxArea(int M[4][4], int n, int m) {

    // Compute area for first row
    int area = largestRectangleArea(M[0], m);

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {

            // Row update: by adding the previous row's value
            if(M[i][j] != 0)
                M[i][j] += M[i-1][j];
            else
                M[i][j] = 0;
        }

        // Entire row is updated now
        area = max(area, largestRectangleArea(M[i], m));
    }
    return area;
}

int main(){
    int array[4][4] =  
        {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}};

    int row = 4;
    int col = 4;
    int ans = maxArea(array[row][col], row, col);

    cout << ans << endl;
}