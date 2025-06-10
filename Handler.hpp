#pragma once
#include <functional>
#include <memory>
#include <vector>

template<typename returnType, typename... functionToDoArgs>
class Handler final {
    typedef std::unique_ptr<Handler> hdlrPtr; // NOLINT
    hdlrPtr successor;
    std::function<bool(functionToDoArgs...)> shouldDoFunction;
    std::function<returnType(functionToDoArgs...)> functionToDo;

public:
    virtual ~Handler() = default;

    explicit Handler() { successor = nullptr; };

    explicit Handler(hdlrPtr s) : successor(std::move(s)) {
    }

    explicit Handler(
    std::function<bool(functionToDoArgs...)> shouldDo,
    std::function<returnType(functionToDoArgs...)> toDo,
    hdlrPtr s = nullptr
    ) : shouldDoFunction(std::move(shouldDo)), functionToDo(std::move(toDo)), successor(std::move(s)) {}

    virtual std::vector<returnType> handleRequest(functionToDoArgs... args) { // NOLINT
        std::vector<returnType> returnVec;
        bool doFunction = shouldDoFunction(args...);
        if (doFunction) {
            returnVec.push_back(functionToDo(args...));
        }
        if (successor) {
            auto tailVec = successor->handleRequest(args...);
            // append
            returnVec.insert(returnVec.end(),
                           std::make_move_iterator(tailVec.begin()),
                           std::make_move_iterator(tailVec.end()));
        }
        return returnVec;
    };

    void setSuccessor(hdlrPtr s) {
        this->successor = std::move(s);
    };

    [[nodiscard]] Handler *getSuccessor() const {
        return successor.get();
    }
};
