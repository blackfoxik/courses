#include <string>
#include "calendar.h"

using namespace std;

bool isLeapYear(int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int daysInMonth(Month month, int year) {
    switch(month) {
        case APRIL:
        case JUNE:
        case SEPTEMBER:
        case NOVEMBER:
            return 30;
        case FEBRUARY:
            return (isLeapYear(year)) ? 29 : 28;
        default:
            return 31;
    }
}
 string monthToString(Month month) {
     switch (month) {
     case 1:
         return "JANUARY";
     case 2:
         return "FEBRUARY";
     case 3:
         return "MARCH";
     case 4:
         return "APRIL";
     case 5:
         return "MAY";
     case 6:
         return "JUNE";
     case 7:
         return "JULY";
     case 8:
         return "AUGUST";
     case 9:
         return "SEPTEMBER";
     case 10:
         return "OCTOBER";
     case 11:
         return "NOVEMBER";
     default:
         return "DECEMBER";
     }
 }
 Month operator ++(Month &month, int) {
     Month old = month;
     month = Month(month +1);
     return old;
 }

 Date::Date() {
     day = 1;
     month = JANUARY;
     year = 1900;
 }

 Date::Date(Month inputMonth, int inputDay, int inputYear) {
     day = inputDay;
     month = inputMonth;
     year = inputYear;
 }

 Date::Date(int inputDay, Month inputMonth, int inputYear) {
     day = inputDay;
     month = inputMonth;
     year = inputYear;
 }

 int Date::getDay() {
     return day;
 }

 int Date::getYear() {
     return year;
 }

 Month Date::getMonth() {
     return month;
 }

string toString(Date date) {
    return to_string(date.getDay()) + "-" + monthToString(date.getMonth()).substr(0,3) + "-" + to_string(date.getYear());
}

ostream &operator<< (ostream &os, Date date) {
    return os << toString(date);
}

bool operator ==(Date &date1, Date &date2) {
    return toString(date1) == toString(date2);
}

bool operator !=(Date &date1, Date &date2) {
    return !(date1 == date2);
}

bool operator <(Date &date1, Date &date2) {
    if (date1.getYear() < date2.getYear()) {
        return true;
    }
    else if(date1.getYear() > date2.getYear()) {
        return false;
    }
    else if(date1.getMonth() < date2.getMonth()) {
        return true;
    }
    else if(date1.getMonth() > date2.getMonth()) {
        return false;
    }
    else if(date1.getDay() < date2.getDay()) {
        return true;
    }
    else if(date1.getDay() >= date2.getDay()) {
        return false;
    }
    return false;
}

bool operator >(Date &date1, Date &date2) {
    return !( (date1 < date2) || (date1 == date2));
}

bool operator <=(Date &date1, Date &date2) {
    return ((date1 < date2) || (date1 == date2));
}

bool operator >=(Date &date1, Date &date2) {
    return ((date1 > date2) || (date1 == date2));
}
Date operator +(Date &date, int countDays) {
    Date dateAfterNDays = date;
    for (int i = 0; i < countDays; i++){
        dateAfterNDays++;
    }
    return dateAfterNDays;
}

Date operator ++(Date &date, int) {
    Date oldDate = date;
    int curDaysInMont = daysInMonth(date.getMonth(),date.getYear());

    if ((date.getDay() + 1) <= curDaysInMont) {
        Date newDate(date.getDay() + 1, date.getMonth(), date.getYear());
        date = newDate;
        //return newDate;
    }
    else if (date.getMonth() == DECEMBER) {
        Date newDate(1, JANUARY, date.getYear() + 1);
        date = newDate;
        //return newDate;
    }
    else {
        Date newDate(1, Month(date.getMonth()+1), date.getYear());
        date = newDate;
        //return newDate;
    }
    return oldDate;
}

Date operator ++(Date &date) {
    int curDaysInMont = daysInMonth(date.getMonth(),date.getYear());

    if ((date.getDay() + 1) <= curDaysInMont) {
        Date newDate(date.getDay() + 1, date.getMonth(), date.getYear());
        date = newDate;
        //return newDate;
    }
    else if (date.getMonth() == DECEMBER) {
        Date newDate(1, JANUARY, date.getYear() + 1);
        date = newDate;
        //return newDate;
    }
    else {
        Date newDate(1, Month(date.getMonth()+1), date.getYear());
        date = newDate;
        //return newDate;
    }
    return date;
}

Date operator -(Date &date, int countDays) {
    Date dateBeforeNDays = date;
    for (int i = 0; i < countDays; i++){
        dateBeforeNDays--;
    }
    return dateBeforeNDays;
}

Date operator --(Date &date, int) {
    Date oldDate = date;
    int curDaysInMont = daysInMonth(date.getMonth(),date.getYear());

    if((date.getDay() - 1) > 0) {
        Date newDate(date.getDay() - 1, date.getMonth(), date.getYear());
        date = newDate;
    }

    else if (((date.getDay() - 1) == 0) && (date.getMonth() != JANUARY)) {
        Month prevMonth = Month(date.getMonth() - 1);
        Date newDate(daysInMonth(prevMonth, date.getYear()), prevMonth, date.getYear());
        date = newDate;
        //return newDate;
    }

    if (((date.getDay() - 1) == 0) && (date.getMonth() == JANUARY)) {
        Date newDate(31, DECEMBER, date.getYear() -1);
        date = newDate;
        //return newDate;
    }

    return oldDate;
}

Date operator --(Date &date) {

    int curDaysInMont = daysInMonth(date.getMonth(),date.getYear());

    if((date.getDay() - 1) > 0) {
        Date newDate(date.getDay() - 1, date.getMonth(), date.getYear());
        date = newDate;
    }

    else if (((date.getDay() - 1) == 0) && (date.getMonth() != JANUARY)) {
        Month prevMonth = Month(date.getMonth() - 1);
        Date newDate(daysInMonth(prevMonth, date.getYear()), prevMonth, date.getYear());
        date = newDate;
        //return newDate;
    }

    if (((date.getDay() - 1) == 0) && (date.getMonth() == JANUARY)) {
        Date newDate(31, DECEMBER, date.getYear() -1);
        date = newDate;
        //return newDate;
    }

    return date;
}

int operator -(Date &date1, Date &date2) {
   Date dateBottom;
   Date dateUp;
   if (date1 == date2) {
       return 0;
   }
   else if (date1 > date2) {
       dateUp = date1;
       dateBottom = date2;


   }
   else {
       dateUp = date2;
       dateBottom = date1;

   }
   int countDays = 0;
   while(dateUp != dateBottom) {
       countDays++;
       dateBottom++;
   }
   return countDays;
}

Date operator +=(Date &date, int countDays) {
    return date = date + countDays;
}

Date operator -=(Date &date, int countDays) {
    return date = date - countDays;
}




