//
//  ASTIfElse.cpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/12/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#include "ASTIfElse.hpp"
#include <iostream>
using namespace std;

ASTIfElse::ASTIfElse(ASTExpression* condition, ASTCodeGroup* ifBody, ASTCodeGroup* elseBody)
{
    _condition = condition;
    _ifBody = ifBody;
    _elseBody = elseBody;
}

ASTIfElse::ASTIfElse(ASTExpression* condition, ASTCodeGroup* ifBody)
{
    _condition = condition;
    _ifBody = ifBody;
    _elseBody = NULL;
}


int ASTIfElse::evaluate(std::map<std::string, int>& variables)
{
    //Evaluate the condition and see if we should then evaluate the if or else body.
    if (_condition->evaluate(variables) != 0)
    {
        _ifBody->evaluate(variables);
    }
    else if (_elseBody != NULL)
    {
        _elseBody->evaluate(variables);
    }
    return 0;
}

void ASTIfElse::print(int nestingLevel)
{
    indent(nestingLevel);
    cout << "if (";
    _condition->print(0);
    cout << ")" << endl;
    _ifBody->print(nestingLevel);
    if (_elseBody != NULL)
    {
        indent(nestingLevel);
        cout << "else" << endl;
        _elseBody->print(nestingLevel);
    }
    
}
