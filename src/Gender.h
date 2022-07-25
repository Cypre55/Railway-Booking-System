// ***** Header File for Gender and GenderType Class
// ***** Author: Chappidi Yoga Satwik
// ***** Date: 08-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef GENDER_H
#define GENDER_H

#include <string>
using namespace std;

template<typename T>
class GenderTypes;

class Gender
{
    const string& name_;

    struct MaleType {};
    struct FemaleType {};

    protected:
    Gender(const string& name);
    virtual ~Gender();

    public:

    const string& GetName() const;

    typedef GenderTypes<MaleType> Male;
    typedef GenderTypes<FemaleType> Female;
    static void UnitTest();

    friend ostream& operator<<(ostream& cout,const Gender& other);
      
};

template<typename T>
class GenderTypes: public Gender
{
    static const string sName;

    GenderTypes(const string& name = GenderTypes<T>::sName);
    
    public:

    ~GenderTypes();

    static const GenderTypes<T>& Type();

};

template<typename T>
const GenderTypes<T>& GenderTypes<T>::Type() 
{
    static const GenderTypes<T> sObj;
    return sObj;
}

template<typename T>
GenderTypes<T>::GenderTypes(const string& name) : Gender(name) { }

template<typename T>
GenderTypes<T>::~GenderTypes() {}

#endif