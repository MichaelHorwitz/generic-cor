#pragma once
#include <string>

#include "FormHandler.hpp"

class NumberHandler : public FormHandler{
    static bool isValidNumber(const std::string &);
public:
    bool handleRequest(FormInput) override;
};
