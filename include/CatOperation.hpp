#pragma once
#include <iostream>
#include <memory>
#include <fstream>
#include "IOperation.hpp"

class CatOperation : public IOperation {
public:
    CatOperation() : IOperation() {}
    CatOperation(std::string& filename, std::shared_ptr<IOperation>&& operation=nullptr) : IOperation(std::move(operation)), filename_(filename) {}
    
    void ProcessLine(const std::string& str) override;
    void HandleEndOfInput() override;
    
private:
    std::string filename_;
};