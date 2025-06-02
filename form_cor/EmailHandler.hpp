//
// Created by michael on 6/1/25.
//

#pragma once
#include "FormHandler.hpp"
class EmailHandler : public FormHandler {
    static bool isValidEmail(const std::string &) ;
public:
    bool handleRequest(FormInput) override;

};