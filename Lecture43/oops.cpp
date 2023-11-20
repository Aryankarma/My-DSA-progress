#include<bits/stdc++.h>
#include<string>
using namespace std;

// Encapsulation - information/data hiding
/* Applications - 
    Data hiding (better security)
    we can also mark our class "read only"
    code reusability
*/

class learningEncapsulation {
    // setting up private data
    private:    
    int age;
    int name;

    public:
    int getAge(){
        return age;
    }
};

// Inheritance - inheriting (coping the properties of parent class)
/* When a child class inherits parent class, what it does is simply copies all the properties of the parent class 
   When we inherit as public properties, all the properties in the child class will be public & private 
   properties of parent class will be inaccessible, when we inherit as private properties, all the properties in 
   the child will be private even the public will become private in the child class (access them with getters)
   when we inherit as protected properties, all the properties in the child will be protected even the public 
   will become protected in the child class (access them with getters)

   When we try to access the private variables of the parent class via child class it says it's inaccessible, 
   cause they are private they can only be accessible in the class itself

   Note: Private data variables of any parent class can not be inherited
*/

class parentClassInheritance_Human{

    private:
    
    // this variable can never be accessed by a child class (no matter the mode in which the class in getting inherited) 
    int privateMember; 
    
    public: 
    int avgAge;
    int avgWeight;
    int avgheight;
};

// inheriting Human properties as public
class childClassInheritance_Male: public parentClassInheritance_Human {
    public:
    int childVariable;
};

// inheriting Human properties as private
class childClassInheritance_Female: private parentClassInheritance_Human {
    public:
    int childVariable;

    int getAge(){
        return avgAge;
    }
};

// creating the protected child class that converts all the public properties of the parent class to protected hence, 
// we are accessing them with getters
class childClassInheritance_FemaleProtected: protected parentClassInheritance_Human{
    public:

    // to access avgAge (now protected member)
    int getAge(){
        return this->avgAge;
    } 
};

/*  Types of inheritance

    Single
    Multi-level
    Multiple
    Hierarchical
    Hybrid
*/

// Single inheritance - what we did till now

// Multi level inheritance - class C (child class of B) inheriting class B (parent class of C & child class of A) 
// which is inheriting class A (parent class of B) - multi level inheritance

// Multiple inheritance - a single class C inheriting 2 or more classes e.g. A & B - class C (child of both A & B) inheriting class A and B
// example of multiple inheritance

class PetrolCars {
    public:
    void printPetrol(){
        cout << "This are petrol cars " << endl;
    }
};

class ElectricCars {
    public:
    void printEv(){
        cout << "This are electric cars " << endl;
    }
};

class HybridCars: public PetrolCars, public ElectricCars {
    
};

/*  Hierarchical inheritance - one class serves as parent class for more than one class that itself are parent classes of another classes


        A(main parent class) 
      /   \
     B     C
    / \   / \
   D   E F   G

Note: In this inheritance we can not inherit the properties of class B in class C cause they are not interconnected

*/

// Hybrid inheritance - combination of more than one type of inheritance
/*
      A  D
     / \ |
    B    C

*/



// Inheritance Ambiguity - if we have 2 classes A & B with the same function name, and a new class C that inherits 
// both of those classes, then calling that function would throw an error 

class ambiguityClass1 {
    public:
    void abc(){
        cout << "console from ambiguity class 1" << endl;
    }
};

class ambiguityClass2 {
    public:
    void abc(){
        cout << "console from ambiguity class 2" << endl;
    }
};

class ambiguityClass3: public ambiguityClass1, public ambiguityClass2{ 
    // check main function 
};




// Polymorphism - Polymorphism is a imp concept that allows us to perform a single action in different ways (poly - many, morphs - forms)
// Types of polymorphism - Compile time(static polymorphism) & Run time(dynamic polymorphism)

// Compile time polymorphism - 2 ways -> Function overloading and operator overloading

// Function overloading -
// When there are multiple functions in a class with the same name but different parameters, these functions 
// are overloaded. The main advantage of function overloading is that it increases the program’s readability. 
// Functions can be overloaded by using different numbers of arguments or by using different types of arguments.
// function overloading can not be achieved by changing the return types (int, char, void)

class functionOverloading {
    public:
    // functions of same name - check main function to see initialization
    void printHello(){
        cout << "Hello from 1st function" << endl;
    }
    // adding a parameter (different function from 1st one)
    void printHello(int num){
        cout << "Hello from 2nd function" << endl;
    }
    void printHello(int num1, int num2){
        cout << "Hello from 3rd function" << endl;
    }

    // if we try to make a function different by changing the return type (function overload throws error = "cannot overload functions distinguished by return type alone")
    // int printHello(int num1){
    //     cout << "This function won't work" << endl;
    // }
};


