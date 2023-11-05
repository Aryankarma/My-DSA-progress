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

    cout << endl << endl;
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

int main(){

    // memoryAllocation();

    // constructorCalling();

    copyConstructor();

}