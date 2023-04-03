#include <iostream>
#include "CommandParser.hpp"


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Run program with arguments like: 'echo <someText> | cat <someFileName> | echo million | cat Elon.txt'\n";
        return 1;
    }
    try{
        OperationsList list(argv[1]);
        list.RunOperations();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}