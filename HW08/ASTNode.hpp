//
//  ASTNode.hpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/12/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#ifndef ASTNode_hpp
#define ASTNode_hpp

#include <stdio.h>
#include <map>
#include <string>

class ASTNode
{
public:
    
    //You can evaluate this node to get a result
    virtual int evaluate(std::map<std::string, int>& variables)=0;
    
    //You can print out this node
    virtual void print(int nestingLevel)=0;
    
    void indent(int level);
};

#endif /* ASTNode_hpp */
