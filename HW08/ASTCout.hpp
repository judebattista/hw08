//
//  ASTCout.hpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/19/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#ifndef ASTCout_hpp
#define ASTCout_hpp

#include <stdio.h>
#include <string>
#include "ASTNode.hpp"
#include "ASTExpression.hpp"

class ASTCout: public ASTNode
{
private:
    std::string _str;
    ASTExpression* _expression;
public:
    
    //Does a cout for the string
    ASTCout(std::string str);
    
    //Does a cout for the expression
    ASTCout(ASTExpression* expression);
    
    virtual int evaluate(std::map<std::string, int>& variables);
    virtual void print(int nestingLevel);
    
};


#endif /* ASTCout_hpp */
