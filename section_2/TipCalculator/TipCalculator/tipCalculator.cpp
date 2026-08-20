#include <fmt/base.h>
#include <iostream>
#include <string>

int main() {

    std::string billAmountInput;
    std::string tipPercentageInput;
    double tipAmount;
    double totalAmount;

    fmt::println("Please enter the bill amount:");
    std::getline(std::cin, billAmountInput);

    fmt::println("Please enter the tip percentage:");
    std::getline(std::cin, tipPercentageInput);

    double billAmount = std::stod(billAmountInput);
    double tipPercentage = std::stod(tipPercentageInput);

    tipAmount = (billAmount * (tipPercentage / 100.0));
    totalAmount = billAmount + tipAmount;

    fmt::println("The total amount is: ${:.2f}", totalAmount);

    return 0;
}
