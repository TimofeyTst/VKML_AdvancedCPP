#include "EchoOperation.hpp"

void EchoOperation::ProcessLine(const std::string& str) {
    std::cout << str << std::endl;
}


void EchoOperation::HandleEndOfInput() {
    ProcessLine(str_);
    if(next_operation_) {
        next_operation_->HandleEndOfInput();
    }
}