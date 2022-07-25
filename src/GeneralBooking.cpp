// ***** Implimentation of Leaf Class GeneralBooking
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include "GeneralBooking.h"
#include "Railways.h"
#include <cmath>

GeneralBooking::GeneralBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) 
      : Booking(start, dest, dateOfBooking, dateOfReservation, passenger, bookingClass, bookingCategory) 
{
    fare_ = ComputeFare();
}

GeneralBooking::~GeneralBooking() {}

unsigned int GeneralBooking::ComputeFare() const 
{
    unsigned int distance = Railways::IndianRailways().GetDistances(start_, dest_);
    unsigned int fare = distance * bookingClass_.GetLoadFactor() * sBaseRate;

    fare += bookingClass_.GetReservationCharge();

    return round(fare);

}

