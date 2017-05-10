//
//  ASTAssignment.hpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/12/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#ifndef ASTAssignment_hpp
#define ASTAssignment_hpp

#include <stdio.h>
#include <string>
#include "ASTNode.hpp"
#include "ASTExpression.hpp"

class ASTAssignment: public ASTNode
{
private:
    std::string _variable;
    ASTExpression* _value;
    
public:
    
    //This assigns the value of the expression to the variable
    ASTAssignment(std::string variable, ASTExpression* value);
    
    virtual int evaluate(std::map<std::string, int>& variables);
    virtual void print(int nestingLevel);

};

#endif /* ASTAssignment_hpp */
