#pragma once
#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include "IOperation.hpp"

class WcOperation final : public IOperation {
public:
    WcOperation() : IOperation() {}
    WcOperation(std::string& pipeline, std::shared_ptr<IOperation>&& operation=nullptr) : IOperation(std::move(operation)), pipeline_(pipeline) {}
    
    void ProcessLine(const std::string& str) override;
    void HandleEndOfInput() override;
    
private:
    std::string pipeline_;
};