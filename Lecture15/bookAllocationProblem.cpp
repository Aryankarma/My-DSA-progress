#include<bits/stdc++.h>
using namespace std;

// [56,2,34,55,32]

// book 0 - 56 pages        
// book 1 - 2 pages         
// book 2 - 34 pages        
// book 3 - 55 pages        
// book 4 - 32 pages        

// now we have "m" number of students our task is to allocate books to all the students such that...

/*  1. each student gets atleast one book.
    2. each book should be allocated to only one student.
    3. Book allocation should be in a contiguous manner.
*/

// allocate the books to "m" students such that the maximum number of pages
//  assigned to a student is minimum

// if the allocation of books is not possible then return -1

/*
example -

Input: ‘n’ = 4 ‘m’ = 2
‘arr’ = [12, 34, 67, 90]

Output: 113

Explanation: All possible ways to allocate the ‘4’ books to '2' students are:

12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is 
‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.

12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student 
two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.

12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, 
and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.

We are getting the minimum in the last case.
Hence answer is ‘113’.

*/


// Link to CodingNinjas [https://www.codingninjas.com/studio/problems/allocate-books_1090540]
// Link to LeetCode [their might be some similar questions to this search google]




bool possibleAnswer(vector<int>& arr, int n, int m, int mid){
    int count=1;
    int sumOfPage=0;
    
    for(int i = 0; i<n; i++) {
        if(sumOfPage + arr[i] <= mid) {
            sumOfPage += arr[i];
        }
        else{
            count++;
            if(count > m || arr[i] > mid ) {
            return false;
        }
            sumOfPage = arr[i];
        }   
        
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    int start=0;
    int sum=0;

    for(int i=0; i<n; i++){
        sum = sum + arr[i];
    }   
    int end = sum;
    int ans = -1;
    int mid = start + (end-start)/2;

    while(start<=end){
        if(n<m){
            return -1;
        }
        if(possibleAnswer(arr, n, m, mid)){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}