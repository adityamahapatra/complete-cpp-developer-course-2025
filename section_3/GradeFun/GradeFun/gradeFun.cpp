/* Use this file as the template to start new exercises. */

#include <fmt/base.h>
#include <iostream>

int main() {

    char grade;

    fmt::println("Enter your letter grade [A-F]:");
    std::cin >> grade;

    switch (grade) {
    case 'A':
    case 'a':
        fmt::println("Great job!");
        break;
    case 'B':
    case 'b':
        fmt::println("Good job!");
        break;
    case 'C':
    case 'c':
        fmt::println("You can do better!");
        break;
    case 'D':
    case 'd':
        fmt::println("You're getting pretty close to failing.");
        break;
    case 'F':
    case 'f':
        fmt::println("You are failing the course!");
        break;
    default:
        fmt::println("You've entered an invalid grade. Try again.");
    }

    return 0;
}
