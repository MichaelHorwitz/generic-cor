#include "EmailHandler.hpp"
#include <regex>

bool EmailHandler::isValidEmail(const std::string &email) {
    const std::regex pattern(R"((\w+)(\.\w+)*@(\w+)(\.\w+)+)");
    return std::regex_match(email, pattern);
}

bool EmailHandler::handleRequest(const FormInput form_input) {
    if (form_input.inputType == EMAIL_INPUT) {
        return isValidEmail(form_input.input);
    }
    if (successor) {
        return successor->handleRequest(form_input);
    }
    return true;
}
