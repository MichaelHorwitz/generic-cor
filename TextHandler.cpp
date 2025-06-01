//
// Created by michael on 6/1/25.
//

#include "TextHandler.hpp"

bool TextHandler::isValidText(const std::string & input) {
    return !input.empty();
}

bool TextHandler::handleRequest(FormInput form_input) {
    if (form_input.inputType == TEXT_INPUT || form_input.inputType == EMAIL_INPUT) {
        if (isValidText(form_input.input)) {
            return successor->handleRequest(form_input);
        }
        return false;
    }
    return successor->handleRequest(form_input);
}
