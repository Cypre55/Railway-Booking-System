// ***** Header File for General Category Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef GENERALCATEGORY_H
#define GENERALCATEGORY_H

#include "BookingCategory.h"
using namespace std;

class GeneralCategory : public BookingCategory
{
    private:

    GeneralCategory(const string& name);

    public:

    ~GeneralCategory();

    static const GeneralCategory& Type();

    bool CheckEligibility(const Passenger& passenger, const Date& dateOfBooking,
     const Date& dateOfReservation) const;

    Booking* CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const;

    static void UnitTest();

    // friend ostream & operator << (ostream &out, const GeneralCategory &);

};

#endif