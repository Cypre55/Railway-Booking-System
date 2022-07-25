// ***** Static info for BookingClass
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef BOOKINGCLASSSTATICS_H
#define BOOKINGCLASSSTATICS_H

#include "BookingClass.h"

template<> const string BookingClass::ACFirstClass::sName = "ACFirstClass";
template<> double BookingClass::ACFirstClass::sLoadFactor = 6.50;
template<> bool BookingClass::ACFirstClass::sSitting = false;
template<> bool BookingClass::ACFirstClass::sAC = true;
template<> bool BookingClass::ACFirstClass::sLuxury = true;
template<> unsigned int BookingClass::ACFirstClass::sNumberOfTiers = 2;
template<> unsigned int BookingClass::ACFirstClass::sReservationCharges = 60.00;
template<> double BookingClass::ACFirstClass::sTatkalPercent = 0.30;
template<> unsigned int BookingClass::ACFirstClass::sMinTatkalCharge = 400;
template<> unsigned int BookingClass::ACFirstClass::sMaxTatkalCharge = 500;
template<> unsigned int BookingClass::ACFirstClass::sMinTatkalDistance = 500;

template<> const string BookingClass::AC2Tier::sName = "AC2Tier";
template<> double BookingClass::AC2Tier::sLoadFactor = 4.00;
template<> bool BookingClass::AC2Tier::sSitting = false;
template<> bool BookingClass::AC2Tier::sAC = true;
template<> bool BookingClass::AC2Tier::sLuxury = false;
template<> unsigned int BookingClass::AC2Tier::sNumberOfTiers = 2;
template<> unsigned int BookingClass::AC2Tier::sReservationCharges = 50;
template<> double BookingClass::AC2Tier::sTatkalPercent = 0.30;
template<> unsigned int BookingClass::AC2Tier::sMinTatkalCharge = 400;
template<> unsigned int BookingClass::AC2Tier::sMaxTatkalCharge = 500;
template<> unsigned int BookingClass::AC2Tier::sMinTatkalDistance = 500;

template<> const string BookingClass::AC3Tier::sName = "AC3Tier";
template<> double BookingClass::AC3Tier::sLoadFactor = 2.50;
template<> bool BookingClass::AC3Tier::sSitting = false;
template<> bool BookingClass::AC3Tier::sAC = true;
template<> bool BookingClass::AC3Tier::sLuxury = false;
template<> unsigned int BookingClass::AC3Tier::sNumberOfTiers = 3;
template<> unsigned int BookingClass::AC3Tier::sReservationCharges = 40;
template<> double BookingClass::AC3Tier::sTatkalPercent = 0.30;
template<> unsigned int BookingClass::AC3Tier::sMinTatkalCharge = 300;
template<> unsigned int BookingClass::AC3Tier::sMaxTatkalCharge = 400;
template<> unsigned int BookingClass::AC3Tier::sMinTatkalDistance = 500;

template<> const string BookingClass::ACChairCar::sName = "ACChairCar";
template<> double BookingClass::ACChairCar::sLoadFactor = 2.00;
template<> bool BookingClass::ACChairCar::sSitting = true;
template<> bool BookingClass::ACChairCar::sAC = true;
template<> bool BookingClass::ACChairCar::sLuxury = false;
template<> unsigned int BookingClass::ACChairCar::sNumberOfTiers = 0;
template<> unsigned int BookingClass::ACChairCar::sReservationCharges = 40;
template<> double BookingClass::ACChairCar::sTatkalPercent = 0.30;
template<> unsigned int BookingClass::ACChairCar::sMinTatkalCharge = 125;
template<> unsigned int BookingClass::ACChairCar::sMaxTatkalCharge = 225;
template<> unsigned int BookingClass::ACChairCar::sMinTatkalDistance = 250;

template<> const string BookingClass::Sleeper::sName = "Sleeper";
template<> double BookingClass::Sleeper::sLoadFactor = 1.00;
template<> bool BookingClass::Sleeper::sSitting = false;
template<> bool BookingClass::Sleeper::sAC = false;
template<> bool BookingClass::Sleeper::sLuxury = false;
template<> unsigned int BookingClass::Sleeper::sNumberOfTiers = 3;
template<> unsigned int BookingClass::Sleeper::sReservationCharges = 20;
template<> double BookingClass::Sleeper::sTatkalPercent = 0.30;
template<> unsigned int BookingClass::Sleeper::sMinTatkalCharge = 100;
template<> unsigned int BookingClass::Sleeper::sMaxTatkalCharge = 200;
template<> unsigned int BookingClass::Sleeper::sMinTatkalDistance = 500;

template<> const string BookingClass::SecondSitting::sName = "SecondSitting";
template<> double BookingClass::SecondSitting::sLoadFactor = 0.60;
template<> bool BookingClass::SecondSitting::sSitting = true;
template<> bool BookingClass::SecondSitting::sAC = false;
template<> bool BookingClass::SecondSitting::sLuxury = false;
template<> unsigned int BookingClass::SecondSitting::sNumberOfTiers = 0;
template<> unsigned int BookingClass::SecondSitting::sReservationCharges = 15;
template<> double BookingClass::SecondSitting::sTatkalPercent = 0.10;
template<> unsigned int BookingClass::SecondSitting::sMinTatkalCharge = 10;
template<> unsigned int BookingClass::SecondSitting::sMaxTatkalCharge = 15;
template<> unsigned int BookingClass::SecondSitting::sMinTatkalDistance = 100;

template<> const string BookingClass::FirstClass::sName = "FirstClass";
template<> double BookingClass::FirstClass::sLoadFactor = 3.00;
template<> bool BookingClass::FirstClass::sSitting = false;
template<> bool BookingClass::FirstClass::sAC = false;
template<> bool BookingClass::FirstClass::sLuxury = true;
template<> unsigned int BookingClass::FirstClass::sNumberOfTiers = 2;
template<> unsigned int BookingClass::FirstClass::sReservationCharges = 50;
template<> double BookingClass::FirstClass::sTatkalPercent = 0.30;
template<> unsigned int BookingClass::FirstClass::sMinTatkalCharge = 400;
template<> unsigned int BookingClass::FirstClass::sMaxTatkalCharge = 500;
template<> unsigned int BookingClass::FirstClass::sMinTatkalDistance = 500;

template<> const string BookingClass::ExecutiveChairCar::sName = "ExecutiveChairCar";
template<> double BookingClass::ExecutiveChairCar::sLoadFactor = 5.00;
template<> bool BookingClass::ExecutiveChairCar::sSitting = true;
template<> bool BookingClass::ExecutiveChairCar::sAC = true;
template<> bool BookingClass::ExecutiveChairCar::sLuxury = true;
template<> unsigned int BookingClass::ExecutiveChairCar::sNumberOfTiers = 0;
template<> unsigned int BookingClass::ExecutiveChairCar::sReservationCharges = 60;
template<> double BookingClass::ExecutiveChairCar::sTatkalPercent = 0.30;
template<> unsigned int BookingClass::ExecutiveChairCar::sMinTatkalCharge = 400;
template<> unsigned int BookingClass::ExecutiveChairCar::sMaxTatkalCharge = 500;
template<> unsigned int BookingClass::ExecutiveChairCar::sMinTatkalDistance = 250;

#endif