// Operator Overloading - Changing the actual working of an operator is operator overloading 
// operators like: + - * / && || () [] / ! etc etc can be overloaded [cannnot be overloaded:   (::) (.) (?:) (.*)] 

// The first argument is the current object, and the second argument is the object that 
// we are adding it to. The this keyword allows us to refer to the current object so that we can access its properties.

class operatorOverload{

    public:
    int a;
    int b;

    // not using this keyword cause we are taking only one object's properties as input 
    void operator* (operatorOverload &object){
        int value1 = object.a;
        int value2 = object.b;
        cout << value1 / value2 << endl;
    }

    // using the taking object param by reference because we may modify the values in the function 
    void operator+ (operatorOverload &object){
        int value1 = this->a;
        int value2 = object.a;
        cout << value2 - value1 << endl;
    }


    void operator- (operatorOverload &object){
        int value1 = this->a;
        int value2 = object.a;
        cout << value1 + value2 << endl;    
    }
};


// Run time polymorphism - when we have a class inheriting another class having the same function as the other class (same name & parameters) 
// then if called the function in the child class will be executed (function overriding) 

// use case of run function overriding - imagine having a class with 10 methods, now we created a child class with 
// the same methods but need to override(update) 2 methods, then run time polymorphism can be used

class Animal{
    public:
    void speak(){
        cout << "speaking " << endl;
    }
};

class Dog: public Animal{
    public:
    // this speak function will override the other function  
    void speak(){
        cout << "barking " << endl;
    }
};



// Abstraction - showing only essential information and hiding the implementation - abstraction can be achieved using classes 



int main(){

    // Encapsulation
    learningEncapsulation Encalsulation1;
    // here we are accessing the age variable that is already private
    cout << "age in Encalsulation1 is : " << Encalsulation1.getAge() << endl;



    // Inheritance
    childClassInheritance_Male rahul;
    // printing all the inherited properties of the parent class
    cout << "avgAge data by rahul : " << rahul.avgAge << endl ;
    cout << "avgHeight data by rahul : " << rahul.avgheight << endl ;
    cout << "avgHeight data by rahul : " << rahul.avgWeight << endl ;

    // printing the official child class variable (non-inherited)
    cout << "childVariable data by rahul : " << rahul.childVariable << endl ;
    
    // trying to print private properties of Female class inherited from Human
    childClassInheritance_Female anjali;
    // accessing the public variables of parent child that has been made private when they got inherited by child class 
    // won't be printed. 
    // cout << "avgAge data by anjali : " << anjali.avgAge << endl ;
    // cout << "avgHeight data by anjali : " << anjali.avgheight << endl ;
    // cout << "avgHeight data by anjali : " << anjali.avgWeight << endl ;

    // but there's a way to print those private vairables i.e. to initialize getters 
    cout << "avgAge data by anjali" << anjali.getAge() << endl;

    // official public variable of anjali child class
    cout << "childVariable data by anjali : " << anjali.childVariable << endl ;

    // Protected data members : similar to private but you can only access this variables in the class itself,
    // also in the child classes of that particular class (can be printed through getters) 

    childClassInheritance_FemaleProtected tina;
    cout << "avgAge data by tina (protected) " << tina.getAge() << endl;

    HybridCars nexonev;
    nexonev.printEv();
    nexonev.printPetrol();

    ambiguityClass3 testObj;
    testObj.ambiguityClass1::abc();
    testObj.ambiguityClass2::abc();




    // polymorphism
    functionOverloading obj;
    obj.printHello();
    obj.printHello(1);
    obj.printHello(1,2);

    operatorOverload object1, object2;
    object1.a = 70;
    object2.a = 80;
    object1.b = 7;

    cout << "result of object1 + object2 is : ";
    object1 + object2;   // subtracts both numbers

    cout << "result of object1 - object2 is: ";
    object1 - object2;   // adds both numbers

    cout << "result of object1 * object2 is : ";
    object1*object1;     // divides both numbers

    // run time polymorphism
    Dog germanShepherd;
    germanShepherd.speak();


//  Encapsulation: Information hiding     ex - hiding data in a class using private/protected methods
//  Abstraction: Implementation hiding    ex - creating a function cause it only deals with the data and hides the implementation from the user
    
    // class foo{
    //   private:
    //     int a, b;
    //   public:
    //     foo(int x=0, int y=0): a(x), b(y) {}
 
    //     int add(){    
    //       return a+b;   
    //     }
    // }  
    
    // Internal representation of any object of foo class is hidden outside of this class. --> Encapsulation.
    // Any accessible member (data/function) of an object of foo is restricted and can only be accessed by that object only.

    // foo foo_obj(3, 4);
    // int sum = foo_obj.add();
    
    // Implementation of method add is hidden. --> Abstraction.

}