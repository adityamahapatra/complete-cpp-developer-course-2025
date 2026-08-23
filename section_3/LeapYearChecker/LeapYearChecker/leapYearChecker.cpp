#include <fmt/base.h>
#include <iostream>

bool isLeapYear(const int& year) {
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 == 0 && year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}

int main() {

    int startingYear{};
    int endingYear{};

    fmt::println("Welcome to the Leap Year Checker!");

    fmt::print("Enter the starting year: ");
    std::cin >> startingYear;

    fmt::print("Enter the ending year: ");
    std::cin >> endingYear;

    for (int year = startingYear; year <= endingYear; year++) {
        if (!isLeapYear(year)) {
            fmt::println("{} is not a leap year.", year);
        } else {
            fmt::println("{} is a leap year.", year);
        }
    }

    return 0;
}
