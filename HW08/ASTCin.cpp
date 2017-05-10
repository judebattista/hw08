//
//  ASTCin.cpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/19/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#include "ASTCin.hpp"
#include <iostream>
using namespace std;

ASTCin::ASTCin(std::string var)
{
    _var = var;
}

int ASTCin::evaluate(std::map<std::string, int>& variables)
{
    int num = 0;
    cin >> num;
    variables[_var] = num;
    return num;
}

void ASTCin::print(int nestingLevel)
{
    indent(nestingLevel);
    cout << "cin >> " << _var << ";" << endl;
}
