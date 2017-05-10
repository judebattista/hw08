//
//  ASTCin.hpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/19/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#ifndef ASTCin_hpp
#define ASTCin_hpp

#include <stdio.h>
#include <string>
#include "ASTNode.hpp"

class ASTCin: public ASTNode
{
private:
    std::string _var;
public:
    
    //Does a cin for an int and assigns it to the variable
    ASTCin(std::string var);
    
    virtual int evaluate(std::map<std::string, int>& variables);
    virtual void print(int nestingLevel);

};


#endif /* ASTCin_hpp */
