//
//  ASTCout.cpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/19/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#include "ASTCout.hpp"
#include <iostream>
using namespace std;

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

ASTCout::ASTCout(std::string str)
{
    _str = str;
    _expression = NULL;
}

ASTCout::ASTCout(ASTExpression* expression)
{
    _expression = expression;
}

int ASTCout::evaluate(std::map<std::string, int>& variables)
{
    if (_expression != NULL)
    {
        int num = _expression->evaluate(variables);
        cout << num;
        return num;
    }
    else
    {
        cout << _str;
        return 0;
    }
}

void ASTCout::print(int nestingLevel)
{
    indent(nestingLevel);
    cout << "cout << ";
    
    if (_expression != NULL)
    {
        _expression->print(0);
    }
    else
    {
        string temp = _str;
        replace( temp, "\n", "\\n");
        cout << "\"" << temp << "\"";
    }
    
    cout << ";";
}
