#include <iostream>
#include <memory>

#include "HundredHandler.hpp"
#include "OneRandHandler.hpp"
#include "TwentyHandler.hpp"

int main() {
    auto hundredHandler = std::make_unique<HundredHandler>(
        std::make_unique<TwentyHandler>(
            std::make_unique<OneRandHandler>()
            ));
    hundredHandler->handleRequest(1234);
    return 0;
}
