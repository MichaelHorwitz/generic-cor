#pragma once
#include <functional>
#include <memory>

template <typename HandleReturnType>
class Handler {
protected:
    std::unique_ptr<Handler> successor_{nullptr};
    std::function<HandleReturnType()> doSomething_;
    std::function<bool()> shouldDoSomething_;

public:
    explicit Handler(std::function<HandleReturnType()> foo, std::function<bool()> should_do_something_) {
        this->doSomething_ = std::move(foo);
        this->shouldDoSomething_ = std::move(should_do_something_);
    };
    virtual HandleReturnType handleRequest() {
        bool shouldDoSomethingVar = shouldDoSomething_();
        HandleReturnType retVal;
        if (shouldDoSomethingVar) {
            retVal = doSomething_();
        }
        if (successor_) {
            successor_->handleRequest();
        }
        return retVal;
    }
    void setSuccessor(std::unique_ptr<Handler> successor) {
        successor_ = std::move(successor);
    }
    auto getSuccessor() {
        return successor_;
    }
};
