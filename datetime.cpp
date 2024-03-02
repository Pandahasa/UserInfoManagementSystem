/**
* Name: Prateek Panda
* Description: Contains information of the date and time and formats it
* Date: <2/10/2024>
*/
#include "datetime.h"

DateTime::DateTime() {
    month = 0;
    day = 0;
    year = 0;
}

DateTime::DateTime(int month, int day, int year, int hour, int minute, int second) : Time(hour, minute, second) {
    this->month = month;
    this->day = day;
    this->year = year;
}

DateTime::~DateTime()=default;

void DateTime::setMonth(int month) {
    this->month = month;
}

int DateTime::getMonth() const {
    return month;
}

void DateTime::setDay(int day) {
    this->day = day;
}

int DateTime::getDay() const {
    return day;
}

void DateTime::setYear(int year) {
    this->year = year;
}

int DateTime::getYear() const {
    return year;
}

string DateTime::toString() const {
    stringstream ss;
    ss << month << "/" << day << "/" << year << " " << getHour();
    ss << ":" << getMinute() << ":" << getSecond();
    return ss.str();
}