#pragma once
#include <iostream>
#include "IOperation.hpp"

class OperationsList {
public:
    OperationsList() : head_(nullptr), tail_(nullptr) {}
    OperationsList(std::string input);

    void AddOperation(IOperation* op);
    void RunOperations();

    virtual ~OperationsList();

private:
    std::string delimiter = " | ";
    IOperation* head_;
    IOperation* tail_;
};