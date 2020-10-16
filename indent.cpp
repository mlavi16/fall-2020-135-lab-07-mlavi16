#include <iostream>
#include <string>
#include "unindent.h"

int countChar(std::string line, char c) {
    int count = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == c) {
            count += 1;
        }
    }
    return count;
}


std::string indent(std::string raw_str) {
    std::string indented_str = "";
    std::string line;
    int count = 0;

    for (int i = 0; i < raw_str.length(); i++) {
        line = "";
        while (raw_str[i] != '\n') {
            line += raw_str[i];
            i++;
        }
        line = removeLeadingSpaces(line); // unindents line

        if (line[0] == '}') {
            count -= 1;
        }

        for (int i = 0; i < count; i++) { // properly indents line
            line.insert(0, 1, '\t');
        }

        indented_str += line + '\n';       

        count += countChar(line, '{');
        count -= countChar(line, '}');
    }
    return indented_str;
}