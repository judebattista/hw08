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
			cout << _value;
			break;
        case typeVar:
			cout << _variable;
          
            
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
	//TODO: Check for precedence of each side and compare to the current precedence
	int left = 0;
	int right = 0;
	int result = 0;
	switch (_type) {
	case typeVal:
		return _value;
		break;
	case typeVar:
		return variables[_variable];
		break;
	case typeAdd:
		left = _leftExpression->evaluate(variables);
		right = _rightExpression->evaluate(variables);
		result = left + right;
		return _leftExpression->evaluate(variables) + _rightExpression->evaluate(variables);
	case typeSub:
		left = _leftExpression->evaluate(variables);
		right = _rightExpression->evaluate(variables);
		result = left - right;
		return _leftExpression->evaluate(variables) - _rightExpression->evaluate(variables);
	case typeMul:
		left = _leftExpression->evaluate(variables);
		right = _rightExpression->evaluate(variables);
		result = left * right;
		return _leftExpression->evaluate(variables) * _rightExpression->evaluate(variables);
	case typeDiv:
		return _leftExpression->evaluate(variables) / _rightExpression->evaluate(variables);
	case typeGreaterThan:
		return _leftExpression->evaluate(variables) > _rightExpression->evaluate(variables);
	case typeGreaterThanOrEqual:
		return _leftExpression->evaluate(variables) >= _rightExpression->evaluate(variables);
	case typeLessThan:
		return _leftExpression->evaluate(variables) < _rightExpression->evaluate(variables);
	case typeLessThanOrEqual:
		return _leftExpression->evaluate(variables) <= _rightExpression->evaluate(variables);
	case typeEqual:
		return _leftExpression->evaluate(variables) == _rightExpression->evaluate(variables);
	case typeNotEqual:
		return _leftExpression->evaluate(variables) != _rightExpression->evaluate(variables);
	default:
		break;
	}

	return 0;
}

void ASTExpression::print(int nestingLevel)
{
    //TO DO: Print this expression
	this->indent(nestingLevel);
	switch (_type) {
	case typeVal:
		cout << _value;
		break;
	case typeVar:
		cout << _variable;
		break;
	case typeAdd:
	case typeSub:
		cout << "(";
		if (_leftExpression != NULL) {
			_leftExpression->print(0);
		}
		printType();
		if (_rightExpression != NULL) {
			_rightExpression->print(0);
		}
		cout << ")";
		break;
	case typeMul:
	case typeDiv:
	case typeGreaterThan:
	case typeGreaterThanOrEqual:
	case typeLessThan:
	case typeLessThanOrEqual:
	case typeEqual:
	case typeNotEqual:
		if (_leftExpression != NULL) {
			_leftExpression->print(0);
		}
		printType();
		if (_rightExpression != NULL) {
			_rightExpression->print(0);
		}
	default:
		break;
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

