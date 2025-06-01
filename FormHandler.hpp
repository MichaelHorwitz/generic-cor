//
// Created by michael on 6/1/25.
//

#pragma once

#include "FormInput.hpp"

class FormHandler {
public:
    FormHandler* successor;
    virtual bool handleRequest(FormInput) = 0;
};
