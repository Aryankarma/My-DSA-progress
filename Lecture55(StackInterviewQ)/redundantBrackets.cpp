#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "a+b+(c+(d*))";

    // // wrote this algo but..! this algo can't work on the last test case... 
    // int counter = 0;
    // map<int, bool> mapping;

    // for (int i = 0; i < s.length(); i++){
    //     if (s[i] == '('){
    //         counter++;
    //         mapping[counter] = false;
    //     }else if (s[i] == ')'){
    //         counter--;
    //     }else if (s[i] == '/' || s[i] == '*' || s[i] == '-' || s[i] == '+'){
    //         if(counter != 0){
    //             mapping[counter] = true;
    //         }
    //     }
    // }

    // for(int i=1; i<= mapping.size(); i++){
    //     if(mapping[i] == false){
    //         cout << "Yes" << endl;
    //         return 0;
    //     }
    // }

    // cout << "No" << endl;
    // return 0;

    // approach 2 (using stack)
    stack<char> stk;
    for (int i = 0; i < s.length(); i++){
        char ch = s[i];

        // if char is open bracket or operators
        if (ch == '(' || ch == '/' || ch == '*' || ch == '-' || ch == '+'){
            stk.push(ch);
        }else{  
            // if close the i ptr reaches a close bracket
            // we'll set the isRed bool to true and will set it to false if
            // their are any operators in bw the opening and closing brackets
            if (ch == ')'){
                bool isRed = true;

                while(stk.top() != '('){
                    char top = stk.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/'){
                        isRed = false;
                    } 
                    stk.pop();
                }
 
                if (isRed){ 
                    return true;
                }

                stk.pop();
            }
        }
    }
    return false;
}