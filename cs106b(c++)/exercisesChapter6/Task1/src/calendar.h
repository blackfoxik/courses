#ifndef _calendar_h
#define _calendar_h
#include <iostream>
#include <string>
using namespace std;

enum Month { JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };

int daysInMonth(Month month, int year);
bool isLeapYear(int year);
string monthToString(Month month);
Month operator ++(Month &month, int);

class Date {
    public:
        Date();
        Date(Month inputMonth, int inputDay, int inputYear);
        Date(int inputDay, Month inputMonth, int inputYear);
        int getDay();
        Month getMonth();
        int getYear();
    private:
        int year;
        Month month;
        int day;

};

string toString(Date date);
ostream &operator<< (ostream &os, Date date);
bool operator ==(Date &date1, Date &date2);
bool operator !=(Date &date1, Date &date2);
bool operator <(Date &date1, Date &date2);
bool operator >(Date &date1, Date &date2);
bool operator <=(Date &date1, Date &date2);
bool operator >=(Date &date1, Date &date2);
Date operator +(Date &date, int countDays);
Date operator +=(Date &date, int countDays);
Date operator -=(Date &date, int countDays);
Date operator ++(Date &date, int);
Date operator ++(Date &date);
Date operator -(Date &date, int countDays);
int operator -(Date &date1, Date &date2);
Date operator --(Date &date, int);
Date operator --(Date &date);

#endif
