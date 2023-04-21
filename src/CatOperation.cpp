#include "CatOperation.hpp"
#include <sstream>

void CatOperation::ProcessLine(const std::string& pipeline) {
    std::ifstream file_(filename_);
    if (!file_.is_open()) {
        throw std::runtime_error("Cannot open file: " + filename_);
    }

    // создаем std::stringstream и передаем в него буфер файла
    std::stringstream file_stream;
    file_stream << file_.rdbuf();

    // получаем содержимое файла в виде строки
    std::string file_contents = file_stream.str();

    // передаем pipeline + file_contents в метод ProcessLine следующей операции
    if (next_operation_) {
        next_operation_->ProcessLine(pipeline + file_contents);
    } else {
        std::cout << pipeline << std::endl << file_contents << std::endl;
    }
}


void CatOperation::HandleEndOfInput() {
    ProcessLine("");
}