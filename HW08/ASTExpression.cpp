//
//  ASTMathExpression.cpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/12/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#include "ASTExpression.hpp"
#include <iostream>
using namespace std;

ASTExpression::ASTExpression(int value)
{
    _value = value;
    _type = typeVal;
    _leftExpression = NULL;
    _rightExpression = NULL;
}

ASTExpression::ASTExpression(std::string variable)
{
    _variable = variable;
    _type = typeVar;
    _leftExpression = NULL;
    _rightExpression = NULL;
}

ASTExpression::ASTExpression(ASTExpression* left, ASTExpression* right, expressionType type)
{
    _leftExpression = left;
    _rightExpression = right;
    _type = type;
}

int ASTExpression::precedence()
{
    switch (_type) {
        case typeVal:
        case typeVar:
            return 0;
          
            
        case typeAdd:
        case typeSub:
            return 1;
            
        case typeMul:
        case typeDiv:
            return 2;
            
        case typeGreaterThan:
        case typeGreaterThanOrEqual:
        case typeLessThan:
        case typeLessThanOrEqual:
        case typeEqual:
        case typeNotEqual:
            return 3;
            
        default:
            break;
    }
    
    return 0;
}

int ASTExpression::evaluate(std::map<std::string, int>& variables)
{
    //TO DO: Evaluate this expression and return the result
    return 0;
}

void ASTExpression::print(int nestingLevel)
{
    //TO DO: Print this expression
	this->indent(nestingLevel);
	if (_leftExpression != NULL) {
		_leftExpression->print(0);
	}
	printType();
	if (_rightExpression != NULL) {
		_rightExpression->print(0);
	}

}

void ASTExpression::printType() {
	switch (_type) {
	case typeVal:
	case typeVar:
		break;
	case typeAdd:
		cout << " + ";
		break;
	case typeSub:
		cout << " - ";
		break;
	case typeMul:
		cout << " * ";
		break;
	case typeDiv:
		cout << " / ";
		break;
	case typeGreaterThan:
		cout << " > ";
		break;
	case typeGreaterThanOrEqual:
		cout << " >= ";
		break;
	case typeLessThan:
		cout << " < ";
		break;
	case typeLessThanOrEqual:
		cout << " <= ";
		break;
	case typeEqual:
		cout << " == ";
		break;
	case typeNotEqual:
		cout << " != ";
		break;
	default:
		break;
	}
}

