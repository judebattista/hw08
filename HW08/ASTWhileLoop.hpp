//
//  ASTWhileLoop.hpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/12/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#ifndef ASTWhileLoop_hpp
#define ASTWhileLoop_hpp

#include <stdio.h>
#include "ASTNode.hpp"
#include "ASTExpression.hpp"
#include "ASTAssignment.hpp"
#include "ASTCodeGroup.hpp"

class ASTWhileLoop : public ASTNode
{
private:
    ASTExpression* _condition;
    ASTCodeGroup* _body;
public:
    
    //Creates a while loop as
    //  while (condition)
    //  {
    //      body
    //  }
    ASTWhileLoop(ASTExpression* condition, ASTCodeGroup* body);
    
    virtual int evaluate(std::map<std::string, int>& variables);
    virtual void print(int nestingLevel);

};


#endif /* ASTWhileLoop_hpp */
