// ***** Application Testing
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

int main(void)
{
    cout<<"++++Testing Compute Fare\n\n";

    cout << "Expected Fare: 2452" << endl;
    const Passenger x1=Passenger::Create("Bishal","Bag","",Date::CreateDate(1,2,2000),Gender::Male::Type(),
                                "123456789012","1234567890",Divyaang::Cancer::Type());
    try{
        Booking::CreateBooking(Station::CreateStation("Kolkata"),Station::CreateStation("Delhi"),Date::CreateDate(9,4,2024),Date::CreateDate(31, 12, 2024),x1,
                        BookingClass::ACFirstClass::Type(),Divyaang::Cancer::Type());
        cout << Booking::getLastBooking() << endl;
    }
    catch(const Bad_Booking& e){
            cout<<e.what();
    }

    const Passenger x3=Passenger::Create("Bishal","Bag","", Date::CreateDate(1,5,2001),Gender::Male::Type(),
                                "123456789234","1234567890",Divyaang::Cancer::Type());
    try{
        cout << "Expected Fare: 2234" << endl;
        Booking::CreateBooking(Station::CreateStation("Mumbai"),Station::CreateStation("Chennai"),Date::CreateDate(9,4,2021),Date::CreateDate(12, 12, 2021),x3,
                        BookingClass::ACFirstClass::Type(),Divyaang::Cancer::Type());
        cout << Booking::getLastBooking() << endl;
    }
    catch(const Bad_Booking& e){
            cout<<e.what();
    }

    const Passenger x8=Passenger::Create("","Kumar","Saha",Date::CreateDate(1,5,1960),Gender::Male::Type(),
                                "123456789340","1234567890");
    try{
        cout << "Expected Fare: 2726" << endl;
        Booking::CreateBooking(Station::CreateStation("Mumbai"),Station::CreateStation("Chennai"),Date::CreateDate(9,4,2021),Date::CreateDate(12, 9, 2021),x8,
                        BookingClass::AC2Tier::Type(),GeneralCategory::Type());
        cout << Booking::getLastBooking() << endl;
    }
    catch(const Bad_Booking& e){
            cout<<e.what();
    }
    cout << "\n\n";

    
    cout<<"Expected Fare: 1848\n";
    Booking::CreateBooking(Station::CreateStation("Mumbai"),Station::CreateStation("Delhi"),Date::CreateDate(9,4,2021),Date::CreateDate(10, 1, 2022),x8,
                            BookingClass::AC3Tier::Type(),GeneralCategory::Type());
    cout << Booking::getLastBooking() << endl;
    

    cout<<"\n\nExpected Fare: 1124\n";
    const Passenger x9=Passenger::Create("","Kumar","Saha", Date::CreateDate(1,5,1950),Gender::Male::Type(),
                            "123456789340","1234567890");
    Booking::CreateBooking(Station::CreateStation("Mumbai"),Station::CreateStation("Delhi"),Date::CreateDate(9,4,2021),Date::CreateDate(12, 9, 2021),x9,
                            BookingClass::AC3Tier::Type(),SeniorCitizen::Type());    
    cout << Booking::getLastBooking() << endl;

    cout<<"\n\nExpected Fare: 2411\n";
    const Passenger x10=Passenger::Create("","Kumar","Saha", Date::CreateDate(1,5,1950),Gender::Male::Type(),
                            "123456789340","1234567890",Divyaang::Cancer::Type());
    Booking::CreateBooking(Station::CreateStation("Mumbai"),Station::CreateStation("Delhi"),Date::CreateDate(9,4,2021),Date::CreateDate(12, 9, 2021),x10,
                            BookingClass::ACFirstClass::Type(),Divyaang::Cancer::Type());
    cout << Booking::getLastBooking() << endl;
    
}