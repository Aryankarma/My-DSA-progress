#include<bits/stdc++.h>

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
// assigned to a student is minimum

// if the allocation of books is not possible then return -1


// example - 
/*

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

