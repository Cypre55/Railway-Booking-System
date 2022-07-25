// ***** Header File for Tatkal Booking Category Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef TATKAL_H
#define TATKAL_H

#include "PriorityCategory.h"

class Tatkal : public PriorityCategory 
{
    Tatkal(const string& name);

    ~Tatkal();

    public:

    static const Tatkal& Type();

    bool CheckEligibility(const Passenger& passenger, const Date& dateOfBooking,
     const Date& dateOfReservation) const;

    double GetPriorityCharge(const BookingClass& bookingClass, unsigned int loadedFare, unsigned int distance) const;

    static void UnitTest();

    Booking* CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const;
};

#endif