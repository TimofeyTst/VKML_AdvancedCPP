#include <iostream>
#include <fstream>
#include "IOperation.hpp"

class IOperation {
public:
    virtual void ProcessLine(const std::string& str) = 0;
    virtual void HandleEndOfInput() = 0;
    virtual void SetNextOperation(IOperation* operation) = 0;
    virtual ~IOperation() {}
};


class EchoOperation : public IOperation {
public:
    EchoOperation() : next_operation_(nullptr) {}
    EchoOperation(const std::string& str, IOperation* operation = nullptr) : str_(str), next_operation_(operation) {}

    void ProcessLine(const std::string& str) override {
        std::cout << str << std::endl;
    }

    void HandleEndOfInput() override {
        ProcessLine(str_);
        if(next_operation_) {
            next_operation_->HandleEndOfInput();
        }
    }

    void SetNextOperation(IOperation* operation) override {
        next_operation_ = operation;
    }
private:
    const std::string& str_;
    IOperation* next_operation_;
};


class CatOperation : public IOperation {
public:
    CatOperation() : file_(nullptr), next_operation_(nullptr) {}
    CatOperation(const std::string file, IOperation* next_operation=nullptr) : file_(file), next_operation_(next_operation) {}
    
    void ProcessLine(const std::string& str) override {
        if (!file_.is_open()) {
            std::cerr << "Cannot open file: " << str << std::endl;
            HandleEndOfInput();
        }
        // читаем строки из файла и выводим их
        std::string line;
        while (std::getline(file_, line)) {
            std::cout << line << std::endl;
        }
        HandleEndOfInput();
    }
    
    void HandleEndOfInput() override {
        if (next_operation_) {
            next_operation_->HandleEndOfInput();
        }
    }
    
    void SetNextOperation(IOperation* operation) override {
        next_operation_ = operation;
    }
    
    ~CatOperation() {
        std::cout << "Destructor CatOperation\n";
        if(next_operation_) {
            delete next_operation_;
        }
    }
    
private:
    std::ifstream file_;
    IOperation* next_operation_;
};