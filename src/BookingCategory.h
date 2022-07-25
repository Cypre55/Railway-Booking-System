// ***** Header File for Booking Category Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef BOOKINGCATEGORY_H
#define BOOKINGCATEGORY_H

class Booking;
class Passenger;
// #include "Booking.h"
// #include "Passenger.h"
#include "Station.h"
#include "Date.h"
#include "BookingClass.h"
#include <string>
using namespace std;

class BookingCategory {
    protected:
    string name_;

    BookingCategory(string name);

    public:

    virtual ~BookingCategory() = 0;

    string GetName() const;

    virtual bool CheckEligibility(const Passenger& passenger, const Date& dateOfBooking,
     const Date& dateOfReservation) const = 0;

    virtual Booking* CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,
      const BookingCategory& bookingCategory) const = 0;
};

#endif