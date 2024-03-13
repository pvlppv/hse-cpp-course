///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       14.02.2024
///
/// TASK DESCRIPTION
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
/*
Describe the “Time” structure with three fields: hours, minutes
and seconds. Define a subtraction operation such that
the result is an object of type time containing
how much time is between the first and second event. If
the second event is later than the first, the answer should be equal to
zero, otherwise return a time structure containing the difference
between these events (hours, minutes, seconds).
*/

struct Time {
    int hours;
    int minutes;
    int seconds;
    Time(int h1, int m1, int s1, int h2, int m2, int s2) {
        int total_s1 = h1 * 3600 + m1 * 60 + s1;
        int total_s2 = h2 * 3600 + m2 * 60 + s2;
        int diff = std::max(0, total_s1 - total_s2);
        hours = diff / 3600;
        minutes = (diff % 3600) / 60;
        seconds = diff % 60;
    }

    void print(){
        std::cout << hours << ':' << minutes << ':' << seconds << std::endl;;
    }
};

int main() {
    Time Time1(1, 30, 30, 2, 30, 30);
    Time1.print();
    return 0;
}