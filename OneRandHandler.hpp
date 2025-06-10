#pragma once
#include <iostream>
#include "Handler.hpp"

class OneRandHandler : public Handler{
public:
    OneRandHandler(){ Handler();}
    explicit OneRandHandler(std::unique_ptr<Handler> next)
    : Handler(std::move(next)) {}
    void handleRequest(int amount) {
        while (amount >= 1) {
            amount -= 1;
            std::cout << "Gave R1 remaining amount: " << amount << std::endl;
        }
        Handler::handleRequest(amount);
    }
};