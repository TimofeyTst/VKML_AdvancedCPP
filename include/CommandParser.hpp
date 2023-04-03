#pragma once
#include <iostream>
#include <memory>
#include <string>
#include "IOperation.hpp"
#include "EchoOperation.hpp"
#include "CatOperation.hpp"

class OperationsList {
public:
    OperationsList() : head_(), tail_() {}
    // input копируем, так как в далньейшем в функции он будет меняться
    OperationsList(const std::string& input);

    void AddOperation(std::shared_ptr<IOperation>&& operation);
    void AddOperation(const std::string& token);
    void RunOperations();

private:
    const std::string delimiter = " | ";
    std::shared_ptr<IOperation> head_;
    std::shared_ptr<IOperation> tail_;
};