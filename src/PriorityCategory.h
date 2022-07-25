// ***** Header File for Priority Category Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef PRIORITYCATEGORY_H
#define PRIORITYCATEGORY_H

#include "BookingCategory.h"
using namespace std;

class PriorityCategory : public BookingCategory
{
    protected:

    PriorityCategory(const string& name);

    public:

    virtual double GetPriorityCharge(const BookingClass& bookingClass, unsigned int loadedFare, unsigned int distance) const = 0;

    virtual ~PriorityCategory();

    Booking* CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const = 0;

    // friend ostream & operator << (ostream &out, const GeneralCategory &);

};

#endif