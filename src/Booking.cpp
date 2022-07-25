// ***** Implimentation of Abstract Base Class Booking 
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include "Booking.h"
#include "Exceptions.h"
#include "Settings.h"

Booking::Booking(const Station& start, const Station& dest, const Date& dateOfBooking,\
 const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
  const BookingCategory& bookingCategory) 
 : start_(start), dest_(dest), dateOfBooking_(dateOfBooking), dateOfReservation_(dateOfReservation),
    passenger_(passenger), bookingClass_(bookingClass), bookingCategory_(bookingCategory)
{
    PNR_ = ++sPNRSerial;
    bookingStatus_ = true;
    bookingMessage_ = "BOOKING SUCCEEDED";
    sBookings.push_back(this);
}

Booking::~Booking() {}

vector<Booking*> Booking::sBookings;
unsigned int Booking::sPNRSerial = 0;
unsigned int Booking::sNoOfBookings = 0;


void Booking::CreateBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
 const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
  const BookingCategory& bookingCategory)
{
    if (start.GetName() == dest.GetName())
    {
        throw Invalid_Stations();
    }

    if(!dateOfBooking.CheckYearSpan(dateOfReservation)) throw Invalid_Bdate();

    if(!bookingCategory.CheckEligibility(passenger, dateOfBooking, dateOfReservation)) throw Invalid_Category();

    // Date dateOfBooking_ = dateOfBooking;

    Booking* currBooking = bookingCategory.CreateNewBooking(start, dest, dateOfBooking, dateOfReservation, passenger, bookingClass, bookingCategory);
}

const Booking& Booking::getLastBooking()
{
    return *sBookings.back();
}

ostream& operator<<(ostream& cout,const Booking& obj){
    cout<<"----------Booking--------------\n";
    cout<<"PNR number: "<<obj.PNR_<<endl;
    cout<<"\tFrom station: "<<obj.start_.GetName()<<endl;
    cout<<"\tTo station: "<<obj.dest_.GetName()<<endl;
    cout<<"\tBooking Date: ";
    cout<<obj.dateOfBooking_;
    cout<<"\tTravel Date: ";
    cout<<obj.dateOfReservation_;
    cout<<"\tTravel Class: "<<obj.bookingClass_.GetName()<<endl;
    cout<<"\tTravel Category: "<<obj.bookingCategory_.GetName()<<endl;
    cout<<"\tFare: "<<obj.fare_<<endl;

    return cout;
}