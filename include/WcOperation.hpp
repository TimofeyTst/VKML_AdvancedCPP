#pragma once
#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include "IOperation.hpp"

class WcOperation final : public IOperation {
public:
    WcOperation() : IOperation() {}
    WcOperation(std::string& str, std::shared_ptr<IOperation>&& operation=nullptr) : IOperation(std::move(operation)), str_(str) {}
    
    void ProcessLine(const std::string& pipeline) override;
    void HandleEndOfInput() override;
    
private:
    std::string str_;
};