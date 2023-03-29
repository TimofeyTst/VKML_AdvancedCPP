#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "IOperation.hpp"


int main() {
    std::string input = "echo million$ | cat static/text.txt | cat static/zarplata.txt";

    OperationsList list;

    std::string delimiter = " | ";
    size_t pos = 0;
    std::string token;
    while ((pos = input.find(delimiter)) != std::string::npos) {
        token = input.substr(0, pos);
        input.erase(0, pos + delimiter.length());

        if (token.find("echo") == 0) {
            std::string str = token.substr(5);
            list.AddOperation(new EchoOperation(str));
        } else if (token.find("cat") == 0) {
            std::string file = token.substr(4);
            list.AddOperation(new CatOperation(file));
        }
    }

    if (!input.empty()) {
        if (input.find("echo") == 0) {
            std::string str = input.substr(5);
            list.AddOperation(new EchoOperation(str));
        } else if (input.find("cat") == 0) {
            std::string file = input.substr(4);
            list.AddOperation(new CatOperation(file));
        }
    }

    list.RunOperations();

    return 0;
}