// ***** Header File for Railways Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef RAILWAYS_H
#define RAILWAYS_H

#include "Station.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

class Railways {

    static const vector<Station> sStations;

    static const map<string, map<string, int>> sDistStations; 

    Railways ();

    vector<Station> SetStations() const;

    map<string, map<string, int>> SetDistStations() const;

    static const Railways& CreateRailways();

    public:

    static const string sName;

    unsigned int GetDistances(Station a, Station b) const;

    friend ostream & operator << (ostream &out, const Railways &railways);

    static const Railways& IndianRailways();

    static void UnitTest();

    ~Railways();
};

#endif