#pragma once
#include <iostream>
#include <fstream>

class IOperation {
public:
    IOperation() : next_operation_(nullptr) {}
    IOperation(IOperation * op) : next_operation_(op) {}
    virtual void ProcessLine(const std::string& str) = 0;
    virtual void HandleEndOfInput() = 0;
    virtual void SetNextOperation(IOperation* operation) = 0;
    virtual ~IOperation() {
        if(next_operation_){
            delete next_operation_;
        }
    }
    IOperation* next_operation_;
};

class EchoOperation : public IOperation {
public:
    EchoOperation() : IOperation(nullptr) {}
    EchoOperation(std::string& str, IOperation* operation = nullptr) : IOperation(operation), str_(str) {}

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
    std::string str_;
};


class CatOperation : public IOperation {
public:
    CatOperation() : IOperation(nullptr) {}
    CatOperation(std::string& filename, IOperation* next_operation = nullptr) : IOperation(next_operation), filename_(filename) {}
    
    void ProcessLine(const std::string& str) override {
        std::ifstream file_(str);
        if (!file_.is_open()) {
            throw std::runtime_error("Cannot open file: " + str);
        }
        // читаем строки из файла и выводим их
        std::string line;
        while (std::getline(file_, line)) {
            std::cout << line << std::endl;
        }
    }
    
    void HandleEndOfInput() override {
        ProcessLine(filename_);
        if (next_operation_) {
            next_operation_->HandleEndOfInput();
        }
    }
    
    void SetNextOperation(IOperation* operation) override {
        next_operation_ = operation;
    }
    
private:
    std::string filename_;
};

class OperationsList {
public:
    OperationsList() : head_(nullptr), tail_(nullptr) {}

    void AddOperation(IOperation* op) {
        if (!head_) {
            head_ = op;
            tail_ = op;
        } else {
            tail_->SetNextOperation(op);
            tail_ = op;
        }
    }

    void RunOperations() {
        if (head_) {
            head_->HandleEndOfInput();
        }
    }

    virtual ~OperationsList() {
        IOperation* cur = head_;
        IOperation* prev;
        while (cur) {
            prev = cur;
            cur = cur->next_operation_;
            delete prev;
        }
    }

private:
    IOperation* head_;
    IOperation* tail_;
};