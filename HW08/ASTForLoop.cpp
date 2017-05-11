//
//  ASTForLoop.cpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/12/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#include "ASTForLoop.hpp"
#include "ASTWhileLoop.hpp"
#include <iostream>
using namespace std;

ASTForLoop::ASTForLoop(ASTAssignment* initialization, ASTExpression* condition, ASTAssignment* update, ASTCodeGroup* body)
{
    _initialization = initialization;
    _condition = condition;
    _update = update;
    _body = body;
}

int ASTForLoop::evaluate(std::map<std::string, int>& variables)
{
	//So, a for loop is really just a while loop and we already have a while loop...
	ASTCodeGroup whileLoopBody;
	whileLoopBody.addNode(_body); //Add the for loop body to the while loop body
	whileLoopBody.addNode(_update); //Update the counter in the while loop body
	ASTWhileLoop whileLoop(_condition, &whileLoopBody);
	ASTCodeGroup translatedForLoop;
	translatedForLoop.addNode(_initialization); //Initialize the counter
	translatedForLoop.addNode(&whileLoop); //Run the while loop
	int result = 0;
	translatedForLoop.evaluate(variables);
    return result;
}

void ASTForLoop::print(int nestingLevel)
{
	//TO DO: Print this for loop
	indent(nestingLevel);
	cout << "for (";
	_initialization->print(0);
	_condition->print(0);
	cout << "; ";
	_update->print(0);
	cout << ") \n";
	_body->print(nestingLevel);
}
