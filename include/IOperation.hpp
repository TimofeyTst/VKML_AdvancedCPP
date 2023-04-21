#pragma once
#include <iostream>
#include <memory>

class IOperation {
public:
    IOperation() : next_operation_() {}
    IOperation(std::shared_ptr<IOperation>&& operation) : next_operation_(std::move(operation)) {}

    virtual void ProcessLine(const std::string& pipeline) = 0;
    virtual void HandleEndOfInput() = 0;
    virtual void SetNextOperation(std::shared_ptr<IOperation>&& operation);

    virtual ~IOperation() {}
    
    std::shared_ptr<IOperation> next_operation_;
};