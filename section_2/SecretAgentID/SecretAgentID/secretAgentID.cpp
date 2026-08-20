#include <fmt/base.h>
#include <iostream>
#include <string>

int main() {

    std::string fullName;
    std::string secretAlias;
    std::string ageInput;
    std::string agentLevelInput;
    std::string favoriteGadget;

    fmt::println("Please enter your full name:");
    std::getline(std::cin, fullName);

    fmt::println("Please enter your secret alias:");
    std::getline(std::cin, secretAlias);

    fmt::println("Please enter your age:");
    std::getline(std::cin, ageInput);
    int age = std::stoi(ageInput);

    fmt::println("Please enter your level:");
    std::getline(std::cin, agentLevelInput);
    int agentLevel = std::stoi(agentLevelInput);

    fmt::println("Please specify your favorite gadget:");
    std::getline(std::cin, favoriteGadget);

    fmt::println("");
    fmt::println("{:=^30}", "");
    fmt::println("S.E.C.R.E.T A.G.E.N.T");
    fmt::println("{:=^30}", "");
    fmt::println("Agent Name: {}", fullName);
    fmt::println("Alias: {}", secretAlias);
    fmt::println("Age: {}", age);
    fmt::println("Level: {}", agentLevel);
    fmt::println("Preferred Gadget: {}", favoriteGadget);
    fmt::println("{:=^30}", "");
    fmt::println("Mission Status: CLASSIFED");

    return 0;
}
