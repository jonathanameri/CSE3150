#include "ECTime.h"

ECTime:: ECTime(int h, int m, int s) : hour(h), min(m), sec(s)
{}


ECTime :: ~ECTime() {}

void ECTime :: GetTime(int &h, int &m, int &s) const{
    h=hour;
    m=min;
    s=sec;
}

ECTime ECTime :: operator+(const ECTime &tmToAdd)
{
    ECTime res(0, 0, 0);
    res.sec = this->sec + tmToAdd.sec;
    res.min = this->min + tmToAdd.min;
    res.min += res.sec / 60;
    res.sec %= 60;
    res.hour = this->hour + tmToAdd.hour;
    res.hour += res.min / 60;
    res.min %= 60;

    return res;
}
