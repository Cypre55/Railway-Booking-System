// ***** Implementation for Railways Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include "Railways.h"
#include "Exceptions.h"

// Defining Static Name
const string Railways::sName = "Indian Railways";

// Constructor
Railways::Railways() { }

// Returns Singleton Object called sIndianRailways
const Railways& Railways::IndianRailways()
{
    try 
    {
        return Railways::CreateRailways();
    }
    catch(const Bad_Railways& e){
        throw;
    }
}

const Railways& Railways::CreateRailways()
{
    vector<Station> stations;
    map<pair<string,string>,int> distances;
    // cout<<sMasterStations.size()<<endl;
    // for(auto x=sStations.begin();x!=sStations.end();x++)
    // {
    //     if(stations.find(x->first)!=stations.end())
    //     throw duplicate_stations();
    //     else stations.insert(x->first);
    // }

    

    // for(auto x=sDistStations.begin();x!=sDistStations.end();x++)
    // {
    //     pair<string,string> pairs=make_pair(x->first.first->GetName(),x->first.second->GetName());
    //     if(distances.find(pairs)!=distances.end())
    //     throw duplicate_stationpairs();
    //     else distances.insert(make_pair(pairs,1));
    // }

    static const Railways sIndianRailways;
    return sIndianRailways;
}

// Set the Stations
vector<Station> Railways::SetStations () const
{
    vector<Station> stations;
    stations.push_back(Station::CreateStation("Mumbai")); 
    stations.push_back(Station::CreateStation("Delhi")); 
    stations.push_back(Station::CreateStation("Bangalore")); 
    stations.push_back(Station::CreateStation("Kolkata")); 
    stations.push_back(Station::CreateStation("Chennai")); 

    return stations;
}

// Assigns sStations the Stations
const vector<Station> Railways::sStations = (Railways::IndianRailways()).SetStations();

// Set the distances between stations
map<string, map<string, int>> Railways::SetDistStations() const
{
    map<string, map<string, int>> distances;

    map<string, int> Mumbai;
    Mumbai.insert(make_pair("Delhi", 1447));
    Mumbai.insert(make_pair("Bangalore", 981));
    Mumbai.insert(make_pair("Kolkata", 2014));
    Mumbai.insert(make_pair("Chennai", 1338));
    distances.insert(make_pair("Mumbai", Mumbai));

    map<string, int> Delhi;
    Delhi.insert(make_pair("Mumbai", 1447));
    Delhi.insert(make_pair("Bangalore", 2150));
    Delhi.insert(make_pair("Kolkata", 1472));
    Delhi.insert(make_pair("Chennai", 2180));
    distances.insert(make_pair("Delhi", Delhi));

    map<string, int> Bangalore;
    Bangalore.insert(make_pair("Mumbai", 981));
    Bangalore.insert(make_pair("Delhi", 2150));
    Bangalore.insert(make_pair("Kolkata", 1871));
    Bangalore.insert(make_pair("Chennai", 350));
    distances.insert(make_pair("Bangalore", Bangalore));

    map<string, int> Kolkata;
    Kolkata.insert(make_pair("Mumbai", 2014));
    Kolkata.insert(make_pair("Delhi", 1472));
    Kolkata.insert(make_pair("Bangalore", 1871));
    Kolkata.insert(make_pair("Chennai", 1659));
    distances.insert(make_pair("Kolkata", Kolkata));

    map<string, int> Chennai;
    Chennai.insert(make_pair("Mumbai", 1338));
    Chennai.insert(make_pair("Delhi", 2180));
    Chennai.insert(make_pair("Bangalore", 350));
    Chennai.insert(make_pair("Kolkata", 1659));
    distances.insert(make_pair("Chennai", Chennai));

    return distances;
}

// Assign sDistStations the distances between stations
const map<string, map<string, int>> Railways::sDistStations = (Railways::IndianRailways()).SetDistStations();

unsigned int Railways::GetDistances(Station a, Station b) const
{
    if (a.GetName() == b.GetName())
        throw Bad_Path();
    else
    {
        if (sDistStations.find(a.GetName()) != sDistStations.end())
        {
            if (sDistStations.find(a.GetName())->second.find(b.GetName()) != sDistStations.find(a.GetName())->second.end())
                return sDistStations.find(a.GetName())->second.find(b.GetName())->second;
            else
                throw Bad_Station();
        }
        else
            throw Bad_Station();
    }
}

