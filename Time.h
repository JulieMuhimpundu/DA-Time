#pragma once
#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
private:
    int days;
    int hours;
    int minutes;
    int seconds;

    void normalize(); // Ensures valid time (e.g., no 90 minutes, etc.)

public:
    Time();  // default
    Time(int d, int h, int m, int s);
    Time(int h, int m, int s);
    Time(int h, int m);
    Time(const Time& t);  // copy constructor

    // Getters
    int getDays() const;
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    // Overloaded operators
    Time& operator=(const Time& right);
    Time operator+(const Time& right) const;
    Time operator-(const Time& right) const;
    bool operator>(const Time& right) const;
    bool operator<(const Time& right) const;
    bool operator==(const Time& right) const;

    // Conversion to int (total seconds)
    operator int() const;

    // Output stream overload
    friend std::ostream& operator<<(std::ostream& out, const Time& t);
};

#endif
