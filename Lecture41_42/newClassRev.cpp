#include "cantbeseen.cpp"
#include <bits/stdc++.h>
using namespace std;


void memoryAllocation(){
    // static memory allocation
    husbandMaterialguys varun;
    
    cout << "sizeof varun (static) : " << sizeof(varun) << endl;
    varun.setValue(10);
    cout << "value rating of varun : " << varun.getValue() << endl;

    // dynamic memory allocation
    husbandMaterialguys *aryan = new husbandMaterialguys;
    cout << "sizeof aryan (dynamic MA) : " << sizeof(aryan) << endl;
    aryan->setValue(8);
    cout << "value rating of aryan :  " << aryan->getValue() << endl;
    cout << "morals rating of aryan :  " << aryan->getMorals() << endl;

}

void constructorCalling(){

    cout << endl << endl;

    learnConstructor aryan;
    learnConstructor aryanCallpara(10);
    cout << aryanCallpara.aryanValue << endl;

    learnConstructor *aryan2 = new learnConstructor();

    cout << endl << endl;

    // calling distructor from here (only because aryan2 was in dynamic memory) 
    delete aryan2;

}

void copyConstructor(){
    cout << endl << endl;

    husbandMaterialguys varun;
    varun.setValue(8);
    varun.setMorals(9);
    cout << "value rating of varun :  " << varun.getValue() << endl;
    cout << "morals rating of varun :  " << varun.getMorals() << endl;

    husbandMaterialguys copy(varun);
    cout << "copied value rating of varun :  " << copy.getValue() << endl;
    cout << "copied morals rating of varun :  " << copy.getMorals() << endl;

    cout << endl << endl;
}

// this is how we initialize a static variable, no need of object name cause it has no relation with object
int learningStaticKeyword::aryansIQ = 10;

int main(){

    // memoryAllocation();

    // constructorCalling();

    // copyConstructor();

    learningStaticKeyword aryan;
    // possible way to access static variable value but not recommended
    // cout << aryan.aryansIQ << endl;
    
    // recommended way for accessing static variable value
    cout << "printing aryansIQ: " << learningStaticKeyword::aryansIQ << endl;

    cout << "printing stsaticFunction : " << learningStaticKeyword::staticFunctionName() << endl;

}

