//
//  ASTAssignment.cpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/12/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#include "ASTAssignment.hpp"
#include <iostream>
using namespace std;


ASTAssignment::ASTAssignment(std::string variable, ASTExpression* value)
{
    this->_variable = variable;
    this->_value = value;
}

int ASTAssignment::evaluate(std::map<std::string, int>& variables)
{
    //TO DO: Impliment this.  Update the variable with the value
    //and return the value as the result
    return 0;
}

void ASTAssignment::print(int nestingLevel)
{
    indent(nestingLevel);
    cout << _variable << " = ";
    _value->print(0);
    cout << ";";
}
