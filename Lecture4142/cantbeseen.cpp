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