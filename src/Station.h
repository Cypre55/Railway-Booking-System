// ***** Header File for Station Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef STATION_H
#define STATION_H

#include <string>
using namespace std;

class Station {
    
    const string name_;
    Station(const string name);

    public:

    static Station CreateStation(const string name);

    string GetName() const;

    unsigned int GetDistance(const Station dest) const;

    friend ostream & operator << (ostream &out, const Station &station);

    // Station& operator=(const Station& station);

    static void UnitTest();

    ~Station();
};

#endif