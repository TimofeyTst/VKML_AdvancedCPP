#include "CommandParser.hpp"

OperationsList::OperationsList(const std::string& input) : head_(nullptr), tail_(nullptr)  {
    size_t pos = 0;
    std::string token;
    std::string_view cursor(input);

    // Пока есть разделители, запоминаем позицию
    while ((pos = cursor.find(delimiter)) != std::string::npos) {
        // Получаем подстроку до разделителя
        token = cursor.substr(0, pos);
        // Удаляем ее из input учитывая длину разделителя
        cursor = cursor.substr(pos + delimiter.length());
        AddOperation(token);
    }

    // Последняя команда указана без разделителя, обрабатываем ее
    if (!cursor.empty()) {
        AddOperation(std::string(cursor));
    }
}

void OperationsList::AddOperation(const std::string& token){
    const std::string ECHO = "echo";
    const std::string CAT = "cat";

    if (token.find(ECHO) == 0) {
        std::string str = token.substr(ECHO.length() + 1); // Достаем переданную строку
        AddOperation(std::make_shared<EchoOperation>(str));
    } else if (token.find(CAT) == 0) {
        std::string file = token.substr(CAT.length() + 1); // Достаем переданный файл
        AddOperation(std::make_shared<CatOperation>(file));
    }
}


void OperationsList::AddOperation(std::shared_ptr<IOperation>&& operation) {
    if (!head_) {
        head_ = std::move(operation);
        tail_ = head_;
    } else {
        tail_->SetNextOperation(std::move(operation));
        tail_ = tail_->next_operation_;
    }
}


void OperationsList::RunOperations() {
    if (head_) {
        head_->HandleEndOfInput();
    }
}