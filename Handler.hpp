#pragma once
#include <memory>


class Handler {
typedef std::unique_ptr<Handler> hdlrPtr; // NOLINT
    hdlrPtr successor;
public:

virtual ~Handler() = default;
explicit Handler() { successor = nullptr;};
    explicit Handler(hdlrPtr s) : successor(std::move(s)) { }
    virtual void handleRequest(int amount) { // NOLINT
        if (successor) {
            successor->handleRequest(amount);
        }
    };
    void setSuccessor(hdlrPtr s) {
        this->successor = std::move(s);
    };
    [[nodiscard]] Handler* getSuccessor() const {
        return successor.get();
    }
};
