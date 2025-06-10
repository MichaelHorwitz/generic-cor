#pragma once
#include <iostream>
#include "Handler.hpp"

class HundredHandler final : public Handler{
public:
    HundredHandler() {
        Handler();
    }
    explicit HundredHandler(std::unique_ptr<Handler> next)
        : Handler(std::move(next)) {}
    void handleRequest(int amount) override {
        while (amount >= 100) {
            amount -= 100;
            std::cout << "Gave R100 remaining amount: " << amount << std::endl;
        }
        Handler::handleRequest(amount);
    }
};
