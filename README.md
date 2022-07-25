# Railway Booking System

### Usage

```bash
# All the below commands are to be run in src directory
# For fresh build
make clean

# Running Application Test
make RunApplicationTest

# Running Unit Test
make RunUnitTest
```

### How to Make a Booking

1. Import the following header files

```c++
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
```

2. Create a Passenger using the following constructor

```c++
Passenger::Passenger(const string& firstName, const string& middleName, const string& lastName, 
const Date& DOB, const Gender& gender, const string aadhar, const string mobile, const Divyaang& divyaang)
    
// Example
const Passenger p1=Passenger::Create("Bishal","Bag","",Date::CreateDate(1,2,2000),Gender::Male::Type(),
                                "123456789012","1234567890",Divyaang::Cancer::Type());
```

3. Create a Booking using the following function

```c++
void Booking::CreateBooking(const Station& start, const Station& dest, const Date& dateOfBooking,\
 const Date& dateOfReservation, const Passenger& passenger, const BookingClass& bookingClass,\
  const BookingCategory& bookingCategory)
    
// Example
Booking::CreateBooking(Station::CreateStation("Kolkata"),Station::CreateStation("Delhi"),Date::CreateDate(9,4,2024),Date::CreateDate(31, 12, 2024),x1, BookingClass::ACFirstClass::Type(),Divyaang::Cancer::Type());
```

4. Print Receipt

```c++
// Option 1
std::cout << Booking::GetLastBooking() << std::endl;

// Option 2
for (Booking* b : Booking::sBookings)
    std::cout << *(b) << std::endl;
```

### Folder Structure

```bash
├── Documents
│   ├── 19CS30013_Design.pdf
│   ├── 19CS30013_Test_Plan.pdf
│   ├── 19CS30013_UML_.pdf
│   ├── Design.txt
│   └── Testplan.txt
├── Problem Statement
│   ├── 2021_H1_SE_Assignment_3 Clarifications.pdf
│   └── 2021_H1_SE_Assignment_3.pdf
├── README.md
└── src
    ├── ApplicationTest
    ├── ApplicationTest.cpp
    ├── BookingCategory.cpp
    ├── BookingCategory.h
    ├── BookingClass.cpp
    ├── BookingClass.h
    ├── BookingClassStatics.h
    ├── Booking.cpp
    ├── Booking.h
    ├── ConcessionBooking.cpp
    ├── ConcessionBooking.h
    ├── ConcessionCategory.cpp
    ├── ConcessionCategory.h
    ├── Date.cpp
    ├── Date.h
    ├── Divyaang.cpp
    ├── Divyaang.h
    ├── DivyaangStatics.h
    ├── Exceptions.h
    ├── Gender.cpp
    ├── Gender.h
    ├── GeneralBooking.cpp
    ├── GeneralBooking.h
    ├── GeneralCategory.cpp
    ├── GeneralCategory.h
    ├── Makefile
    ├── Passenger.cpp
    ├── Passenger.h
    ├── PremiumTatkal.cpp
    ├── PremiumTatkal.h
    ├── PriorityBooking.cpp
    ├── PriorityBooking.h
    ├── PriorityCategory.cpp
    ├── PriorityCategory.h
    ├── Railways.cpp
    ├── Railways.h
    ├── ReadMe.txt
    ├── SeniorCitizen.cpp
    ├── SeniorCitizen.h
    ├── SeniorCitizenStatics.h
    ├── Settings.h
    ├── Station.cpp
    ├── Station.h
    ├── Tatkal.cpp
    ├── Tatkal.h
    ├── UnitTest
    └── UnitTest.cpp
```



### Future Improvements

* Read Rates, Stations and Distance from JSON files
* Text User Interface / Graphical User Interface