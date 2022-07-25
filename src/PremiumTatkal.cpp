// ***** Implimentation of Leaf Class Premium Taktal BookingCategory
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include "PremiumTatkal.h"
#include "PriorityBooking.h"

PremiumTatkal::PremiumTatkal(const string& name) : PriorityCategory(name)
{}

PremiumTatkal::~PremiumTatkal() {}

const PremiumTatkal& PremiumTatkal::Type()
{
    static const PremiumTatkal sObj ("PremiumTatkal");
    return sObj;
}

bool PremiumTatkal::CheckEligibility(const Passenger& passenger, const Date& dateOfBooking,
     const Date& dateOfReservation) const
{
    if (dateOfReservation.GetMonth() == dateOfBooking.GetMonth())
    {
        if (dateOfReservation.GetDay() - dateOfBooking.GetDay() == 1)
        {
            return true;
        }
    }
    else if (dateOfReservation.GetMonth() - dateOfBooking.GetMonth() == 1)
    {
        if (dateOfBooking.GetDay() != 1) return false;

        unsigned int rmonth = dateOfReservation.GetMonth();
        unsigned int rdate = dateOfReservation.GetDay();
        if( rmonth == 1 || rmonth == 3 || rmonth  == 5 || rmonth == 7 || rmonth == 8 || rmonth == 10 || rmonth == 12 )
        {
            if (rdate == 31) return true;
        }
        else
        {
            if (rdate == 30) return true;
        }
    }
    return false;
}

double PremiumTatkal::GetPriorityCharge(const BookingClass& bookingClass, unsigned int loadedFare, unsigned int distance) const
{
    if (distance < bookingClass.GetMinTatkalDistance())
    {
        return 0.0;
    }
    
    double charge = loadedFare * bookingClass.GetTatkalPercent();

    if (charge < bookingClass.GetMinTatkalCharge()) return bookingClass.GetMinTatkalCharge();
    if (charge > bookingClass.GetMaxTatkalCharge()) return bookingClass.GetMaxTatkalCharge();

    return 2*charge;

}

Booking* PremiumTatkal::CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const
{
    Booking* temp = new PriorityBooking(start, dest, dateOfBooking, dateOfReservation, passenger, bookingClass, PremiumTatkal::Type());
    return temp;
}