#pragma once
#include <iostream>
#include <memory>
#include "IOperation.hpp"

class EchoOperation : public IOperation {
public:
    EchoOperation() : IOperation() {}
    EchoOperation(std::string& str, std::shared_ptr<IOperation>&& operation=nullptr) : IOperation(std::move(operation)), str_(str) {}

    void ProcessLine(const std::string& str) override;
    void HandleEndOfInput() override;

private:
    std::string str_;
};