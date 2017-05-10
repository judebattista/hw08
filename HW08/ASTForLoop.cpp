//
//  ASTForLoop.cpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/12/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#include "ASTForLoop.hpp"
#include <iostream>
using namespace std;

ASTForLoop::ASTForLoop(ASTAssignment* initialization, ASTExpression* condition, ASTAssignment* update, ASTCodeGroup* body)
{
    _initialization = initialization;
    _condition = condition;
    _update = update;
    _body = body;
}

int ASTForLoop::evaluate(std::map<std::string, int>& variables)
{
    //TO DO: Evaluation this for loop and return 0
    return 0;
}

void ASTForLoop::print(int nestingLevel)
{
    //TO DO: Print this for loop
}
