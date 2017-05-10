//
//  ASTCodeGroup.hpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/12/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#ifndef ASTCodeGroup_hpp
#define ASTCodeGroup_hpp

#include <stdio.h>
#include <vector>
#include "ASTNode.hpp"

class ASTCodeGroup : public ASTNode
{
private:
    std::vector<ASTNode*> _statements;
    
public:
    ASTCodeGroup();
    ASTCodeGroup(ASTNode* node); //For groups with one node
    
    //Adds a node to the group
    void addNode(ASTNode* node);
    
    virtual int evaluate(std::map<std::string, int>& variables);
    virtual void print(int nestingLevel);
    
};

#endif /* ASTCodeGroup_hpp */
