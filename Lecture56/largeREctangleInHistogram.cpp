#include <bits/stdc++.h>
using namespace std;

/*  Problem Statement - Largest Rectangle in Histogram

    Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
    return the area of the largest rectangle in the histogram.

    Example 1:
    Input: heights = [2,1,5,6,2,3]
    Output: 10
    Explanation: The above is a histogram where width of each bar is 1.
    The largest rectangle is shown in the red area, which has an area = 10 units.

    Example 2:
    Input: heights = [2,4]
    Output: 4

    Link to Leetcode [https://leetcode.com/problems/largest-rectangle-in-histogram/description]

*/

// approach 1, time complexity O(n^2), simple bruteforce
int largestRectangleArea(vector<int> heights) {
    int breadth[heights.size()];
    for(int i = 0; i < heights.size(); i++) {
        breadth[i] = 1;
    }
    for(int i=0; i<heights.size(); i++){
        // loop for left
        for(int l=i-1; l>=0; l--){
            if(heights[l] >= heights[i]){
                breadth[i]++;
            }else{
                break;
            }
        }
        // loop for right side
        for(int r=i+1; r<heights.size(); r++){
            if(heights[r] >= heights[i]){
                breadth[i]++;
            }else{
                break;
            }
        }
    }

    int area[heights.size()];
    for(int i=0; i<sizeof(breadth)/sizeof(breadth[0]); i++){
        area[i] = breadth[i]*heights[i];
    }

    int ans = 0;
    for(int i=0; i<heights.size(); i++){
        if(area[i] > ans){
            ans = area[i];
        }
    }

    return ans;
}

vector<int> rightSmallerElement(vector<int> &arr, int n) {
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

vector<int> leftSmallerElement(vector<int> &arr, int n) {
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

int largestRectangleArea2(vector<int> heights) {

    int s = heights.size();

    vector<int> leftSmallerElements(s);
    vector<int> rightSmallerElements(s);

    leftSmallerElements = leftSmallerElement(heights, s);
    rightSmallerElements = rightSmallerElement(heights, s);

    int area = 0;

    for(int i=0; i<s; i++){  

        int length = heights[i];
        if(rightSmallerElements[i] == -1){
            rightSmallerElements[i] = s;
        }

        int breadth = rightSmallerElements[i] - leftSmallerElements[i] - 1;
        area = max(area, length*breadth);
    }

    return area;
}

int main(){
    vector<int> vect = {2,1,5,6,2,3};
    int result = largestRectangleArea2(vect);
    cout << result << endl;
}