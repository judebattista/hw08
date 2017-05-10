//
//  main.cpp
//  CS273_HW08_AST
//
//  Created by Stephen Johnson on 4/12/17.
//  Copyright © 2017 Glacier Peak Studios LLC. All rights reserved.
//

#include <iostream>
#include <map>
#include "ASTNode.hpp"
#include "ASTCodeGroup.hpp"
#include "ASTAssignment.hpp"
#include "ASTExpression.hpp"
#include "ASTForLoop.hpp"
#include "ASTWhileLoop.hpp"
#include "ASTIfElse.hpp"
#include "ASTCin.hpp"
#include "ASTCout.hpp"

using namespace std;

void testSumation()
{
    
    cout << "----- Test Summation -----" << endl;
    
    /*
     * Create the AST for the summation
     *
     * sum = 0;
     * for (i = 1; i <= 10; i = i + 1)
     * {
     *     sum = sum + i;
     * }
     * sum;
     *
     * The final value is the return value
     */
    
    ASTExpression zero(0);
    ASTExpression one(1);
    ASTExpression varI("i");
    ASTExpression varSum("sum");
    ASTExpression ten(10);
    
    ASTAssignment initSum("sum", &zero); //sum=0
    
    //Parts of the loop
    ASTExpression addOne(&varI, &one, typeAdd); //i+1
    ASTAssignment loopInit("i", &one); //i=1
    ASTExpression condition(&varI, &ten, typeLessThanOrEqual); //i<=10
    ASTAssignment update("i", &addOne); //i=i+1
    
    //loop body
    ASTExpression sumAdd(&varSum, &varI, typeAdd);
    ASTAssignment sumUpdate("sum", &sumAdd);
    ASTCodeGroup body;
    body.addNode(&sumUpdate);
    
    //loop
    ASTForLoop forLoop(&loopInit, &condition, &update, &body);
    
    //full function
    ASTCodeGroup funct;
    funct.addNode(&initSum);
    funct.addNode(&forLoop);
    funct.addNode(&varSum); //Last expression is the result
    
    funct.print(0);
    
    map<string, int> variables;
    int result = funct.evaluate(variables);
    cout << "result: " << result << endl;
}

void testExpressions()
{
    
    cout << "----- Test Expressions -----" << endl;
    
    /*
     * Create the AST for
     *
     * var = (1 + 3) * (6 - 7);
     * x = 2 * var + 3;
     * y = x + var;
     * y
     *
     */
    
    ASTExpression one(1);
    ASTExpression two(2);
    ASTExpression three(3);
    ASTExpression six(6);
    ASTExpression seven(7);
    ASTExpression var("var");
    ASTExpression x("x");
    ASTExpression y("y");
    
    //var = (1 + 3) * (6 - 7);
    ASTExpression leftAdd(&one, &two, typeAdd);
    ASTExpression rightAdd(&six, &seven, typeSub);
    ASTExpression firstMul(&leftAdd, &rightAdd, typeMul);
    ASTAssignment varAssign("var", &firstMul);
    
    //x = 2 * var + 3;
    ASTExpression secondMul = ASTExpression(&two, &var, typeMul);
    ASTExpression secondAdd = ASTExpression(&secondMul, &three, typeAdd);
    ASTAssignment xAssign("x", &secondAdd);
    
    //y = x + var;
    ASTExpression lastAdd(&x, &var, typeAdd);
    ASTAssignment yAssign("y", &lastAdd);
    
    ASTCodeGroup func;
    func.addNode(&varAssign);
    func.addNode(&xAssign);
    func.addNode(&yAssign);
    func.addNode(&y);

    func.print(0);
    
    map<string, int> variables;
    int result = func.evaluate(variables);
    cout << "result: " << result << endl << endl;

}

void testComplex()
{
    
    cout << "----- Test Complex -----" << endl;
    
    /*
     * Create the AST for
     *
     * cout << "Hello, guess a number between 1 and 10\n";
     * cin >> guess;
     * while (guess > 10)
     * {
     *    cout << "Invalid number! You entered ";
     *    cout << guess;
     *    cout << ". Please try again\n";
     *    cin >> guess;
     * }
     *
     * if (guess == 8)
     * { 
     *    cout << "You got it!\n";
     * }
     * else 
     * {
     *    cout << "Better luck next time\n";
     * }
     * guess
     *
     */
    
    ASTExpression guess("guess");
    ASTExpression eight(8);
    ASTExpression ten(10);
    
    ASTCout hello("Hello, guess a number between 1 and 10\n");
    ASTExpression compare(&guess, &ten, typeGreaterThan);
    ASTCin firstCin("guess");
    
    ASTCout invalid1("Invalid number! You entered ");
    ASTCout invalid2(&guess);
    ASTCout invalid3(". Please try again\n");
    ASTCin secondCin("guess");
    
    ASTCodeGroup whileCodeBlock;
    whileCodeBlock.addNode(&invalid1);
    whileCodeBlock.addNode(&invalid2);
    whileCodeBlock.addNode(&invalid3);
    whileCodeBlock.addNode(&secondCin);
    
    ASTWhileLoop whileLoop(&compare, &whileCodeBlock);
    
    ASTExpression correctCheck(&guess, &eight, typeEqual);
    ASTCout correctCout("You got it!\n");
    ASTCout incorrectCout("Better luck next time\n");
    ASTCodeGroup correctCodeGroup(&correctCout);
    ASTCodeGroup incorrectCodeGroup(&incorrectCout);
    
    ASTIfElse ifStatement(&correctCheck, &correctCodeGroup, &incorrectCodeGroup);
    
    ASTCodeGroup func;
    func.addNode(&hello);
    func.addNode(&firstCin);
    func.addNode(&whileLoop);
    func.addNode(&ifStatement);
    func.addNode(&guess);
    
    func.print(0);
    
    map<string, int> variables;
    int result = func.evaluate(variables);
    cout << "result: " << result << endl << endl;

}

void testYourExample()
{
    //You need to come up with an
    //exampe to test.
}

int main(int argc, const char * argv[])
{
    //Run the tests
    testExpressions();
    testSumation();
    testComplex();
    testYourExample();
    
    return 0;
}
