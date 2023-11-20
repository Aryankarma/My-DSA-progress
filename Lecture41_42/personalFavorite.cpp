#include <bits/stdc++.h>
using namespace std;

class MyFavoriteMovie {

    public:
    string actor;
    string actress;

    void setActor(string name){
        actor = name;    
    }

    void setActress(string name){
        actress = name;    
    }

    string getActor(){
        return actor;
    }

    string getActress(){
        return actress;
    }
};