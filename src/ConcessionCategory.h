// ***** Header File for Concession Category Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef CONCESSIONCATEGORY_H
#define CONCESSIONCATEGORY_H

class Passenger;

#include "BookingCategory.h"
#include "BookingClass.h"
// #include "Passenger.h"
#include "Station.h"
using namespace std;

class ConcessionCategory : public BookingCategory 
{
    protected:

    ConcessionCategory(const string& name);

    public:

    virtual double GetConcessionCharge(const BookingClass& bookingClass, const Passenger& passenger) const = 0;

    virtual ~ConcessionCategory();

    Booking* CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const = 0;

    // friend ostream & operator << (ostream &out, const GeneralCategory &);

};

#endif