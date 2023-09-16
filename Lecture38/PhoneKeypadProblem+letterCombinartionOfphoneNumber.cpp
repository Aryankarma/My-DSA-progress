#include<bits/stdc++.h>
using namespace std;

/*  17. Letter Combinations of a Phone Number

    Given a string containing digits from 2-9 inclusive, return all possible letter 
    combinations that the number could represent. Return the answer in any order.

    A mapping of digits to letters (just like on the telephone buttons) is given below. 
    Note that 1 does not map to any letters.

      1      2       3   
    (none) (abc)   (def)
    
      4      5       6
    (ghi)  (jkl)   (mno)
    
      7      8       9
    (pqrs) (tuv)  (wxyz)
    
    Example 1:
    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

    Example 2:
    Input: digits = ""
    Output: []

    Example 3:
    Input: digits = "2"
    Output: ["a","b","c"]

    Constraints:
    0 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9']

*/

class Solution{
private:
    void solve(string digits, string inner, vector<string> &outer, string map[], int index){
        // base case
        if(index >= digits.length()){
            outer.push_back(inner);
            return;
        }
        int number = digits[index] - '0';
        string value = map[number];      
        for(int i=0; i<value.length(); i++){
            inner.push_back(value[i]);
            solve(digits,inner,outer,map,index+1);
            inner.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        string inner = "";
        vector<string> outer;
        if(digits.length()==0){
            return outer;
        }
        int index=0;
        string mappletter[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,inner,outer,mappletter,index);
        return outer;
    }
};


// vs code solution:

#include <bits/stdc++.h>
using namespace std;

void solve(string digits, string inner, vector<string> &outer, string map[], int index){
    // base case
    if (index >= digits.length()){
        outer.push_back(inner);
        return;
    }
    cout << "index : " << index << endl;
    int number = digits[index] - '0';
    cout << "number : " << number << endl;
    string value = map[number];
    cout << "value :  " << value << endl;
    for (int i = 0; i < value.length(); i++){
        inner.push_back(value[i]);
        cout << "inner :  " << inner << endl;
        solve(digits, inner, outer, map, index + 1);
        cout << "calling after recursive & pop back :  " << endl;
        cout << inner.back() << endl;
        inner.pop_back();
    }
}

vector<string> letterCombinations(string digits){
    string inner = "";
    vector<string> outer;
    if (digits.length() == 0){
        return outer;
    }
    int index = 0;
    string mappletter[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, inner, outer, mappletter, index);
    return outer;
}

int main(){
    vector<string> save = letterCombinations("23");
    for(int i=0; i<save.size(); i++){
        cout << save[i] << " "; 
    }
}