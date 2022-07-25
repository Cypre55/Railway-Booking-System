// ***** Header file for GeneralBooking Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef GENERALBOOKING_H
#define GENERALBOOKING_H

#include "Booking.h"
#include "GeneralCategory.h"
#include "Station.h"
#include "Passenger.h"

class GeneralBooking : public Booking {

    GeneralBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory);
    ~GeneralBooking();

    unsigned int ComputeFare() const;

    public:

    friend Booking* GeneralCategory::CreateNewBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory) const;
};

#endif