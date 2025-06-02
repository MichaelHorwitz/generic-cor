//
// Created by michael on 6/1/25.
//

#include "NumberHandler.hpp"
bool NumberHandler::isValidNumber(const std::string & input) {
    try {
        std::stoi(input);
        return true;
    } catch (int _) {
        return false;
    }
}
bool NumberHandler::handleRequest(const FormInput form_input) {
    if (form_input.inputType == NUMBER_INPUT) {
        return isValidNumber(form_input.input);
    }
    return successor->handleRequest(form_input);
}

