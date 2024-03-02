/**
* Name: Prateek Panda
* Description: Time class header which contains all information for time
* Date: <2/10/2024>
*/

#ifndef LAB1_MANAGEUSERACCS_TIME_H
#define LAB1_MANAGEUSERACCS_TIME_H


class Time {
public:
    Time();
    /**
     * Time constructor
     * @param hour Hour
     * @param minute Minute
     * @param second Second
     */
    Time(int hour, int minute, int second);
    ~Time();
    //getter and setter methods
    void setHour(int hour);
    int getHour() const;
    void setMinute(int minute);
    int getMinute() const;
    void setSecond(int second);
    int getSecond() const;
private:
    int hour;
    int minute;
    int second;
};


#endif //LAB1_MANAGEUSERACCS_TIME_H
