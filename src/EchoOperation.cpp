#include "EchoOperation.hpp"

void EchoOperation::ProcessLine(const std::string& pipeline) {
    if(next_operation_) {
        next_operation_->ProcessLine(str_);
    } else {
        std::cout << str_ << std::endl;
    }
}


void EchoOperation::HandleEndOfInput() {
    ProcessLine("");
}