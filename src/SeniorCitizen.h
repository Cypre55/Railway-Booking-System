// ***** Header File for Senior Citizen Booking Category Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef SENIORCITIZEN_H
#define SENIORCITIZEN_H

#include "ConcessionCategory.h"
#include "Passenger.h"
#include <map>
using namespace std;

class SeniorCitizen : public ConcessionCategory
{
    SeniorCitizen(const string& name);

    ~SeniorCitizen();

    static const map<string, double> sConcessions;
    
    public:

    map<string, double> SetConcessions() const; 

    static const SeniorCitizen& Type();

    bool CheckEligibility(const Passenger& passenger, const Date& dateOfBooking,
     const Date& dateOfReservation) const;

    double GetConcessionCharge(const BookingClass& bookingClass, const Passenger& passenger) const;

    static void UnitTest();

   Booking* CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const;
};

#endif