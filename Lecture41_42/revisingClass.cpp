#include<bits/stdc++.h>
#include "cantbeseen.cpp"
#include "personalFavorite.cpp"
using namespace std;

int main(){

    MyFavoriteMovie ddlj;

    cout << "size of static allocation : " << sizeof(ddlj) << endl;

    ddlj.setActor("SRK");
    ddlj.setActress("Kajol");

    // direct variable print 
    cout << "variable ddlj actor print: " << ddlj.actor << endl;
    cout << "variable ddlj actress print: " << ddlj.actress << endl;

    // function print
    cout << "printing ddlj actor fucntion: " << ddlj.getActor() << endl;
    cout << "printing ddlj actress fucntion: " << ddlj.getActress() << endl;


    cout << endl;

    MyFavoriteMovie *soty = new MyFavoriteMovie;
    cout << "size of dynamic allocation : " << sizeof(soty) << endl ;

    soty->setActor("actor2");    
    soty->setActress("actress2");

    husbandMaterialguys aadarsh;
    cout << "size of adarsh " << sizeof(aadarsh) << endl;

}