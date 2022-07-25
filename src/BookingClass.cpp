// ***** Implimentation of BookingClass class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include "BookingClass.h"
#include "BookingClassStatics.h"

BookingClass::BookingClass(const string& name) : name_(name)
{}

BookingClass::~BookingClass() {}

string BookingClass::GetName() const
{
    return name_;
}

ostream& operator << (ostream& cout, const BookingClass& other)
{
    cout<<"--------Booking-Class------------\n";
        cout<<"\tBooking Class Name: "<<other.GetName()<<endl;
        cout<<"\tBooking Class Fare Load: "<<other.GetLoadFactor()<<endl;
        cout<<"\tBooking Class Berth: "<<other.IsSitting()<<endl;
        cout<<"\tBooking Class No. of Tiers: "<<other.GetNumberOfTiers()<<endl;
        cout<<"\tBooking Class Luxury Statue: "<<other.IsLuxury()<<endl;
        cout<<"\tBooking Class Reservation Charge: "<<other.GetReservationCharge()<<endl;
        
        return cout;
}