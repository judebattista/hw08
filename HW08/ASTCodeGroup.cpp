//
//  ASTCodeGroup.cpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/12/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#include <iostream>
#include "ASTCodeGroup.hpp"
using namespace std;

ASTCodeGroup::ASTCodeGroup()
{
    
}

ASTCodeGroup::ASTCodeGroup(ASTNode* node)
{
    addNode(node);
}

void ASTCodeGroup::addNode(ASTNode* node)
{
    _statements.push_back(node);
}

int ASTCodeGroup::evaluate(std::map<std::string, int>& variables)
{
    //Evaluate each statement in this group
    int result = 0;
    for (int i = 0; i < this->_statements.size(); i++)
    {
        ASTNode* node = this->_statements[i];
        result = node->evaluate(variables);
    }
    
    return result;
}

void ASTCodeGroup::print(int nestingLevel)
{
    //Print each statement in this group
    indent(nestingLevel);
    cout << "{" << endl;
    for (int i = 0; i < this->_statements.size(); i++)
    {
        ASTNode* node = this->_statements[i];
        node->print(nestingLevel+1);
        cout << endl;
    }
    indent(nestingLevel);
    cout << "}" << endl;
}
