// ***** Implimentation of Leaf Class SeniorCitizen BookingCategory
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include "SeniorCitizen.h"
#include "SeniorCitizenStatics.h"
#include "ConcessionBooking.h"

SeniorCitizen::SeniorCitizen(const string& name) : ConcessionCategory(name)
{}

SeniorCitizen::~SeniorCitizen() {}

const SeniorCitizen& SeniorCitizen::Type()
{
    static const SeniorCitizen sObj ("SeniorCitizen");
    return sObj;
}

bool SeniorCitizen::CheckEligibility(const Passenger& passenger, const Date& dateOfBooking,
     const Date& dateOfReservation) const
{
    if (passenger.GetGender().GetName() == "Male" && passenger.GetDOB().GetAge() >= 60) return true;
    if (passenger.GetGender().GetName() == "Female" && passenger.GetDOB().GetAge() >= 58) return true;
    return false;
}

double SeniorCitizen::GetConcessionCharge(const BookingClass& bookingClass, const Passenger& passenger) const
{
    return sConcessions.find(passenger.GetGender().GetName())->second;
}

const map<string, double> SeniorCitizen::sConcessions = (SeniorCitizen::Type()).SetConcessions();

Booking* SeniorCitizen::CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const
{
    Booking* temp = new ConcessionBooking(start, dest, dateOfBooking, dateOfReservation, passenger, bookingClass, SeniorCitizen::Type());
    return temp;
}