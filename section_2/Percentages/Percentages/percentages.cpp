#include <fmt/ranges.h>
#include <iostream>
#include <string>

int main() {

    std::string fullName;
    std::string location;
    int initialScore;

    std::cout << "Please enter your full name: " << std::endl;
    std::getline(std::cin, fullName);

    if (fullName.empty()) {
        std::cout << "Please provide a valid name." << std::endl;
        return 1;
    }

    std::cout << "Please enter your location: " << std::endl;
    std::getline(std::cin, location);

    if (location.empty()) {
        std::cout << "Please provide a valid location." << std::endl;
        return 1;
    }

    std::cout << "Please enter an initial score: " << std::endl;
    std::cin >> initialScore;

    if (!std::cin) {
        std::cout << "Please enter a valid score." << std::endl;
        return 1;
    }

    std::cout << "Hello, " << fullName << std::endl;
    std::cout << "We heard you are from " << location << std::endl;
    std::cout << "Your original score is " << initialScore << ", but with five points added, your score is "
              << initialScore + 5 << std::endl;

    return 0;
}
