// ***** Header file for Booking Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef BOOKING_H
#define BOOKING_H

#include "Date.h"
#include "BookingClass.h"
#include "BookingCategory.h"
#include "Passenger.h"
#include "Station.h"
#include <string>
#include <vector>
using namespace std;

class Booking {

    static unsigned int sPNRSerial;
    static unsigned int sNoOfBookings;
    
    protected:

    static const double sBaseRate;
    unsigned int PNR_;
    unsigned int fare_;
    Date dateOfReservation_;
    Date dateOfBooking_;
    bool bookingStatus_;
    string bookingMessage_;
    const BookingClass& bookingClass_;
    const BookingCategory& bookingCategory_;
    const Passenger passenger_;
    const Station start_;
    const Station dest_;

    Booking(const Station& start, const Station& dest, const Date& dateOfBooking,\
     const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
      const BookingCategory& bookingCategory);

    virtual unsigned int ComputeFare() const = 0;

    public:

    virtual ~Booking();

    static vector<Booking*> sBookings;

    static void CreateBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
 const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
  const BookingCategory& bookingCategory);

    static const Booking& getLastBooking();

  friend ostream& operator<<(ostream& cout,const Booking& obj);

};

#endif