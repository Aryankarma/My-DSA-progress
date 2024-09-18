#include <bits/stdc++.h> 
using namespace std;
/*  Problem Statement 

    Kevin has recently learned the concept of “STACK”. During his practice, he got stuck in a problem where he
    has to reverse a string ‘S’ using a stack. So, he appoints you to help him in reversing the string ‘S’. 
    All you have to do is to find the reversed string.

    Please reverse the string using a stack so that Kevin gets to know where he is getting wrong after 
    seeing your solution. It is guaranteed that strings will only be composed of English alphabets.

*/

// Link to codingNinjas [https://www.naukri.com/code360/problems/kevin-s-stack-problem_1169465?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM]

string kevinStackProblem(string &s){
	stack<char> stk;
	string result;

	for(int i=0; i<s.size(); i++){
		stk.push(s[i]);
	}

	while(!stk.empty()){
		result = result + stk.top();
		stk.pop();
	}

	return result;
}

int main(){
    string main = "aryan";
    string result = kevinStackProblem(main);
    cout << result << endl;
}