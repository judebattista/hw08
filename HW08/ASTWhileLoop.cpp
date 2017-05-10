//
//  ASTWhileLoop.cpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/12/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#include "ASTWhileLoop.hpp"
#include <iostream>
using namespace std;

ASTWhileLoop::ASTWhileLoop(ASTExpression* condition, ASTCodeGroup* body)
{
    _condition = condition;
    _body = body;
}

int ASTWhileLoop::evaluate(std::map<std::string, int>& variables)
{
    //TO DO
    return 0;
}

void ASTWhileLoop::print(int nestingLevel)
{
    //TO DO
}
