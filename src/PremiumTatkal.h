// ***** Header File for Premium Tatkal Booking Category Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef PREMIUMTATKAL_H
#define PREMIUMTATKAL_H

#include "PriorityCategory.h"

class PremiumTatkal : public PriorityCategory
{
    PremiumTatkal(const string& name);

    ~PremiumTatkal();

    public:

    static const PremiumTatkal& Type();

    bool CheckEligibility(const Passenger& passenger, const Date& dateOfBooking,
     const Date& dateOfReservation) const;

    double GetPriorityCharge(const BookingClass& bookingClass, unsigned int loadedFare, unsigned int distance) const;

    static void UnitTest();

    Booking* CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const;
};

#endif