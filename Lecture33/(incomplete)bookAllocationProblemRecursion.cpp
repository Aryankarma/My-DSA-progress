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

/* example -

Input: ‘n’ = 4 ‘m’ = 2
‘arr’ = [12, 34, 67, 90]

Output: 113

Explanation: All possible ways to allocate the ‘4’ books to '2' students are:

12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is 
‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.

12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.

12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113', and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.

We are getting the minimum in the last case.
Hence answer is ‘113’.

*/

// Link to CodingNinjas [https://www.codingninjas.com/studio/problems/allocate-books_1090540]
// Link to LeetCode [their might be some similar questions to this search google]



// Main code

bool possibleSolution(int mid, int arr[], int sumOfPages, int studentCount, int n, int m, int i){
    cout << mid << endl;
    if(studentCount > n){
        return false;
    }
    if((studentCount == n) && ((i+1)==m)){
        return true;
    }
    if(sumOfPages < mid){
        // sumOfPages += mid;
        return possibleSolution(mid, arr, sumOfPages, studentCount, n, m, i+1);
    }else{
        // studentCount++;
        // sumOfPages = arr[i];
        return possibleSolution(mid, arr, sumOfPages + arr[i], studentCount+1, n, m, i+1);
    }
}

int binaryRecursion(int start, int sum, int m, int n, int arr[]){
    int mid = (start+sum)/2;
    int sumOfPages=0, studentCount=1, i=0;
    if(start>sum){
        return mid;
    }
    if(possibleSolution(mid, arr, sumOfPages, studentCount, n, m, i)){
        return binaryRecursion(start, mid-1, m, n, arr);
    }else{
        return binaryRecursion(mid+1, sum, m, n, arr);
    }
}

int main(){
    // int n=2, m=4;
    // int arr[m] = {10,20,30,40};
    // int start=0;
    // int sum=0;
    // for(int i=0; i<m; i++){
    //     sum = sum + arr[i];
    // }
    // int end = sum;
    // cout << binaryRecursion(start, sum, m, n, arr) << endl;
    cout << "working "<< endl;
}




/*   Converted the function from official solution of book allocation to recursive by AI    */ 


// int main(){
//     int n=2, m=4;
//     int arr[m] = {10,20,30,40};
//     int start=0;
//     int sum=0;
//     for(int i=0; i<m; i++){
//         sum = sum + arr[i];
//     }
//     int end = sum;
//     cout << binaryRecursion(start, sum, m, n, arr) << endl;
// }


// bool possibleSolution(int mid, int arr[], int sumOfPages, int studentCount, int n, int m, int i){
//     if(studentCount > n){
//         return false;
//     }
//     if((studentCount == n) && ((i+1)==m)){
//         return true;
//     }

//     if(sumOfPages < mid){
//         return possibleSolution(mid, arr, sumOfPages + arr[i], studentCount + 1, n, m, i+1);
//     }else{
//         return possibleSolution(mid, arr, sumOfPages, studentCount, n, m, i+1);
//     }
// }

// int binaryRecursion(int start, int sum, int m, int n, int arr[]){
//     int mid = (start+sum)/2;
//     int sumOfPages=0, studentCount=1, i=0;
//     if(start>sum){
//         return mid;
//     }
//     if(possibleSolution(mid, arr, sumOfPages, studentCount, n, m, i)){
//         return binaryRecursion(start, mid-1, m, n, arr);
//     }else{
//         return binaryRecursion(mid+1, sum, m, n, arr);
//     }
// }



/*   2nd solution   */


// bool possibleAnswer(vector<int>& arr, int n, int m, int mid){
//     int count=1;
//     int sumOfPage=0;
    
//     for(int i = 0; i<n; i++) {
//         if(sumOfPage + arr[i] <= mid) {
//             sumOfPage += arr[i];
//         }
//         else{
//             count++;
//             if(count > m || arr[i] > mid ) {
//             return false;
//             }
//             sumOfPage = arr[i];
//         }   
        
//     }
//     return true;
// }

// int findPagesRecursive(vector<int>& arr, int n, int m, int start, int end){
//     if(n<m){
//         return -1;
//     }

//     int mid = start + (end-start)/2;

//     if(possibleAnswer(arr, n, m, mid)){
//         return mid;
//     }
//     else if(start == end){
//         return -1;
//     }
//     else{
//         return findPagesRecursive(arr, n, m, start, mid-1);
//     }
// }

// int findPages(vector<int>& arr, int n, int m) {
//     return findPagesRecursive(arr, n, m, 0, arr[n-1]);
// }
