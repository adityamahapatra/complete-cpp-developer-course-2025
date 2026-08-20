#include <iostream>
#include <string>

int main() {

    bool isSunny;
    bool isWarm;
    std::string input;

    std::cout << "It looks sunny out there." << std::endl;
    std::getline(std::cin, input);

    if (input.empty()) {
        std::cout << "No response received." << std::endl;
        return 1;
    }

    if (input == "true" || input == "1") {
        isSunny = true;
        std::cout << std::boolalpha << isSunny << ", it does look sunny." << std::endl;
    } else if (input == "false" || input == "0") {
        isSunny = false;
        std::cout << std::boolalpha << isSunny << ", check again." << std::endl;
    } else {
        std::cout << "Please enter a valid response." << std::endl;
    }

    std::cout << "Okay, is it warm?" << std::endl;
    std::getline(std::cin, input);

    if (input.empty()) {
        std::cout << "No response received." << std::endl;
        return 1;
    }

    if (input == "true" || input == "1") {
        isWarm = true;
        std::cout << std::boolalpha << isWarm << ", it is quite warm." << std::endl;
    } else if (input == "false" || input == "0") {
        isWarm = false;
        std::cout << std::boolalpha << isWarm << ", it's quite nice actually." << std::endl;
    } else {
        std::cout << "Please enter a valid response." << std::endl;
    }

    return 0;
}
