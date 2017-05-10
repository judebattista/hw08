//
//  ASTIfElse.hpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/12/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#ifndef ASTIfElse_hpp
#define ASTIfElse_hpp

#include <stdio.h>
#include "ASTNode.hpp"
#include "ASTExpression.hpp"
#include "ASTCodeGroup.hpp"

class ASTIfElse : public ASTNode
{
private:
    ASTExpression* _condition;
    ASTCodeGroup* _ifBody;
    ASTCodeGroup* _elseBody;
    
public:
    
    //Creates an if else as
    //  if (condition)
    //  {
    //      ifBody
    //  } else {
    //      elseBody
    //  }
    ASTIfElse(ASTExpression* condition, ASTCodeGroup* ifBody, ASTCodeGroup* elseBody);

    //Creates an if as
    //  if (condition)
    //  {
    //      ifBody
    //  }
    ASTIfElse(ASTExpression* condition, ASTCodeGroup* ifBody);
    
    virtual int evaluate(std::map<std::string, int>& variables);
    virtual void print(int nestingLevel);

};

#endif /* ASTIfElse_hpp */
