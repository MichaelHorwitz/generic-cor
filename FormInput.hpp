//
// Created by michael on 6/1/25.
//
#pragma once
#include <string>

enum InputType {
    EMAIL_INPUT,
    TEXT_INPUT,
    NUMBER_INPUT,
};

class FormInput {
public:
    InputType inputType;
    std::string input;
};