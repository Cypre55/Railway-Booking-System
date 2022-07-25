// ***** Header File for Passenger Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef PASSENGER_H
#define PASSENGER_H

class Divyaang;

#include <string>
#include "Date.h"
#include "Gender.h"
#include "Divyaang.h"
using namespace std;

class Passenger 
{
    
    const string firstName_;
    const string middleName_;
    const string lastName_;
    const Date DOB_;
    const Gender& gender_;
    const string aadhar_;
    const string mobile_;
    const Divyaang& divyaang_;
    const string divyangID_ = " ";

    Passenger(const string& firstName, const string& middleName, const string& lastName, 
const Date& DOB, const Gender& gender, const string aadhar, const string mobile, const Divyaang& divyaang);
    
    public:

    static bool CheckFields(const string& firstName, const string& middleName, const string& lastName, 
const Date& DOB, const Gender& gender, const string aadhar, const string mobile, const Divyaang& divyaang);

    static void UnitTest();

    const Divyaang& GetDivyaang() const;

    const Date GetDOB() const;

    const Gender& GetGender() const;

    static Passenger Create(const string& firstName, const string& middleName, const string& lastName, 
const Date& DOB, const Gender& gender, const string aadhar, const string mobile, const Divyaang& divyaang = Divyaang::NullDivyaang::Type());
};

#endif