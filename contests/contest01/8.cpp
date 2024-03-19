#include <iostream>

int main() {
    int day, month, year;
    std::cin >> day >> month >> year;

    bool is_visokosny = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    day += 2;

    if (is_visokosny && month == 2) days_in_month[2] = 29;
    if (day > days_in_month[month]) {
        day -= days_in_month[month];
        month += 1;
    }
    if (month > 12) {
        month = 1;
        year += 1;
    }

    std::cout << day << " " << month << " " << year << std::endl;

    return 0;
}