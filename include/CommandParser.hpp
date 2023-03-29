#pragma once
#include <iostream>
#include "IOperation.hpp"

class OperationsList {
public:
    OperationsList() : head_(nullptr), tail_(nullptr) {}
    // input копируем, так как в далньейшем в функции он будет меняться
    OperationsList(std::string input);

    void AddOperation(IOperation* op);
    void RunOperations();

    virtual ~OperationsList();

private:
    std::string delimiter = " | ";
    IOperation* head_;
    IOperation* tail_;
};