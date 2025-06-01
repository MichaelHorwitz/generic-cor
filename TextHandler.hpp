#pragma once
#include <string>

#include "FormHandler.hpp"

class TextHandler : public FormHandler{
    static bool isValidText(const std::string &);
public:
    bool handleRequest(FormInput) override;
};
