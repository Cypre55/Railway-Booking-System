// ***** Header file for PriorityBooking Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef PRIORITYBOOKING_H
#define PRIORITYBOOKING_H

#include "Booking.h"
#include "PriorityCategory.h"
#include "Passenger.h"
#include "Station.h"
#include "Tatkal.h"
#include "PremiumTatkal.h"

class PriorityBooking : public Booking {

    PriorityBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const PriorityCategory& bookingCategory);
    ~PriorityBooking();

    unsigned int ComputeFare() const;
    const PriorityCategory& category_;

    public:

    friend Booking* Tatkal::CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const;

    friend Booking* PremiumTatkal::CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const;
};

#endif