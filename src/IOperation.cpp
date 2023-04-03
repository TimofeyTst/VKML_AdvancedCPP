#include "IOperation.hpp"

// Реализуем по умолчанию метод интерфейсного класса
void IOperation::SetNextOperation(std::shared_ptr<IOperation>&& operation) {
    next_operation_ = std::move(operation);
}