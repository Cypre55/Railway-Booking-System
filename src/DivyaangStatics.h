// ***** Static info for Divyaang ConcessionCategory
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef DIVYAANGSTATICS_H
#define DIVYAANGSTATICS_H
#include "Divyaang.h"

template <>
map<string, double> Divyaang::Blind::SetConcessions() const
{
    map<string, double> concessions;
    concessions.insert(make_pair("ACFirstClass", 0.50));
    concessions.insert(make_pair("ExecutiveChairCar", 0.75));
    concessions.insert(make_pair("AC2Tier", 0.50));
    concessions.insert(make_pair("FirstClass", 0.75));
    concessions.insert(make_pair("AC3Tier", 0.75));
    concessions.insert(make_pair("ACChairCar", 0.75));
    concessions.insert(make_pair("Sleeper", 0.75));
    concessions.insert(make_pair("SecondSitting", 0.75));

    return concessions;
}

template <>
map<string, double> Divyaang::Ortho::SetConcessions() const
{
    map<string, double> concessions;
    concessions.insert(make_pair("ACFirstClass", 0.50));
    concessions.insert(make_pair("ExecutiveChairCar", 0.75));
    concessions.insert(make_pair("AC2Tier", 0.50));
    concessions.insert(make_pair("FirstClass", 0.75));
    concessions.insert(make_pair("AC3Tier", 0.75));
    concessions.insert(make_pair("ACChairCar", 0.75));
    concessions.insert(make_pair("Sleeper", 0.75));
    concessions.insert(make_pair("SecondSitting", 0.75));

    return concessions;
}

template <>
map<string, double> Divyaang::Cancer::SetConcessions() const
{
    map<string, double> concessions;
    concessions.insert(make_pair("ACFirstClass", 0.50));
    concessions.insert(make_pair("ExecutiveChairCar", 0.75));
    concessions.insert(make_pair("AC2Tier", 0.50));
    concessions.insert(make_pair("FirstClass", 0.75));
    concessions.insert(make_pair("AC3Tier", 1.00));
    concessions.insert(make_pair("ACChairCar", 1.00));
    concessions.insert(make_pair("Sleeper", 1.00));
    concessions.insert(make_pair("SecondSitting", 1.00));

    return concessions;
}

template <>
map<string, double> Divyaang::TB::SetConcessions() const
{
    map<string, double> concessions;
    concessions.insert(make_pair("ACFirstClass", 0.00));
    concessions.insert(make_pair("ExecutiveChairCar", 0.00));
    concessions.insert(make_pair("AC2Tier", 0.00));
    concessions.insert(make_pair("FirstClass", 0.75));
    concessions.insert(make_pair("AC3Tier", 0.00));
    concessions.insert(make_pair("ACChairCar", 0.00));
    concessions.insert(make_pair("Sleeper", 0.75));
    concessions.insert(make_pair("SecondSitting", 0.75));

    return concessions;
}

template <>
map<string, double> Divyaang::NullDivyaang::SetConcessions() const
{
    map<string, double> concessions;

    return concessions;
}

#endif