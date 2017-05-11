//
//  ASTMathExpression.hpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/12/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#ifndef ASTExpression_hpp
#define ASTExpression_hpp

#include <stdio.h>
#include <string>
#include "ASTNode.hpp"

enum expressionType
{
    //Value types
    typeVar, //just a variable
    typeVal, //a number value
    
    //Math operators
    typeMul,
    typeAdd,
    typeSub,
    typeDiv,
    
    //Comparison
    typeGreaterThan,
    typeGreaterThanOrEqual,
    typeLessThan,
    typeLessThanOrEqual,
    typeEqual,
    typeNotEqual
};

class ASTExpression: public ASTNode
{
private:
    std::string _variable;
    int _value;
    expressionType _type;
    
    ASTExpression* _leftExpression;
    ASTExpression* _rightExpression;
    
public:
    
    //Creates an expression that is just an int value
    ASTExpression(int value);
    
    //Creates an expresssion that is the value of a variable
    ASTExpression(std::string variable);
    
    //Creates an expression that is the result of "left type right" ie "left + right" or "left > right"
    ASTExpression(ASTExpression* left, ASTExpression* right, expressionType type);
    
    virtual int evaluate(std::map<std::string, int>& variables);
    virtual void print(int nestingLevel);
	//Print the operator
	void printType();

    int precedence();

};

#endif /* ASTMathExpression_hpp */
