// ***** Implimentation of Leaf Class ConcessionBooking 
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include "ConcessionBooking.h"
#include "Railways.h"
#include <cmath>

ConcessionBooking::ConcessionBooking(const Station& start, const Station& dest, const Date& dateOfBooking,
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,
      const ConcessionCategory& bookingCategory) 
      : Booking(start, dest, dateOfBooking, dateOfReservation, passenger, bookingClass, bookingCategory), category_(bookingCategory)
{
    fare_ = ComputeFare();
}

ConcessionBooking::~ConcessionBooking() {}

unsigned int ConcessionBooking::ComputeFare() const 
{
    unsigned int distance = Railways::IndianRailways().GetDistances(start_, dest_);
    unsigned int fare = distance * bookingClass_.GetLoadFactor() * sBaseRate;

    fare *= (1 - (category_).GetConcessionCharge(bookingClass_, passenger_));

    fare += bookingClass_.GetReservationCharge();

    return round(fare);
}