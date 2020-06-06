#ifndef INHERITANCE_PARSER_H
#define INHERITANCE_PARSER_H

class Parser
{
public:
    virtual bool parse(std::istream& stream) = 0;
};

class IntParser : public Parser
{
public:
    virtual bool parse(std::istream& stream);
};

class StrParser : public Parser
{
public:
    virtual bool parse(std::istream& stream);
};

class IdParser : public Parser
{
public:
    virtual bool parse(std::istream& stream);
};

class OpParser : public Parser
{
public:
    virtual bool parse(std::istream& stream);
};

class CombiParser : public Parser
{
    struct Item
    {
        Parser* parser;
        Item* next;
    };
    Item* list;
public:
    CombiParser(int num, ...);
    virtual bool parse(std::istream& stream);
};

#endif //INHERITANCE_PARSER_H
