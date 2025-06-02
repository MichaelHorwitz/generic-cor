#pragma once
#include <functional>
#include <memory>

template <typename HandleReturnType>
class Handler {
protected:
    std::unique_ptr<Handler> successor_{nullptr};
    std::function<HandleReturnType()> foo_;

public:
    explicit Handler(std::function<HandleReturnType()> foo)
      : foo_{std::move(foo)}
    {}
    virtual HandleReturnType handleRequest() {
        HandleReturnType retVal = foo_();
        if (successor_) {
            successor_->handleRequest();
        }
        return retVal;
    }
    void setSuccessor(std::unique_ptr<Handler> successor) {
        successor_ = std::move(successor);
    }
};
