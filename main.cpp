#include <iostream>
#include "unindent.h"
#include "indent.h"

int main()
{
    std::string line;
    std::string input;
    while (std::getline(std::cin, line)){
        input += line + '\n';
    }
    std::cout << "Unindented code:\n" << unindent(input) << "\n-----------------\n" << std::endl;
    std::cout << "Indented code:\n" <<indent(input) << std::endl;
    return 0;
}