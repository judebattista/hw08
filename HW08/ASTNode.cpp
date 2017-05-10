//
//  ASTNode.cpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/12/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#include "ASTNode.hpp"
#include <iostream>
using namespace std;

void ASTNode::indent(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << "    ";
    }
}
