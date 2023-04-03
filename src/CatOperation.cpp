#include "CatOperation.hpp"

void CatOperation::ProcessLine(const std::string& str) {
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


void CatOperation::HandleEndOfInput() {
    ProcessLine(filename_);
    if (next_operation_) {
        next_operation_->HandleEndOfInput();
    }
}