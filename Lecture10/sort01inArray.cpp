#include<iostream>
using namespace std;

/*
    in a given array of only 0 and 1 elements, sort it as all the 0's take left and all 
    1's take right...

    no leetcode/codingninjas
*/

void sort01(int array[], int size){
    int i=0, j=size-1;
    while(i<j){
        if(array[i] == 0){
            i++;
        }else if(array[j] == 1){
            j--;
        }else if(array[i] == 1 && array[j] == 0){
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }

    for(int i=0; i<size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){
    int array[11] = {1,1,0,0,1,0,0,0,0,0,1};
    sort01(array, 11);
}