#include "WcOperation.hpp"

void WcOperation::ProcessLine(const std::string& pipeline) {
    // вычисляем суммарное число байт в строке full_string = pipeline + str_
    int total_bytes = sizeof(char) * (pipeline.size() + str_.size());

    // передаем pipeline + str_ в метод ProcessLine следующей операции
    if (next_operation_) {
        next_operation_->ProcessLine(std::to_string(total_bytes));
    } else {
        std::cout << total_bytes << std::endl;
    }
}


void WcOperation::HandleEndOfInput() {
    ProcessLine("");
}