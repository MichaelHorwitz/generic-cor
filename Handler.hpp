#pragma once
#include <functional>
#include <memory>

template<typename request,typename... functionToDoArgs>
class Handler final {
    typedef std::unique_ptr<Handler> hdlrPtr; // NOLINT
    hdlrPtr successor;
    std::function<bool(functionToDoArgs...)> shouldDoFunction;
    std::function<request(functionToDoArgs...)> functionToDo;

public:
    virtual ~Handler() = default;

    explicit Handler() { successor = nullptr; };

    explicit Handler(hdlrPtr s) : successor(std::move(s)) {
    }

    explicit Handler(
    std::function<bool(functionToDoArgs...)> shouldDo,
    std::function<request(functionToDoArgs...)> toDo,
    hdlrPtr s = nullptr
    ) : shouldDoFunction(std::move(shouldDo)), functionToDo(std::move(toDo)), successor(std::move(s)) {}

    virtual request handleRequest(functionToDoArgs... args) { // NOLINT
        bool doFunction = shouldDoFunction(args...);
        if (doFunction) {
            functionToDo(args...);
        }
        if (successor) {
            successor->handleRequest(args...);
        }
    };

    void setSuccessor(hdlrPtr s) {
        this->successor = std::move(s);
    };

    [[nodiscard]] Handler *getSuccessor() const {
        return successor.get();
    }
};
