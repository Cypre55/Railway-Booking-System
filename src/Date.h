// ***** Header File for Date Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.1
// ***** Known bugs: None

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date {

    static const vector<string> sMonthNames;
    static const vector<string> sDayNames;

    enum Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
    enum Day { Mon, Tue, Wed, Thr, Fri, Sat, Sun };

    typedef unsigned int UINT;
    
    
    UINT date_; UINT month_; UINT year_;
    
    Date(UINT d, UINT m, UINT y);


    public:
    
    UINT GetDay() const;
    UINT GetMonth() const;
    UINT GetYear() const;

    static Date CreateDate(UINT d, UINT m, UINT y);

    friend ostream & operator << (ostream &out, const Date &date);

    bool CheckYearSpan(const Date& date) const;

    unsigned int GetAge() const;

    static bool ValidDate(unsigned int d, unsigned int m, unsigned int y);

    static void UnitTest();

    bool IsPast() const;

    Date(const Date &);

    ~Date();

};

#endif