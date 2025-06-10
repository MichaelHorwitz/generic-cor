#pragma once
#include <iostream>
#include "Handler.hpp"

class TwentyHandler : public Handler {
    int numberOfNotes = 20;

public:
    TwentyHandler() { Handler(); }

    explicit TwentyHandler(std::unique_ptr<Handler> next)
        : Handler(std::move(next)) {
    }

    void handleRequest(int amount) override {
        while (amount >= 20) {
            amount -= 20;
            std::cout << "Gave R20 remaining amount: " << amount << std::endl;
            numberOfNotes--;
        }
        Handler::handleRequest(amount);
    }
};
