#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

Date::Date()
{
    time_t rawtime;
    time(&rawtime);
    struct tm* timeinfo;
    timeinfo = localtime(&rawtime);
    day = timeinfo->tm_mday;
    month = timeinfo->tm_mon + 1;
    year = timeinfo->tm_year + 1900;
}

Date::Date(string d)
{
    stringstream ss(d);
    char tmp;
    ss >> this->day >> tmp >> this->month >> tmp >> this->year;
}

string Date::toString() {
    stringstream res;
    res << this->day << "/" << this->month << "/" << this->year;
    return res.str();
}

istream& operator>>(istream& is, Date& D)
{
    char tmp;
    is >> D.day >> tmp >> D.month >> tmp >> D.year;
    return is;
}

ostream& operator<<(ostream& os, const Date& D)
{
    stringstream res;
    res << D.day << "/" << D.month << "/" << D.year;
    os << res.str();
    return os;
}

Date::~Date()
{
}