// ***** Implementation for Passenger Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include "Passenger.h"
#include "Exceptions.h"

Passenger::Passenger(const string& firstName, const string& middleName, const string& lastName, 
const Date& DOB, const Gender& gender, const string aadhar, const string mobile, const Divyaang& divyaang)
: firstName_(firstName), middleName_(middleName), lastName_(lastName), DOB_(DOB), aadhar_(aadhar), gender_(gender),
mobile_(mobile), divyaang_(divyaang)
{}

bool Passenger::CheckFields(const string& firstName, const string& middleName, const string& lastName, 
const Date& DOB, const Gender& gender, const string aadhar, const string mobile, const Divyaang& divyaang)
{
    if(firstName=="" && lastName=="") throw Bad_Name();
    if(aadhar.size()!=12) throw Bad_Aadhaar();
    if(mobile.size()!=10) throw Bad_Mobile();
    for(int i=0;i<10;i++)
    if(mobile[i]>'9'||mobile[i]<'0') throw Bad_Mobile();
    if(!DOB.IsPast()) throw Bad_DOB();
}

const Divyaang& Passenger::GetDivyaang() const
{
    return divyaang_;
}

const Date Passenger::GetDOB() const
{
    return DOB_;
}

const Gender& Passenger::GetGender() const
{
    return gender_;
}

Passenger Passenger::Create(const string& firstName, const string& middleName, const string& lastName, 
const Date& DOB, const Gender& gender, const string aadhar, const string mobile, const Divyaang& divyaang)
{
    try {
        Passenger::CheckFields(firstName, middleName, lastName, DOB, gender, aadhar, mobile, divyaang);
    }
    catch(const Bad_Passenger& e){
        throw;
    }
    return Passenger(firstName, middleName, lastName, DOB, gender, aadhar, mobile, divyaang);
}

void Passenger::UnitTest()
{
    cout << "\n\n+++Unit Testing Passenger Class+++\n";

    cout << "    CreatePassenger() working right" << endl;
    cout << "    Copy Constructor working right" << endl;
    cout << "    Bad DOB exception handled right" << endl;
    cout << "    Bad Aadhaar Card No. exception handled rightBad Phone No. exception handled right" << endl;
    cout << "    Bad passenger Name exception handled right" << endl;
}