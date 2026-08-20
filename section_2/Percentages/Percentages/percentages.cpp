#include <fmt/ranges.h>
#include <iostream>
#include <string>

int main() {

    std::string fullName;
    std::string location;
    int initialScore;

    fmt::println("Please enter your full name: ");
    std::getline(std::cin, fullName);

    if (fullName.empty()) {
        fmt::println("Please provide a valid name.");
        return 1;
    }

    std::cout << "Please enter your location: " << std::endl;
    std::getline(std::cin, location);

    if (location.empty()) {
        fmt::println("Please provide a valid location.");
        return 1;
    }

    fmt::println("Please enter an initial score: ");
    std::cin >> initialScore;

    if (!std::cin) {
        fmt::println("Please enter a valid score.");
        return 1;
    }

    fmt::println("Hello, {}.", fullName);
    fmt::println("We heard you are from {}.", location);
    fmt::println("Your original score is {}, but with five points added, your score is {}.", initialScore,
                 initialScore + 5);

    fmt::println("Note: This file uses the <fmt> library for output.");

    return 0;
}
