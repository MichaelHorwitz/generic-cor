#include <iostream>

#include "EmailHandler.hpp"
#include "NumberHandler.hpp"
#include "TextHandler.hpp"

// Game plan:
// Make a very concrete cor for form validation
// Make as much of it generic
// Redo form validation with generic
// Make ATM money printer with generic

int main() {
    TextHandler* mainHandler = new TextHandler();
    mainHandler->successor = new NumberHandler();
    mainHandler->successor->successor = new EmailHandler();
    FormInput form_input;
    form_input.input = "hello";
    form_input.inputType = TEXT_INPUT;

    std::cout << "We expect true" << mainHandler->handleRequest(form_input);
    return 0;
}
