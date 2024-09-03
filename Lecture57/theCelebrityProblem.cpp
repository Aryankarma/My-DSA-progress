 /*  Problem Statement - The celebrity problem 
 
     A celebrity is a person who is known to all but does not know anyone at a party. A party is being
     organized by some people.  A square matrix mat is used to represent people at the party such that if an element 
     of row i and column j is set to 1 it means ith person knows jth person. You need to return the index 
     of the celebrity in the party, if the celebrity does not exist, return -1.

    Note: Follow 0-based indexing.

    Examples:

    Input: mat[][] = [[0 1 0],
                    [0 0 0], 
                    [0 1 0]]
    Output: 1
    Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity. 

    Link to GFG [https://www.geeksforgeeks.org/problems/the-celebrity-problem/1]
*/

//  solution - O(n)
bool knows(vector<vector<int> >& mat, int n, int a, int b){
    if(mat[a][b] == 1){
        return true;
    }else{
        return false;
    }
}

int celebrity(vector<vector<int> >& mat) {

    stack<int> stk;
    int n = mat.size();
    
    for(int i=0; i<n; i++){
        stk.push(i);
    }
    while(stk.size() > 1){
        int a = stk.top();
        stk.pop();
        int b = stk.top();
        stk.pop();
        
        if(knows(mat,n,a,b)){
            stk.push(b);
        }else{
            stk.push(a);
        }
    }
    
    int celebrity = stk.top();
    
    // lets make sure 
    
    bool rowCheck  = false;
    bool colCheck  = false;
    int  zeroCount = 0;
    int  oneCount  = 0;
    
    for(int i=0; i<n; i++){
        if(mat[celebrity][i] == 0){
            zeroCount++;
        }if(mat[i][celebrity] == 1){
            oneCount++;
        }
            
        if(zeroCount == n){
            rowCheck = true;
        }if(oneCount == n-1){
            colCheck = true;
        }
    }
    
    if(rowCheck && colCheck){
        return celebrity;
    }else{
        return -1;
    }
}
