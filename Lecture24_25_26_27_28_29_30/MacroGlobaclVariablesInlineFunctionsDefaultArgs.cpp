#include <bits/stdc++.h>
using namespace std;
#define MASK 4

// Macro - a constant variable that doesn't take any space. working - before compilation it 
// changes all the values of macro name to it's variable then it compiles the program this 
// process doesn't takes any space; Definition of Macro -  a piece of code in a program that is 
// replaced by Macro.

// an example of macro

/*
    #define AREA(l, b) (l * b)
    int main(){
    	int length1 = 10, length2 = 5, area;
    	// Find the area using macros
    	area = AREA(length1, length2);
    	cout << "Area of rectangle is: " << area;
    }

    explanation - 
        The line #define AREA(l, b) (l * b) defines a macro named AREA that takes two 
    arguments l (length) and b (breadth) and calculates the area of a rectangle using the 
    formula (length * breadth). The macro definition uses parentheses to ensure proper 
    evaluation of the multiplication. 
        The line area = AREA(l1, l2); calculates the area of 
    a rectangle using the AREA macro. The l1 and l2 values are passed as arguments to the macro, 
    which performs the multiplication and returns the result. 

*/

// Global variable - a variable that can be accessed and modified from all the functions just create 
// it out any scopes (out of int main) it isn't very useful (security issues), reference variable is better.

// inline functions - working of inline functions is the same as macros, when we create a inline function 
// (must not contain more than 2-3 lines), the compiler before compiling replaces the function execution 
// with the statements inside that inline function. To create an inline function one just has to put 'inline' before function name.

// Default Args - in default args when we initialize a variable in the parenthesis so that if some value is given form function's arguments the value overrides the default value that we gave previously, and if we don't the value set in the parenthesis would be takes as default.

// An inline function
void inline inlineFunction(int x){
    cout << x << endl;
}

void defaultArgs(int x=1){
    cout << x << endl;
}

int main(){

    int x=2;
    cout << "the value of macro variable " << MASK << endl;
    inlineFunction(x);
    defaultArgs(5);     // prints 5
    defaultArgs();      // prints 1 (default argument)

}