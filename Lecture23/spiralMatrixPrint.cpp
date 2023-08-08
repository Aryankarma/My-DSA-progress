#include<bits/stdc++.h>
using namespace std;

/*  Problem statement - 54. Spiral Matrix

    Given an m x n matrix, return all elements of the matrix in spiral order.

    Example 1:
    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]

    1 -> 2 -> 3 
              v  
    4 -> 5    6
    ^         v
    7 <- 8 <- 9

    output - [1,2,3,6,9,8,7,4,5]


    Example 2:
    Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]

    1  ->  2  ->  3  ->  4
                         v
    5  ->  6  ->   7     8
    ^              v     v
    9      10 <-  11    12
    ^                    v
    13 <-  14  <- 15 <- 16

    Output: [1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10]

*/

// Link to LeetCode [https://leetcode.com/problems/spiral-matrix/]


// Leetcode solution
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int Rfinal = matrix.size()-1;
        int Cfinal = matrix[0].size()-1;
        int Rinitial=0, Cinitial=0;
        int prints=0;
        int total = (Rfinal+1)*(Cfinal+1);
        vector<int> ans;

        while(prints<total){
            // first row
            for(int col=Cinitial; col<=Cfinal && prints<total; col++){
                ans.push_back(matrix[Rinitial][col]);
                prints++;
            }Rinitial++;

            // last col
            for(int row=Rinitial; row<=Rfinal && prints<total; row++){
                ans.push_back(matrix[row][Cfinal]);
                prints++;
            }Cfinal--;

            // last row
            for(int col=Cfinal; col>=Cinitial && prints<total;col--){   
                ans.push_back(matrix[Rfinal][col]);
                prints++;
            }Rfinal--;

            // first Col
            for(int row=Rfinal; row>=Rinitial && prints<total; row--){
                ans.push_back(matrix[row][Cinitial]);
                prints++;
            }Cinitial++;
        }
    return ans;
    }
};


// VS code solution

/* commenting till last

int main(){
    int arr[4][4] = {{1,2,3,4,},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int Rinitial=0,Rfinal=4-1,Cinitial=0,Cfinal=4-1,prints=0;
    vector<int> ans;
    int size1=Rfinal, size2=Cfinal;

    // for(int i=0; i<ans.size(); i++){
    //     cout << ans.at(i) << " ";
    // }
    int total = ((size1+1)*(size2+1));

    while(prints < total){

        // // printingFirstLine
        // for(int row=0; row<Rfinal-1 && prints < total; row++){
        //     ans.push_back(arr[row][Cinitial]);
        //     prints++;
        //     cout << "loop running 1" << endl;
        //     cout << "value of prints : " << prints <<endl;
        // }
        //  Cinitial++;
        for(int col=Cinitial; col<=Cfinal && prints < total; col++){
            ans.push_back(arr[Rinitial][col]);
            prints++;
            cout << "loop running 1" << endl;
            cout << "value of prints : " << prints <<endl;
        }
        Rinitial++;
        // // PrintsingSecondLine
        // for(int col=0; col<Cfinal-1 && prints < total; col++){
        //     ans.push_back(arr[Rfinal][col]);
        //     prints++;
        //     cout << "loop running 2" << endl;
        //     cout << "value of prints : " << prints <<endl;
        // }
        // Rfinal--;
        for(int row=Rinitial; row<=Rfinal && prints < total; row++){
            ans.push_back(arr[row][Cfinal]);
            prints++;
            cout << "loop running 2" << endl;
            cout << "value of prints : " << prints <<endl;
        }
        Cfinal--;
        // // printsingThirdLine
        // for(int row=Rfinal; row>Rinitial-1 && prints < total; row--){
        //     ans.push_back(arr[row][Cfinal]);
        //     prints++;
        //     cout << "loop running 3" << endl;
        //     cout << "value of prints : " << prints <<endl;
        // }
        // Cfinal--;
        for(int col=Cfinal; col>=Cinitial && prints < total; col--){
            ans.push_back(arr[Rfinal][col]);
            prints++;
            cout << "loop running 3" << endl;
            cout << "value of prints : " << prints <<endl;
        }
        Rfinal--;
        // // printsingFourthLine
        // for(int col=Cfinal; col>Cinitial-1 && prints < total; col--){
        //     ans.push_back(arr[Rinitial][col]);
        //     prints++;
        //     cout << "loop running 4" << endl;
        //     cout << "value of prints : " << prints <<endl;
        // }
        // Rinitial++;
        for(int row=Rfinal; row >= Rinitial && prints < total; row--){
            ans.push_back(arr[row][Cinitial]);
            prints++;
            cout << "loop running 4" << endl;
            cout << "value of prints : " << prints <<endl;
        }
        Cinitial++;
    }

    for(int i=0; i<ans.size(); i++){
        cout << ans.at(i) << " ";
    }
}


comment ends    */