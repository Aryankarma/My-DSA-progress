#include<bits/stdc++.h>
using namespace std;

// inversion-count-in-array-using-merge-sort
  
/*  Inversion Count for an array indicates – how far (or close) the array is from being sorted. If the 
    array is already sorted, then the inversion count is 0, but if the array is sorted in reverse order, the 
    inversion count is the maximum. 
    Given an array arr[]. The task is to find the inversion count of arr[]. Where two elements arr[i] and 
    arr[j] form an inversion if a[i] > a[j] and i < j.

    Examples:
    Input: arr[] = {8, 4, 2, 1}
    Output: 6
    Explanation: Given array has six inversions: (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).

    Input: arr[] = {1, 20, 6, 4, 5}
    Output: 5
    Explanation: Given array has five inversions: (20, 6), (20, 4), (20, 5), (6, 4), (6, 5). 
*/



void merge(int *arr, int start, int end, int &count){
    int mid = (start+end)/2;
    
    // calculating length of new sub arrays
    int len1 = mid-start+1;
    int len2 = end - mid;

    // creating sub arrays in the heap
    int *first = new int[len1];
    int *second = new int[len2];

    // copying the values
    int mainIndex = start;
    for(int i=0; i<len1; i++){
        first[i] = arr[mainIndex++];
    }
    mainIndex = mid + 1;
    for(int i=0; i<len2; i++){
        second[i] = arr[mainIndex++];
    }

    // creating indexes for
    int index1=0, index2=0;
    mainIndex=start;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainIndex++] = first[index1++];
        }else{
            arr[mainIndex++] = second[index2++];
            count = count + len1 - index1;
        }
    }

    while(index1 < len1){
        arr[mainIndex++] = first[index1++];
    }

    while(index2 < len2){
        arr[mainIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int *arr, int start, int end, int &count){
    if(start >= end){
        return ;
    }
    int mid = (start+end)/2;
    mergeSort(arr, start, mid, count);
    mergeSort(arr, mid+1, end, count);
    merge(arr, start, end, count);
}

int main(){
    int size = 4;
    int arr[size] = {3, 2, 1, 0};
    int count=0;
    mergeSort(arr, 0, size-1, count);
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "count is: " << count << endl;
}


// #include <bits/stdc++.h>
// using namespace std;

// int _mergeSort(int arr[], int temp[], int left, int right);
// int merge(int arr[], int temp[], int left, int mid,
// 		int right);

// // This function sorts the
// // input array and returns the
// // number of inversions in the array
// int mergeSort(int arr[], int array_size){
// 	int temp[array_size];
// 	return _mergeSort(arr, temp, 0, array_size - 1);
// }

// // An auxiliary recursive function
// // that sorts the input array and
// // returns the number of inversions in the array.
// int _mergeSort(int arr[], int temp[], int left, int right)
// {
// 	int mid, inv_count = 0;
// 	if (right > left) {
// 		// Divide the array into two parts and
// 		// call _mergeSortAndCountInv()
// 		// for each of the parts
// 		mid = (right + left) / 2;

// 		// Inversion count will be sum of
// 		// inversions in left-part, right-part
// 		// and number of inversions in merging
// 		inv_count += _mergeSort(arr, temp, left, mid);
// 		inv_count += _mergeSort(arr, temp, mid + 1, right);

// 		// Merge the two parts
// 		inv_count += merge(arr, temp, left, mid + 1, right);
// 	}
// 	return inv_count;
// }

// // This function merges two sorted arrays
// // and returns inversion count in the arrays.
// int merge(int arr[], int temp[], int left, int mid,
// 		int right)
// {
// 	int i, j, k;
// 	int inv_count = 0;

// 	i = left;
// 	j = mid;
// 	k = left;
// 	while ((i <= mid - 1) && (j <= right)) {
// 		if (arr[i] <= arr[j]) {
// 			temp[k++] = arr[i++];
// 		}
// 		else {
// 			temp[k++] = arr[j++];

// 			// this is tricky -- see above
// 			// explanation/diagram for merge()
// 			inv_count = inv_count + (mid - i);
// 		}
// 	}

// 	// Copy the remaining elements of left subarray
// 	// (if there are any) to temp
// 	while (i <= mid - 1)
// 		temp[k++] = arr[i++];

// 	// Copy the remaining elements of right subarray
// 	// (if there are any) to temp
// 	while (j <= right)
// 		temp[k++] = arr[j++];

// 	// Copy back the merged elements to original array
// 	for (i = left; i <= right; i++)
// 		arr[i] = temp[i];

// 	return inv_count;
// }

// // Driver code
// int main(){
// 	int arr[] = { 1, 20, 6, 4, 5 };
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	int ans = mergeSort(arr, n);
// 	cout << " Number of inversions are " << ans;
// 	return 0;
// }