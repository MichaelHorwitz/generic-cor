#include <iostream>
#include <memory>
#include "Handler.hpp"

void doDeduction (int& amount, int amountToCheck) {
    while (amount >= amountToCheck) {
        amount -= amountToCheck;
        std::cout << "Gave R" << amountToCheck << " remaining amount: " << amount << std::endl;
    }
}

bool shouldDo(const int& amount, const int amountToCheck) {
    return amount >= amountToCheck;
}

void do100 (int& amount) {
    doDeduction(amount, 100);
}

bool shouldDo100 (const int& amount) {
    return shouldDo(amount, 100);
}

void do20 (int& amount) {
    doDeduction(amount, 20);
}

bool shouldDo20 (const int& amount) {
    return shouldDo(amount, 20);
}

void do1 (int& amount) {
    doDeduction(amount, 1);
}

bool shouldDo1 (const int& amount) {
    return shouldDo(amount, 1);
}

int main() {
    auto hundredsHandler =
        Handler<int&>(shouldDo100, do100,
        std::make_unique<Handler<int&>>(shouldDo20, do20,
            std::make_unique<Handler<int&>>(shouldDo1, do1)));
    int currAmount = 1234;
    hundredsHandler.handleRequest(currAmount);
    return 0;
}