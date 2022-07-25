// ***** Implimentaion of Abstract Base Class Booking Category
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include "BookingCategory.h"

BookingCategory::BookingCategory(string name) : name_(name)
{ };

BookingCategory::~BookingCategory() { }

string BookingCategory::GetName() const
{
    return name_;
}