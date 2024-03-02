/**
* Name: Prateek Panda
* Description: Time implementation that holds time information
* Date: <2/10/2024>
*/

#include "time.h"

Time::Time() {
    hour = 0;
    minute = 0;
    second = 0;
}

Time::Time(int hour, int minute, int second) {
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

Time::~Time()=default;

void Time::setHour(int hour) {
    this->hour = hour;
}

int Time::getHour() const {
    return hour;
}

void Time::setMinute(int minute) {
    this->minute = minute;
}

int Time::getMinute() const {
    return minute;
}

void Time::setSecond(int second) {
    this->second = second;
}

int Time::getSecond() const {
    return second;
}