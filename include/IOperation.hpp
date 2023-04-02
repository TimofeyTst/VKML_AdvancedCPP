#pragma once
#include <iostream>
#include <fstream>

class IOperation {
public:
    IOperation() : next_operation_(nullptr) {}
    IOperation(IOperation * op) : next_operation_(op) {}

    virtual void ProcessLine(const std::string& str) = 0;
    virtual void HandleEndOfInput() = 0;
    virtual void SetNextOperation(IOperation* operation);

    virtual ~IOperation() {}
    
    IOperation* next_operation_;
};

class EchoOperation : public IOperation {
public:
    EchoOperation() : IOperation(nullptr) {}
    EchoOperation(std::string& str, IOperation* operation = nullptr) : IOperation(operation), str_(str) {}

    void ProcessLine(const std::string& str) override;
    void HandleEndOfInput() override;

private:
    std::string str_;
};


class CatOperation : public IOperation {
public:
    CatOperation() : IOperation(nullptr) {}
    CatOperation(std::string& filename, IOperation* next_operation = nullptr) : IOperation(next_operation), filename_(filename) {}
    
    void ProcessLine(const std::string& str) override;
    
    void HandleEndOfInput() override;
    
private:
    std::string filename_;
};