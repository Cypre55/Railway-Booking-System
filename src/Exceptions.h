// ***** Header file for Exceptions Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
using namespace std;

class Bad_Booking : public exception {
    
};

class Invalid_Category : public Bad_Booking {
    public:
    virtual const char* what() const throw()
    {
        return "Bad_Booking exception: Invalid Category\n";
    }
};

class Invalid_Bdate : public Bad_Booking {
    public:
    virtual const char* what() const throw()
    {
        return "Bad_Booking exception: Invalid Date Of Travel\n";
    }
};

class Invalid_Stations : public Bad_Booking {
    public:
    virtual const char* what() const throw()
    {
        return "Bad_Booking exception: Invalid Path Of Travel\n";
    }
};

class Bad_Passenger : public exception {

};

class Bad_Disability : public Bad_Passenger {
    public:
    virtual const char* what() const throw()
    {
        return "Bad_Passenger exception: Disability Proofs not consistent\n";
    }
};

class Bad_Aadhaar : public Bad_Passenger {
    public:
    virtual const char* what() const throw()
    {
        return "Bad_Passenger exception: Wrong format of Aadhaar card Number\n";
    }
};

class Bad_Mobile : public Bad_Passenger {
    public:
    virtual const char* what() const throw()
    {
        return "Bad_Passenger exception: Wrong format of Mobile Number\n";
    }
};

class Bad_DOB : public Bad_Passenger {
    public:
    virtual const char* what() const throw()
    {
        return "Bad_Passenger exception: Invalid DOB entry\n";
    }
};

class Bad_Name : public Bad_Passenger {
    public:
    virtual const char* what() const throw()
    {
        return "Bad_Passenger exception: Incomplete Name Info\n";
    }
};

class Bad_Railways : public exception {
    
};

class Duplicate_Stations : public Bad_Railways {
    public:
    virtual const char* what() const throw()
    {
        return "Bad_Railways exception: Duplicate stations present in master data\n";
    }
};

class Bad_Station : public Bad_Railways {
    public:
    virtual const char* what() const throw()
    {
        return "Bad_Railways exception: Station does not exist\n";
    }
};

class Bad_Path : public Bad_Railways {
    public:
    virtual const char* what() const throw()
    {
        return "Bad_Railways exception: Path does not exist\n";
    }
};

class Duplicate_Stationpairs : public Bad_Railways {
    public:
    virtual const char* what() const throw()
    {
        return "Bad_Railways exception: Ambiguous distances between two pairs\n";
    }
};

class Bad_Date : public exception {

};

class Invalid_Format : public Bad_Date {
    public:
    virtual const char* what() const throw()
    {
        return "Bad_Date exception: Incorrect format of date entry\n";
    }
};

class Invalid_Date : public Bad_Date {
    public:
    virtual const char* what() const throw()
    {
        return "Bad_Date exception: Invalid date\n";
    }
};

class Bad_StationName : public Bad_Railways {
    public:
    virtual const char* what() const throw()
    {
        return "Bad_Station exception: Station name cannot be empty\n";
    }
};

#endif