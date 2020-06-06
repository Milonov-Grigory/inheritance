#include <iostream>
#include <cctype>
#include "parser.h"

bool StrParser::parse(std::istream& stream) {
    char buffer[30];
    stream >> buffer;

    for(const char* it = buffer; *it; ++it)
        if(!(isascii(*it) && !isdigit(*it)))
            return false;

    return true;
}


bool IntParser::parse(std::istream &stream) {
    char buffer[30]; stream >> buffer;

    for(const char* it = buffer; *it; ++it)
        if(!isdigit(*it)) return false;

    return true;

}

bool IdParser::parse(std::istream &stream) {
    char buffer[30]; stream >> buffer;
    const char * it = buffer;

    if(!isalpha(*it++)) return false;

    for(;*it;++it)
        if(!isalnum(*it)) return false;

    return true;

}
bool OpParser::parse(std::istream &stream) {
    char buffer[30]; stream >> buffer;

    for(const char* it = buffer; *it; ++it)
        if(*it != '+' && *it != '-' && *it != '/' && *it != '*')
            return false;

    return true;
}

bool CombiParser::parse(std::istream & stream) {
    for(Item* it = list; it; it = it->next)
        if(!it->parser->parse(stream))
            return false;

    return true;

}





