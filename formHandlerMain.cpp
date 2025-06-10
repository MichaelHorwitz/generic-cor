#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <functional>
#include "Handler.hpp"

struct Field {
    std::string name;
    std::string value;
    std::string type;
};

struct Section {
    std::string name;
    std::vector<Field> fields;
};

struct Form {
    std::vector<Section> sections;
};

bool isValidSAID(const std::string& id) {
    if (id.size() != 13 || !std::all_of(id.begin(), id.end(), ::isdigit)) return false;
    int sum = 0;
    for (int i = 0; i < 12; ++i) {
        int digit = id[i] - '0';
        if (i % 2 == 0) {
            sum += digit;
        } else {
            int dbl = digit * 2;
            sum += (dbl / 10) + (dbl % 10);
        }
    }
    int checkDigit = (10 - (sum % 10)) % 10;
    return checkDigit == (id[12] - '0');
}

int main() {
    Form form {
        {
            { "User Details", {
                { "Email",        "john.doe@example.com",    "email" },
                { "ID Number",    "8001015009087",          "id"    }
            }},
            { "Billing Details", {
                { "Email",        "billing@company.co.za",   "email" },
                { "ID Number",    "abcdef",                  "id"    }
            }}
        }
    };

    auto emailFormatHandler = std::make_unique<Handler<std::string, Field&>>(
        [](Field& f){ return true; },
        [](Field& f){
            auto at  = f.value.find('@');
            auto dot = f.value.find('.', at);
            if (at == std::string::npos || dot == std::string::npos) {
                return std::string("Invalid email format");
            }
            return std::string("");
        }
    );
    auto alnumEmailHandler = std::make_unique<Handler<std::string, Field&>>(
        [](Field& f){ return true; },
        [](Field& f){
            if (!std::all_of(f.value.begin(), f.value.end(), [](char c){ return std::isalnum(c) || c=='@' || c=='.'; })) {
                return std::string("Email contains invalid characters");
            }
            return std::string("");
        },
        std::move(emailFormatHandler)
    );

    auto idChecksumHandler = std::make_unique<Handler<std::string, Field&>>(
        [](Field& f){ return std::all_of(f.value.begin(), f.value.end(), ::isdigit); },
        [](Field& f){
            return isValidSAID(f.value) ? std::string("") : std::string("Invalid ID checksum");
        }
    );
    auto numericHandler = std::make_unique<Handler<std::string, Field&>>(
        [](Field& f){ return true; },
        [](Field& f){
            if (!std::all_of(f.value.begin(), f.value.end(), ::isdigit)) {
                return std::string("ID must be numeric");
            }
            return std::string("");
        },
        std::move(idChecksumHandler)
    );

    for (auto& section : form.sections) {
        std::cout << "Section: " << section.name << "\n";
        for (auto& field : section.fields) {
            std::cout << " Validating " << field.name << " (" << field.value << ")\n";
            auto errors = (field.type == "email")
                ? alnumEmailHandler->handleRequest(field)
                : numericHandler->handleRequest(field);

            bool hasError = false;
            for (auto& e : errors) {
                if (!e.empty()) {
                    std::cout << "  Error: " << e << "\n";
                    hasError = true;
                }
            }
            if (!hasError) {
                std::cout << "  Valid\n";
            }
        }
    }
    return 0;
}
