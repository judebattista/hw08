//
//  ASTForLoop.hpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/12/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#ifndef ASTForLoop_hpp
#define ASTForLoop_hpp

#include <stdio.h>
#include "ASTNode.hpp"
#include "ASTExpression.hpp"
#include "ASTAssignment.hpp"
#include "ASTCodeGroup.hpp"

class ASTForLoop : public ASTNode
{
private:
    ASTAssignment* _initialization;
    ASTExpression* _condition;
    ASTAssignment* _update;
    ASTCodeGroup* _body;
public:
    
    //Creates a for loop as
    // for (initialization; condition; update;)
    // {
    //    body
    // }
    ASTForLoop(ASTAssignment* initialization, ASTExpression* condition, ASTAssignment* update, ASTCodeGroup* body);
    
    virtual int evaluate(std::map<std::string, int>& variables);
    virtual void print(int nestingLevel);

};

#endif /* ASTForLoop_hpp */
