// ***** Implimentation of Gender class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include "Gender.h"
#include <iostream>
using namespace std;

Gender::Gender(const string& name) : name_(name) { }

Gender::~Gender() { }

const string& Gender::GetName() const 
{ 
    return name_; 
}

template<>
const string Gender::Male::sName = "Male";

template<>
const string Gender::Female::sName = "Female";

ostream& operator<<(ostream& cout,const Gender& other)
{
        cout<<"----------Gender-Class-----------\n";
        cout << "\tGender Name: " << other.GetName() << endl;
        return cout;
}

void Gender::UnitTest()
{
    cout<<"\n\n+++Unit Testing Gender Class+++\n";
    if(Gender::Male::Type().GetName()=="Male" && Gender::Female::Type().GetName()=="Female")
        cout<<"    Gender Class works right\n";
    else
        cout<<"    Gender Class works wrong\n";
}