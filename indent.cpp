#include <iostream>
#include <string>
#include "unindent.h"

int countChar(std::string line, char c) {
    /*
        Funcion counts and returns the number of times char c is found in line.
    */
    int count = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == c) {
            count += 1;
        }
    }
    return count;
}


std::string indent(std::string raw_str) {
    /*
    Function correctly indents the given string.
    @param raw_str input to indent
    @return indented_str correctly indented code

    Shortcomings:
        1. Won't work for loops/if statements without curly brackets
        2. No support for commented curly brackets
        3. Symbols {, } inside string and char literals are misinterpreted as blocks
        4. May not work if the code is not syntacticly correct (uneven number of open/curly brackets)
    */
    std::string indented_str = "";
    std::string line;
    int count = 0;
    int count_dif;
    int countOpening = 0;
    int countClosing = 0;

    for (int i = 0; i < raw_str.length(); i++) {
        line = "";
        while (raw_str[i] != '\n') {
            line += raw_str[i];
            i++;
        }
        line = removeLeadingSpaces(line); // unindents line
        countOpening = countChar(line, '{');
        countClosing = countChar(line, '}');
        count_dif = countOpening - countClosing;

        if (count_dif <= 0) { // if more } than { in a line
            count += count_dif; 
        }

        for (int i = 0; i < count; i++) { // properly indents line
            line.insert(0, 1, '\t');
        }

        indented_str += line + '\n';   

        if (count_dif > 0) {
            count += count_dif;
        }    

    }
    return indented_str;
}