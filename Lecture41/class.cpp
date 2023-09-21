#include<bits/stdc++.h>
using namespace std;

// learning class in cpp [ public, private, protected ]

class YourFavoriteMovie{
    private:
    string Actor;
    string Actress;  
 
    public:
    int rating;
    char grade;

    string getActor(){
        return Actor;
    }

    string getActress(){
        return Actress;
    }

    int getSizeActor(){
        return sizeof(Actor);
    }

    int getSizeActress(){
        return sizeof(Actress);
    }

    void setActor(string name){
        Actor = name;
    }
    
    void setActress(string name){
        Actress = name;
    }
};


int main(){

    // static memory Allocation 
    YourFavoriteMovie soty;

    // dynamic memory allocation
    YourFavoriteMovie *Interstellar = new YourFavoriteMovie;

    cout << "Size of soty : " << sizeof(soty) << endl;
    cout << "Size of soty actor var : " << sizeof(soty.getSizeActor()) << endl;
    cout << "Size of soty actress var : " << sizeof(soty.getSizeActress()) << endl;
    cout << "Size of soty rating var : " << sizeof(soty.rating) << endl;
    cout << "Size of soty grade var : " << sizeof(soty.grade) << endl;
    cout << "Size of interstellar : " << sizeof(Interstellar) << endl;

    soty.rating = 7;
    soty.grade = 'A';

    // setting actor
    soty.setActor("varun");
    soty.setActress("Alia");

    cout << "Rating : " << soty.rating << endl;
    cout << "grade : " << soty.grade << endl;
    cout << "Actor : " << soty.getActor() << endl;
    cout << "Actress : " << soty.getActress() << endl;

    // setting actor interstellar
    (*Interstellar).rating = 9;
    (*Interstellar).grade = 'A';
    (*Interstellar).setActor("idk1");
    (*Interstellar).setActress("idk2");

    cout << "Rating : " << (*Interstellar).rating << endl;
    cout << "grade : " << (*Interstellar).grade << endl;
    cout << "Actor : " << (*Interstellar).getActor() << endl;
    cout << "Actress : " << (*Interstellar).getActress() << endl;
}