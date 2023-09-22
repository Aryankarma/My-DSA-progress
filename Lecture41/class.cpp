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

class callDefCons{
    public:
    callDefCons(){
        cout << "The constructor has been called " << endl;
    }
};

/*  
    Here if we are creating a parameterized constructor, then the pre defined default constructor gets deleted and it 
    throws an error while evoking it with a new object, hence to use only a parameterized constructor it is necessary to 
    create an default constructor, only then we would be able to create an object of that particular class.

    class callParaCons{
        public:
        int health;
        callParaCons(int health){
            this -> health = health; 
        }
    };

*/
class callParaCons{
    public:
    int health;
    callParaCons(){
        // now this is a default constructor that helps us create a new object, without this we can't use this class with 
        // only an parameterized constructor 
    }
    callParaCons(int health){
        this -> health = health; 
    // here "this -> health" is pointing towards the health variable that has been initialized at line 63 (read about this 
    // keyword above initializing this object in the int main) and the "health" is the variable that we got as parameters in the constructor function.
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

    // calling via ->
    cout << "Rating : " << Interstellar->rating << endl;
    cout << "grade : " << Interstellar->grade << endl;
    cout << "Actor : " << Interstellar->getActor() << endl;
    cout << "Actress : " << Interstellar->getActress() << endl;

    /*
        Understanding Constructor - 
        Constructor gets called when we create a new object, they invoke at the time of object creating, they don't 
        have any input type, they don't have any return type. here when we do "YourFavoriteMovie soty" the bts working 
        is that it simply calls soty.YourFavoriteMovie() this is called default constructor...
    */

    // calling a {default constructor} with a new class
    // dynamically setting up a object will work the same as statically setting up the object;
    cout << "Before calling constructor : " << endl;
    callDefCons call;
    cout << "End of calling a default constructor " << endl;

    // (their exists an already build constructor when we create a class), so when we create such constructors, 
    // this constructor overrides the old default constructor that was pre build, If we create only a parameterized 
    // constructor even then we can see that the pre defined constructor gets deleted, thereafter if we are trying to create an object 
    // with the same class, it would be impossible cause we have already created an parameterized constructor that removed 
    // our pre defined default constructor. 



    // {PARAMETERIZED CONSTRUCTOR} that has a parameter 
    // this keyword - this is a pointer variable that has the address of the object the keyword lies in, so 
    // technically, if we are using keyword in an object that 'this' keyword will be pointing to that particular 
    // object it is being used in. if we try printing the value of this keyword in an object and then the 
    // address of that particular object, both of those values are gonna be same.

    callParaCons calllingWithThis(16);
    cout << calllingWithThis.health << endl;

/*
    Here pops a question - If we can do the same thing using setters and parameterized construction when and why to use each?
    
    Parameterized Constructors:
    Parameterized constructors are useful when you want to ensure that an object is properly initialized upon its creation. They allow 
    you to set the initial values of member variables at the moment an object is instantiated. This is particularly helpful when you have 
    mandatory data that every object of the class should have.
    
    Setters (Member Functions):
    Setters are useful when you want to allow for the modification of member variables after the object has been created. They provide a way to 
    change the state of an object incrementally or under specific conditions. You might use setters when some member variables are optional or 
    when you want to enforce some rules or constraints during the setting of values.
   
*/

    // {COPY CONSTRUCTOR} an constructor that helps copy all values from an object of some class to another object of that particular class.  
    // syntax - just send the object that you want to copy in the parenthesis of another object; 

    callParaCons copyCalllingWithThis(calllingWithThis);
    cout << "Printing the copied value : " << copyCalllingWithThis.health << endl;



}