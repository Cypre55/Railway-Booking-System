// ***** Implimentation of Leaf Class PriorityBooking 
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include "PriorityBooking.h"
#include "Railways.h"
#include <cmath>

PriorityBooking::PriorityBooking(const Station& start, const Station& dest, const Date& dateOfBooking,
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,
      const PriorityCategory& bookingCategory) 
      : Booking(start, dest, dateOfBooking, dateOfReservation, passenger, bookingClass, bookingCategory), category_(bookingCategory)
{
    fare_ = ComputeFare();
}

PriorityBooking::~PriorityBooking() {}

unsigned int PriorityBooking::ComputeFare() const 
{
    unsigned int distance = Railways::IndianRailways().GetDistances(start_, dest_);
    unsigned int fare = distance * bookingClass_.GetLoadFactor() * sBaseRate;

    fare += (category_).GetPriorityCharge(bookingClass_, fare, distance);

    fare += bookingClass_.GetReservationCharge();

    return round(fare);

}