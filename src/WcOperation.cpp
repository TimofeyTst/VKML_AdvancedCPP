#include "WcOperation.hpp"

void WcOperation::ProcessLine(const std::string& str) {
    // str всегда вида "file1.txt file2.txt file3.txt " или ""
    std::istringstream iss(str);
    std::string filename;
    int bytes = 0;
    while (iss >> filename) { // Читаем имена файлов из потока
        std::ifstream file(filename, std::ios::binary);
        if (file) { // Проверяем, успешно ли открылся файл
            file.seekg(0, std::ios::end);
            bytes += file.tellg();
        }
    }
    // Выводим результат в стандартный поток вывода
    std::cout << "Total bytes: " << bytes << std::endl;
}


void WcOperation::HandleEndOfInput() {
    ProcessLine(pipeline_);
    if (next_operation_) {
        next_operation_->HandleEndOfInput();
    }
}