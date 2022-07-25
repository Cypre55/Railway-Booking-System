// ***** Implementation for Station Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include "Station.h"
#include "Railways.h"
#include "Exceptions.h"

// Constructor
Station::Station(const string name) : name_(name) 
{ }

Station Station::CreateStation(const string name)
{
    if(name=="") throw Bad_StationName();
    return Station(name);
}

// Returns name of the station
string Station::GetName() const
{
    return name_;
}

// Returns the distance between a Station and the current station
unsigned int Station::GetDistance(const Station dest) const
{
    return (Railways::IndianRailways()).GetDistances(*this, dest);
}

// Output Stream Operator
ostream & operator << (ostream &out, const Station &station)
{
    out << "----------Station---------\n";
    out << "Name : " << station.GetName() << endl;

    return out;
}

// Destructor
Station::~Station() { }

void Station::UnitTest()
{
    cout<<"\n\n+++Unit Testing Station Class+++\n";

    //Constructors
    Station first=(Station::CreateStation("First"));
    if(first.GetName()!="First")
        cout<<"    "<<"Constructor taking string argument not working\n";
    else 
        cout<<"    "<<"Constructor taking string argument works\n";
    if(Station(first).GetName()!=first.GetName())
        cout<<"    "<<"Copy constructor not working\n";
    else 
        cout<<"    "<<"Copy constructor working\n";

    if(first.GetName()!="First")
        cout<<"    "<<"GetName() not working\n";
    else 
        cout<<"    "<<"GetName() works\n";

    Station mumbai=(Station::CreateStation("Mumbai"));
    if(mumbai.GetDistance(Station::CreateStation("Delhi"))!=1447)
        cout<<"    "<<"GetDistance() not working\n";
    else 
        cout<<"    "<<"GetDistance() works\n";
    
}
