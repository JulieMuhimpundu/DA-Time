#include "Time.h"
#include <iomanip>

Time::Time() : days(0), hours(0), minutes(0), seconds(0) {}

Time::Time(int d, int h, int m, int s) : days(d), hours(h), minutes(m), seconds(s) {
    normalize();
}

Time::Time(int h, int m, int s) : days(0), hours(h), minutes(m), seconds(s) {
    normalize();
}

Time::Time(int h, int m) : days(0), hours(h), minutes(m), seconds(0) {
    normalize();
}

Time::Time(const Time& t) {
    days = t.days;
    hours = t.hours;
    minutes = t.minutes;
    seconds = t.seconds;
}

void Time::normalize() {
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
    if (hours >= 24) {
        days += hours / 24;
        hours %= 24;
    }
}

int Time::getDays() const { return days; }
int Time::getHours() const { return hours; }
int Time::getMinutes() const { return minutes; }
int Time::getSeconds() const { return seconds; }

Time& Time::operator=(const Time& right) {
    if (this != &right) {
        days = right.days;
        hours = right.hours;
        minutes = right.minutes;
        seconds = right.seconds;
    }
    return *this;
}

Time Time::operator+(const Time& right) const {
    Time sum;
    sum.seconds = seconds + right.seconds;
    sum.minutes = minutes + right.minutes;
    sum.hours = hours + right.hours;
    sum.days = days + right.days;
    sum.normalize();
    return sum;
}

Time Time::operator-(const Time& right) const {
    int total1 = static_cast<int>(*this);
    int total2 = static_cast<int>(right);
    int diff = total1 - total2;

    Time result;
    result.days = diff / 86400;
    diff %= 86400;
    result.hours = diff / 3600;
    diff %= 3600;
    result.minutes = diff / 60;
    result.seconds = diff % 60;

    return result;
}

bool Time::operator>(const Time& right) const {
    return static_cast<int>(*this) > static_cast<int>(right);
}

bool Time::operator<(const Time& right) const {
    return static_cast<int>(*this) < static_cast<int>(right);
}

bool Time::operator==(const Time& right) const {
    return static_cast<int>(*this) == static_cast<int>(right);
}

Time::operator int() const {
    return seconds + (minutes * 60) + (hours * 3600) + (days * 86400);
}

std::ostream& operator<<(std::ostream& out, const Time& t) {
    out << t.days << "d "
        << std::setw(2) << std::setfill('0') << t.hours << "h:"
        << std::setw(2) << std::setfill('0') << t.minutes << "m:"
        << std::setw(2) << std::setfill('0') << t.seconds << "s";
    return out;
}
