#include <bits/stdc++.h>
using namespace std;

class learnConstructor{
    public:

    int aryanValue;

    // creating a basic constructor
    learnConstructor(){
        cout << "learnConstructor constructor called " << endl;
    }

    // creating a parameterized constructor (gets called when )
    learnConstructor(int input){
        this->aryanValue = input;
    }

    // THis is distructor that will be called in static constructor initialization not dynamic allocation
    ~learnConstructor(){
        cout << "this is being sent by distructor " << endl;
    }

};

class husbandMaterialguys{
    
    public:
    int value;
    int morals;
    int morals2;
    int morals3;

    int getValue(){
        return value;
    }   
    int getMorals(){
        return morals;
    }


    void setValue(int input){
        value = input;
    }
    void setMorals(int input){
        morals = input;
    }
    
};


class learningStaticKeyword{
    public:
    int nonStaticVariable;

    // how to declare static variables
    static int aryansIQ;    

    // creating static functions
    // 1. they can only access static variables/members
    // 2. no need to create object 
    // 3. "this" keyword doesn't work here cause this is completely related to the object it is used in while static functions are not object based  

    static int staticFunctionName(){
    // won't work
    // cout << this.aryansIQ << endl;  // this keyword
    // cout << nonStaticKeyword << endl; // not a static member

    return aryansIQ;
    }

};