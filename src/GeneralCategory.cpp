// ***** Implimentaion of Class General Category
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include "GeneralCategory.h"
#include "GeneralBooking.h"

GeneralCategory::GeneralCategory(const string& name) : BookingCategory(name)
{ }

GeneralCategory::~GeneralCategory() { }

const GeneralCategory& GeneralCategory::Type()
{
    static const GeneralCategory sObj ("GeneralCategory");
    return sObj;
}

bool GeneralCategory::CheckEligibility(const Passenger& passenger, const Date& dateOfBooking,
     const Date& dateOfReservation) const
{
    // All Passengers are allowed
    return true;
}

Booking* GeneralCategory::CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking, \
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass, \
      const BookingCategory& bookingCategory) const
{
    Booking* temp = new GeneralBooking(start, dest, dateOfBooking, dateOfReservation, passenger, bookingClass, bookingCategory);
    return temp;
}
