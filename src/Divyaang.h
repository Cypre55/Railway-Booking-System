// ***** Header File for Divyaang and DivyaangType Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef DIVYAANG_H
#define DIVYAANG_H

#include "ConcessionCategory.h"
// #include "ConcessionBooking.h"
// #include "Passenger.h"
class Passenger;

#include <map>
#include <string>
using namespace std;

template<typename T>
class DivyaangTypes;

class Divyaang : public ConcessionCategory
{
    struct TBType {};
    struct BlindType {};
    struct OrthoType {};
    struct CancerType {};
    struct NullType {};

    const string disabilityName_;

    protected:

    Divyaang(const string& name, const string& disabilityName);

    virtual ~Divyaang();

    public:

    string GetDisabilityName() const;

    // static const Divyaang nullDivyaang;

    typedef DivyaangTypes<TBType> TB;
    typedef DivyaangTypes<BlindType> Blind;
    typedef DivyaangTypes<OrthoType> Ortho;
    typedef DivyaangTypes<CancerType> Cancer;
    typedef DivyaangTypes<NullType> NullDivyaang;

};

template<typename T>
class DivyaangTypes : public Divyaang
{
    static const map<string, double> sConcessions;

    static const string sDisabilityName;

    DivyaangTypes(const string& disabilityName = DivyaangTypes<T>::sDisabilityName);

    ~DivyaangTypes();

    public:

    map<string, double> SetConcessions() const; 

    bool CheckEligibility(const Passenger& passenger, const Date& dateOfBooking,
     const Date& dateOfReservation) const;

    double GetConcessionCharge(const BookingClass& bookingClass, const Passenger& passenger) const;

    static const DivyaangTypes<T>& Type();

    static void UnitTest();

    Booking* CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const;
    
};

// template <typename T>
// Booking* DivyaangTypes<T>::CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
//      const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
//       const BookingCategory& bookingCategory) const
// {
//     Booking* temp = new ConcessionBooking(start, dest, dateOfBooking, dateOfReservation, passenger, bookingClass, DivyaangTypes<T>::Type());
//     return temp;
// }


#endif