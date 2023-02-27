#include "ECPointerString.h"
using namespace std;

ECStringPtr::ECStringPtr() : ptr(NULL)
{
}

ECStringPtr::ECStringPtr(const string &strInit)
{
    ptr = new string(strInit);
}

ECStringPtr::ECStringPtr(const ECStringPtr &rhs)
{
    if (rhs.ptr != NULL)
    {
        ptr = new string(rhs.GetString());
    }
    else
    {
        ptr = NULL;
    }
}

ECStringPtr::ECStringPtr(ECStringPtr &&rhs)
{
    ptr = rhs.ptr;
    rhs.ptr = NULL;
}

ECStringPtr::~ECStringPtr()
{
    delete ptr;
}

ECStringPtr &ECStringPtr::operator=(const ECStringPtr &rhs)
{
    if (this != &rhs)
    {
        if (ptr != NULL)
        {
            delete ptr;
        }
        if (rhs.ptr != NULL)
        {
            ptr = new string(rhs.GetString());
        }
        else
        {
            ptr = NULL;
        }
    }
    return *this;
}

void ECStringPtr::SetString(const string &strToSet)
{
    if (ptr != NULL)
    {
        *ptr = strToSet;
    }
    else
    {
        ptr = new string(strToSet);
    }
}

std::string ECStringPtr ::GetString() const
{
    string str;
    if (ptr != NULL)
    {
        str = *ptr;
    }
    return str;
}

const string *ECStringPtr::GetPtr() const
{
    return ptr;
}

ECStringPtr ECStringPtr::Duplicate() const
{
    ECStringPtr strDup;
    if (ptr != NULL)
    {
        strDup.SetString(*ptr + *ptr);
    }
    return strDup;
}