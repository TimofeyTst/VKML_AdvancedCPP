#include "CommandParser.hpp"

OperationsList::OperationsList(std::string input) : head_(nullptr), tail_(nullptr)  {
    size_t pos = 0;
    std::string token;

    // Пока есть разделители, запоминаем позицию
    while ((pos = input.find(delimiter)) != std::string::npos) {
        // Получаем подстроку до разделителя
        token = input.substr(0, pos);
        // Удаляем ее из input учитывая длину разделителя
        input.erase(0, pos + delimiter.length());

        if (token.find("echo") == 0) {
            std::string str = token.substr(5); // Достаем переданную строку
            AddOperation(new EchoOperation(str));
        } else if (token.find("cat") == 0) {
            std::string file = token.substr(4); // Достаем переданный файл
            AddOperation(new CatOperation(file));
        }
    }

    // Последняя команда указана без разделителя, обрабатываем ее
    if (!input.empty()) {
        if (input.find("echo") == 0) {
            std::string str = input.substr(5);
            AddOperation(new EchoOperation(str));
        } else if (input.find("cat") == 0) {
            std::string file = input.substr(4);
            AddOperation(new CatOperation(file));
        }
    }
}


void OperationsList::AddOperation(IOperation* op) {
    if (!head_) {
        head_ = op;
        tail_ = op;
    } else {
        tail_->SetNextOperation(op);
        tail_ = op;
    }
}


void OperationsList::RunOperations() {
    if (head_) {
        head_->HandleEndOfInput();
    }
}


OperationsList::~OperationsList() {
    IOperation* cur = head_;
    IOperation* next;
    while (cur) {
        next = cur->next_operation_;
        delete cur;
        cur = next;
    }
}