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

