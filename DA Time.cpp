

/*=== Time to Integer Conversion Test ===
Time: 1d 02h:30m:15s
Total seconds: 95415

t1 = 0d 01h:30m:45s
t2 = 0d 02h:10m:30s
t1 + t2 = 0d 03h:41m:15s
t2 - t1 = 0d 00h:39m:45s
t1 > t2: 0
t1 < t2: 1
t1 == t1: 1
*/



#include <iostream>
#include "Time.h"

void testTimeIntegerConversion() {
    std::cout << "=== Time to Integer Conversion Test ===\n";
    Time t1(1, 2, 30, 15); // 1 day, 2 hours, 30 minutes, 15 seconds
    std::cout << "Time: " << t1 << "\n";
    int seconds = t1;
    std::cout << "Total seconds: " << seconds << "\n\n";
}

void testAll() {
    Time t1(0, 1, 30, 45);
    Time t2(0, 2, 10, 30);

    std::cout << "t1 = " << t1 << "\n";
    std::cout << "t2 = " << t2 << "\n";

    Time sum = t1 + t2;
    std::cout << "t1 + t2 = " << sum << "\n";

    Time diff = t2 - t1;
    std::cout << "t2 - t1 = " << diff << "\n";

    std::cout << "t1 > t2: " << (t1 > t2) << "\n";
    std::cout << "t1 < t2: " << (t1 < t2) << "\n";
    std::cout << "t1 == t1: " << (t1 == t1) << "\n";
}

int main() {
    testTimeIntegerConversion();
    testAll();
    return 0;
}

