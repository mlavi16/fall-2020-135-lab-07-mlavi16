#include <fstream>
#include <iostream>
#include <string>
#include "unindent.h"

std::string removeLeadingSpaces(std::string line) {
    /*
    Function takes one line of code as input and returns its copy 
    without leading spaces and tabs.
    */

   std::string new_line = "";
   int index = 0; //index of first char that's not whitespace

    while (isspace(line[index])) {
        index++;
    }

   for (int i = index; i < line.length(); i++) {
       new_line += line[i];
   }

   return new_line;
}

std::string unindent(std::string raw_str) {
    /*
        Function unindents all code.
    */
    std::string fixed_str = "";
    std::string line;
    int index = 0;

    for (int i = 0; i < raw_str.length(); i++){
        line = "";
        while (raw_str[i] != '\n') {
            line += raw_str[i];
            i++;
        }
        fixed_str += removeLeadingSpaces(line) + '\n';
    }
    return fixed_str;
}

