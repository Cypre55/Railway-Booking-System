// ***** Unit Testing
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include <iostream>
#include "Railways.h"
#include "Station.h"
#include "Date.h"
#include "SeniorCitizen.h"
#include "Gender.h"
#include "Divyaang.h"
#include "Booking.h"
#include "BookingClass.h"
#include "GeneralCategory.h"
#include "Tatkal.h"
#include "PremiumTatkal.h"
#include "Exceptions.h"
#include <ctime>
#include <cstring>

int main(void)
{
    Station::UnitTest();
    Railways::UnitTest();
    Date::UnitTest();
    Gender::UnitTest();
    Passenger::UnitTest();
}