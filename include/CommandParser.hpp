#pragma once
#include <iostream>
#include <memory>
#include "IOperation.hpp"
#include "EchoOperation.hpp"
#include "CatOperation.hpp"

class OperationsList {
public:
    OperationsList() : head_(), tail_() {}
    // input копируем, так как в далньейшем в функции он будет меняться
    OperationsList(std::string input);

    void AddOperation(std::shared_ptr<IOperation>&& operation);
    void RunOperations();

private:
    const std::string delimiter = " | ";
    std::shared_ptr<IOperation> head_;
    std::shared_ptr<IOperation> tail_;
};