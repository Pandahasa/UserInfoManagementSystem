/**
* Name: Prateek Panda
* Description: Header of DateTime which contains information of date and time
* Date: <2/10/2024>
*/

#include "time.h"
#include <iostream>
#include <sstream>


using namespace std;


#ifndef LAB1_MANAGEUSERACCS_DATETIME_H
#define LAB1_MANAGEUSERACCS_DATETIME_H

class DateTime : public Time {
public:
    DateTime();
    /**
     * DateTime constructor
     * @param month Month
     * @param day Day
     * @param year Year
     * @param hour Hour
     * @param minute Minute
     * @param second Second
     */
    DateTime(int month, int day, int year, int hour, int minute, int second);
    ~DateTime();

    //getter and setter methods, rest are in time.h
    void setMonth(int month);
    int getMonth() const;
    void setDay(int day);
    int getDay() const;
    void setYear(int year);
    int getYear() const;

    //outputs string version of date in month/day/year hour:minute:second
    string toString() const;
private:
    int month;
    int day;
    int year;
    Time time;
};


#endif //LAB1_MANAGEUSERACCS_DATETIME_H