// Output Stream Operator
ostream & operator << (ostream &out, const Railways &railways)
{
    out << "---------------Indian--Railways---------------\n";
    out << "Stations: \n\n";
    for (Station s : Railways::sStations)
    {
        out << s.GetName() << endl;
        out << "\tDistance: \n";
        for (Station j : Railways::sStations)
        {
            if (j.GetName() != s.GetName())
            {
                out << "\t\t" << j.GetName() << " " << Railways::IndianRailways().GetDistances(s, j) << endl;
            }
        }
        out << "\n";
    }
    out << "\n";

    return out;
}

// Destructor
Railways::~Railways() { }

void Railways::UnitTest()
{
    cout<<"\n\n+++Unit Testing Railways Class+++\n";
    cout<<"    Name: "<<Railways::sName<<endl;
    if(&Railways::IndianRailways()!=&Railways::IndianRailways())
        cout<<"    Singleton class not returned\n";
    else cout<<"    Singleton class returned\n";
    
    Station Delhi = Station::CreateStation("Delhi");
    Station Chennai = Station::CreateStation("Chennai");
    Station Kolkata = Station::CreateStation("Kolkata");
    Station Bangalore = Station::CreateStation("Bangalore");
    Station Mumbai = Station::CreateStation("Mumbai");

    bool distances=true;
    if(Railways::IndianRailways().GetDistances(Delhi,Mumbai)!=1447)
    {
        distances=false;
        cout<<"    Distance between Delhi and Mumbai returned wrong\n";
    }    
    if(Railways::IndianRailways().GetDistances(Delhi,Kolkata)!=1472)
    {
        distances=false;
        cout<<"    Distance between Delhi and Kolkata returned wrong\n";
    }  
    
    if(Railways::IndianRailways().GetDistances(Delhi,Chennai)!=2180)
    {
        distances=false;
        cout<<"    Distance between Delhi and Chennai returned wrong\n";
    }  
    if(Railways::IndianRailways().GetDistances(Delhi,Bangalore)!=2150)
    {
        distances=false;
        cout<<"    Distance between Delhi and Banglore returned wrong\n";
    }  
    if(Railways::IndianRailways().GetDistances(Mumbai,Kolkata)!=2014)
    {
        distances=false;
        cout<<"    Distance between Mumbai and Kolkata returned wrong\n";
    }  
    if(Railways::IndianRailways().GetDistances(Bangalore,Kolkata)!=1871)
    {
        distances=false;
        cout<<"    Distance between Banglore and Kolkata returned wrong\n";
    }  
    if(Railways::IndianRailways().GetDistances(Chennai,Kolkata)!=1659)
    {
        distances=false;
        cout<<"    Distance between Chennai and Kolkata returned wrong\n";
    }  
    if(Railways::IndianRailways().GetDistances(Bangalore,Mumbai)!=981)
    {
        distances=false;
        cout<<"    Distance between Banglore and Mumbai returned wrong\n";
    }  
    if(Railways::IndianRailways().GetDistances(Mumbai,Chennai)!=1338)
    {
        distances=false;
        cout<<"    Distance between Mumbai and Chennai returned wrong\n";
    }  
    if(Railways::IndianRailways().GetDistances(Chennai,Bangalore)!=350)
    {
        distances=false;
        cout<<"    Distance between Banglore and Chennai returned wrong\n";
    }  
    if(distances)    cout <<"    All distances returned right\n";

    try
    {
        int wrong_distance = Railways::IndianRailways().GetDistances(Mumbai,Station::CreateStation("Jaipur"));//Jaipur does not exist as a station in the master data
    }
    catch(Bad_Railways& e)
    {
        if (typeid(e).name() != typeid(Bad_Station).name())
            cout<<"    Bad staion name(station name repeated) exception handled wrong\n";
        else
            cout<<"    Bad station name(station name repeated) exception handled right\n";
    }
    try
    {
        int wrong_distance = Railways::IndianRailways().GetDistances(Mumbai,Mumbai);//Same station name cannot appear twice in a booking 
    }
    catch(Bad_Railways& e)
    {
        if (typeid(e).name() != typeid(Bad_Path).name())
            cout<<"    Bad staion name(station name repeated) exception handled wrong\n";
        else
            cout<<"    Bad station name(station name repeated) exception handled right\n";
    }
    

}