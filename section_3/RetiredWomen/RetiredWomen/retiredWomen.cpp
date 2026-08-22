#include <fmt/base.h>
#include <iostream>

int main() {

    char gender;
    int age;

    fmt::println("What is your age?");
    std::cin >> age;

    if (age < 60) {
        fmt::println("You're ineligible");
        return 0;
    }

    fmt::println("Please enter your gender? (M/F)");
    std::cin >> gender;

    if (gender != 'f' && gender != 'F') {
        if (gender == 'm' || gender == 'M') {
            fmt::println("You're ineligible");
            return 0;
        } else {
            fmt::println("Please enter a valid gender.");
            return 0;
        }
    }

    fmt::println("You're eligible.");

    return 0;
}
