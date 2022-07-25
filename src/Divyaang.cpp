// ***** Implimentation of Leaf Class Divyaang BookingCategory
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include "Divyaang.h"
#include "DivyaangStatics.h"
#include "Passenger.h"
#include "ConcessionBooking.h"
#include <iostream>
using namespace std;

Divyaang::Divyaang(const string& name, const string& disabilityName) : ConcessionCategory(name), disabilityName_(disabilityName)
{}

Divyaang::~Divyaang() {}

string Divyaang::GetDisabilityName() const
{
    return disabilityName_;
}

template <typename T>
DivyaangTypes<T>::DivyaangTypes(const string& disabilityName) : Divyaang("Divyaang", disabilityName)
{}

template <typename T>
DivyaangTypes<T>::~DivyaangTypes() {}

template <typename T>
bool DivyaangTypes<T>::CheckEligibility(const Passenger& passenger, const Date& dateOfBooking,
     const Date& dateOfReservation) const
{
    if(passenger.GetDivyaang().GetDisabilityName() == DivyaangTypes<T>::Type().GetDisabilityName()) return true;
    return false;
}

template <typename T>
double DivyaangTypes<T>::GetConcessionCharge(const BookingClass& bookingClass, const Passenger& passenger) const
{
    return sConcessions.find(bookingClass.GetName())->second;
}

template <typename T>
const DivyaangTypes<T>& DivyaangTypes<T>::Type()
{
    static const DivyaangTypes<T> sObj;
    return sObj;
}



template <>
const string Divyaang::TB::sDisabilityName = "TB";
template <>
const map<string, double> Divyaang::TB::sConcessions = (Divyaang::TB::Type()).SetConcessions();

template <>
const string Divyaang::Blind::sDisabilityName = "Blind";
template <>
const map<string, double> Divyaang::Blind::sConcessions = (Divyaang::Blind::Type()).SetConcessions();

template <>
const string Divyaang::Ortho::sDisabilityName = "Ortho";
template <>
const map<string, double> Divyaang::Ortho::sConcessions = (Divyaang::Ortho::Type()).SetConcessions();

template <>
const string Divyaang::Cancer::sDisabilityName = "Cancer";
template <>
const map<string, double> Divyaang::Cancer::sConcessions = (Divyaang::Cancer::Type()).SetConcessions();

template <>
const string Divyaang::NullDivyaang::sDisabilityName = "Null";
template <>
const map<string, double> Divyaang::NullDivyaang::sConcessions = (Divyaang::NullDivyaang::Type()).SetConcessions();

template <>
Booking* Divyaang::Cancer::CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const
{
    Booking* temp = new ConcessionBooking(start, dest, dateOfBooking, dateOfReservation, passenger, bookingClass, Divyaang::Cancer::Type());
    return temp;
}

template <>
Booking* Divyaang::TB::CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const
{
    Booking* temp = new ConcessionBooking(start, dest, dateOfBooking, dateOfReservation, passenger, bookingClass, Divyaang::TB::Type());
    return temp;
}

template <>
Booking* Divyaang::Blind::CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const
{
    Booking* temp = new ConcessionBooking(start, dest, dateOfBooking, dateOfReservation, passenger, bookingClass, Divyaang::Blind::Type());
    return temp;
}

template <>
Booking* Divyaang::Ortho::CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const
{
    Booking* temp = new ConcessionBooking(start, dest, dateOfBooking, dateOfReservation, passenger, bookingClass, Divyaang::Ortho::Type());
    return temp;
}

template <>
Booking* Divyaang::NullDivyaang::CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const
{
}
