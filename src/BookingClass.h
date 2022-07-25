// ***** Header File for BookingClass and BookingClassType Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef BOOKINGCLASS_H
#define BOOKINGCLASS_H

#include <string>
#include <iostream>
using namespace std;

template<typename T>
class BookingClassTypes;

class BookingClass
{
    struct SleeperType {};
    struct SecondSittingType {};
    struct FirstClassType {};
    struct ExecutiveChairType {};
    struct ACFirstClassType {};
    struct AC2TierType {};
    struct AC3TierType {};
    struct ACChairCarType {};

    protected:
    const string name_;

    BookingClass(const string& name);
    virtual ~BookingClass();

    public:

    string GetName() const;

    virtual double GetLoadFactor() const = 0;
    virtual bool IsSitting() const = 0;
    virtual bool IsAC() const = 0;
    virtual bool IsLuxury() const = 0;
    virtual unsigned int GetNumberOfTiers() const = 0;
    virtual unsigned int GetReservationCharge() const = 0;
    virtual double GetTatkalPercent() const = 0;
    virtual unsigned int GetMinTatkalCharge() const = 0;
    virtual unsigned int GetMaxTatkalCharge() const = 0;
    virtual unsigned int GetMinTatkalDistance() const = 0;
    
    // friend ostream & operator << (ostream &out, const BookingClass &bookingClass);
    friend ostream& operator << (ostream& cout, const BookingClass& other);

    typedef BookingClassTypes<SleeperType> Sleeper;
    typedef BookingClassTypes<SecondSittingType> SecondSitting;
    typedef BookingClassTypes<FirstClassType> FirstClass;
    typedef BookingClassTypes<ExecutiveChairType> ExecutiveChairCar;
    typedef BookingClassTypes<ACFirstClassType> ACFirstClass;
    typedef BookingClassTypes<AC2TierType> AC2Tier;
    typedef BookingClassTypes<AC3TierType> AC3Tier;
    typedef BookingClassTypes<ACChairCarType> ACChairCar;

};



template<typename T>
class BookingClassTypes : public BookingClass
{
    static double sLoadFactor;
    static bool sSitting;
    static bool sAC;
    static bool sLuxury;
    static unsigned int sNumberOfTiers;
    static unsigned int sReservationCharges; 
    static double sTatkalPercent;
    static unsigned int sMinTatkalCharge;
    static unsigned int sMaxTatkalCharge;
    static unsigned int sMinTatkalDistance;
    static const string sName;

    BookingClassTypes(const string& name = BookingClassTypes<T>::sName);
    virtual ~BookingClassTypes();

    public:

    double GetLoadFactor() const;
    bool IsSitting() const;
    bool IsAC() const;
    bool IsLuxury() const;
    unsigned int GetNumberOfTiers() const;
    unsigned int GetReservationCharge() const;
    double GetTatkalPercent() const;
    unsigned int GetMinTatkalCharge() const;
    unsigned int GetMaxTatkalCharge() const;
    unsigned int GetMinTatkalDistance() const;

    static const BookingClassTypes<T>& Type();

    static void UnitTest();
};

template<typename T>
BookingClassTypes<T>::BookingClassTypes(const string& name) : BookingClass(name)
{}

template<typename T>
BookingClassTypes<T>::~BookingClassTypes() {}

template<typename T>
const BookingClassTypes<T>& BookingClassTypes<T>::Type()
{
    static const BookingClassTypes<T> sObj;
    return sObj;
}

template<typename T>
double BookingClassTypes<T>::GetLoadFactor() const
{
    return sLoadFactor;
}

template<typename T>
bool BookingClassTypes<T>::IsSitting() const
{
    return sSitting;
}

template<typename T>
bool BookingClassTypes<T>::IsAC() const
{
    return sAC;
}

template<typename T>
bool BookingClassTypes<T>::IsLuxury() const
{
    return sLuxury;
}

template<typename T>
unsigned int BookingClassTypes<T>::GetNumberOfTiers() const
{
    return sNumberOfTiers;
}

template<typename T>
unsigned int BookingClassTypes<T>::GetReservationCharge() const
{
    return sReservationCharges;
}

template<typename T>
double BookingClassTypes<T>::GetTatkalPercent() const
{
    return sTatkalPercent;
}

template<typename T>
unsigned int BookingClassTypes<T>::GetMinTatkalCharge() const
{
    return sMinTatkalCharge;
}

template<typename T>
unsigned int BookingClassTypes<T>::GetMaxTatkalCharge() const
{
    return sMaxTatkalCharge;
}

template<typename T>
unsigned int BookingClassTypes<T>::GetMinTatkalDistance() const
{
    return sMaxTatkalCharge;
}

#endif