// ***** Header file for ConcessionBooking Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef CONCESSIONBOOKING_H
#define CONCESSIONBOOKING_H

#include "Booking.h"
#include "ConcessionCategory.h"
#include "Passenger.h"
#include "Station.h"
#include "SeniorCitizen.h"
#include "Divyaang.h"

class ConcessionBooking : public Booking {

    ConcessionBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const ConcessionCategory& bookingCategory);
    ~ConcessionBooking();

    unsigned int ComputeFare() const;
    const ConcessionCategory& category_;

    public:

    friend Booking* SeniorCitizen::CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const;

    // template<>
    friend Booking* Divyaang::TB::CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const;

    // template<>
    friend Booking* Divyaang::Ortho::CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const;
    
    // template<>
    friend Booking* Divyaang::Cancer::CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const;
    
    // template<>
    friend Booking* Divyaang::Blind::CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const;
    
};

#endif