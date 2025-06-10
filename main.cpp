#include <iostream>

#include "Handler.hpp"
#include "form_cor/EmailHandler.hpp"
#include "form_cor/NumberHandler.hpp"
#include "form_cor/TextHandler.hpp"

// Game plan:
// Make a very concrete cor for form validation
// Make as much of it generic
// Redo form validation with generic
// Make ATM money printer with generic

void testFormHandlerConcrete() {
    auto* mainHandler = new TextHandler();
    mainHandler->successor = new NumberHandler();
    mainHandler->successor->successor = new EmailHandler();
    FormInput form_input;
    form_input.input = "hello";
    form_input.inputType = TEXT_INPUT;

    std::cout << "We expect true" << mainHandler->handleRequest(form_input);
}

int doSomething() {
    std::cout<< "doSomething: Ummm what the sigma" << std::endl;
    return 7;
}
int doSomethingDifferent() {
    std::cout<< "doSomethingElse: This is painful" << std::endl;
    return 8;
}

bool alwaysDoSomething() {
    return true;
}
bool neverDoSomething() {
    return false;
}
int main() {
    auto handler    = std::make_unique<Handler<int>>(doSomething, alwaysDoSomething);
    auto handler2   = std::make_unique<Handler<int>>(doSomethingDifferent, alwaysDoSomething);
    auto handler3   = std::make_unique<Handler<int>>(doSomething, neverDoSomething);
    handler2->setSuccessor(std::move(handler3));
    handler->setSuccessor(std::move(handler2));
    handler->handleRequest();
    return 0;
}
