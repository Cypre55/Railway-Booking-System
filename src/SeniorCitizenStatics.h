// ***** Static info for Senior Citizen ConcessionCategory
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef SENIORCITIZENSTATICS_H
#define SENIORCITIZENSTATICS_H

#include "SeniorCitizen.h"

map<string, double> SeniorCitizen::SetConcessions() const
{
    map<string, double> concessions;
    concessions.insert(make_pair("Male", 0.40));
    concessions.insert(make_pair("Female", 0.50));

    return concessions;
}

#endif