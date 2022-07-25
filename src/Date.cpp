// ***** Implementation for Date Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include "Date.h"
#include <ctime>
#include "Exceptions.h"

typedef unsigned int UINT;

// Defining Static month names
const vector<string> sMonthNames = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

// Defining Static day names
const vector<string> sDayNames = { "Monday", "Tuesday", "Wednesday", "Thursday",
    "Friday", "Saturday", "Sunday" };

// Constructor
Date::Date(UINT d, UINT m, UINT y) : date_(d), month_(m), year_(y)
{ }

// Output Stream operator
ostream & operator << (ostream &out, const Date &date)
{
    out << date.date_ << "/";
    out << sMonthNames[date.month_ - 1] << "/";
    out << date.year_ << endl;

    return out;

}

// Copy Constructor
Date::Date(const Date &date) : date_(date.date_), month_(date.month_), year_(date.year_)
{ }

// Destructor
Date::~Date() { }

bool Date::CheckYearSpan(const Date& date) const
{
    unsigned int d=date.GetDay();
    unsigned int m=date.GetMonth();
    unsigned int y=date.GetYear();
    
    if (y > year_ + 1)
        return false;
    else if (y == year_ + 1)
    {
        if (m < month_)
            return true;
        else if (m == month_)
        {
            if (d <= date_)
                return true;
            else
                return false;
        }
        else {
            return false;
        }
    }
    else if (y == year_)
    {
        if (m > month_)
            return true;
        else if (m == month_)
        {
            if (d >= date_)
                return true;
            else
                return false;
        }
    }
    else if (y < year_)
        return false;
}

unsigned int Date::GetAge() const
{
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    unsigned int d=now->tm_mday;
    unsigned int m=now->tm_mon+1;
    unsigned int y=now->tm_year + 1900;
    return y-year_;
}

bool Date::ValidDate(unsigned int d, unsigned int m, unsigned int y)
{
    if( y <1900 ||y>2099 )
		throw Invalid_Date();
		
	if( m <= 0 || m > 12)
		throw Invalid_Date();
	
	if( m == 2)
	{	
		if ( y % 4 == 0 )
		{
				if( d > 29 || d <=0) 
					throw Invalid_Date();
		}
		else
		{
				if( d > 28 || d <=0) 
					throw Invalid_Date();
		}
	}
	else if( m == 1 || m == 3 || m  == 5 || m == 7 || m == 8 || m == 10 || m == 12 )
	{
		if( d > 31 || d <= 0) 
			throw Invalid_Date();
	}
	else
	{
		if( d > 30 || d <= 0) 
			throw Invalid_Date();
	}
}

bool Date::IsPast() const
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    unsigned int d=now->tm_mday;
    unsigned int m=now->tm_mon+1;
    unsigned int y=now->tm_year + 1900;
    if(year_>y) return false;
    if(year_==y){
        if(month_>m) return false;
        else if(month_==m&&date_>=d) return false;
    }
    return true;
}

unsigned int Date::GetDay() const
{
    return date_;
}

unsigned int Date::GetMonth() const
{
    return month_;
}

unsigned int Date::GetYear() const
{
    return year_;
}

Date Date::CreateDate(unsigned int d, unsigned int m, unsigned int y)
{
    // if (ValidDate(d, m, y) == false) {
    //     throw Invalid_Date();
    // }
    return Date(d, m, y);
}

void Date::UnitTest()
{
    cout<<"\n\n+++Unit Testing Date Class+++\n";
    Date d1(1,1,2000);
    if( d1.date_==1 && d1.month_ == 1 && d1.year_ == 2000)
        cout<<"    Constructor with integer arguments working\n";
    else
        cout<<"    Constructor with integer arguments not working\n";

    Date d3 = Date::CreateDate(12, 12, 2041);
    if( d3.date_==12 && d3.month_ == 12 && d3.year_ == 2021)
        cout<<"    CreateDate() with string working\n";
    else
        cout<<"    CreateDate() with string not working\n";
    if (d3.CheckYearSpan(d1) == false)
        cout<<"    CheckYearSpan() working right\n";
    else
        cout<<"    CheckYearSpan() working wrong\n";

    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    unsigned int y=now->tm_year + 1900;
    if(d1.GetAge()==y-d1.year_)
        cout<<"    GetAge() working right\n";
    else
        cout<<"    GetAge() working wrong\n";
    if (d3.IsPast() == false and d1.IsPast() == true)
        cout<<"    IsPast() working right\n";
    else
        cout<<"    IsPast() working wrong\n";

    try
    {
        Date d5 = Date::CreateDate(30, 2, 2025);//Invalid date
    }
    catch(Bad_Date& e)
    {
        if (typeid(e).name() != typeid(Invalid_Date).name())
            cout<<"    Bad date(invalid date) exception handled wrong\n";
        else
            cout<<"    Bad date(invalid date) exception handled right\n";
    }
}