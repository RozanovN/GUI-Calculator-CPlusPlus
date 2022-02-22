//
// Created by Nikolay on 2022-02-03.
//

#include <vector>
#include <numeric>
#include <iostream>
#include <stack>
#include "BasicMath.h"
#include "string"
#include <cmath>
#include <cstring>
#include <sstream>
#include <map>

using namespace std;


    /**
     * Constructs a Basic Math calculator.
     */
    BasicMath::BasicMath() = default;;

    /**
    * Calculates expression.
    *
    * @param userInput a string that represents the expression given by the user
    * @return the result of expression as a string
    */
    string BasicMath::calculateExpression(const string userInput) {
        vector<string> expression = convertToReversePolishNotation(userInput);
        int i;

        for (i = 0; i < expression.size(); i++) {
            if (!isOperand(expression[i])) {
                if (i - 2 >= 0) {
                    expression[i] = evaluateExpression(expression[i-2], expression[i], expression[i-1]);
                    expression.erase(expression.begin() + i - 1);
                    expression.erase(expression.begin() + i - 2);
                    i -= 2;
                } else {
                    expression[i] = evaluateExpression("0", expression[i], expression[i - 1]);
                    expression.erase(expression.begin() + i - 1);
                    --i;
                }
            }
        }
        return accumulate(expression.begin(), expression.end(), string{});
    }

    /**
    * Gets button values.
    *
    * @return a vector of strings representing button values
    */
    vector<string> BasicMath::getButtonValues() {
        return buttonValues;
    }

    /**
    * Calculates expression.
    *
    * @param userInput a string that represents the expression given by the user
    * @return the result of expression as a String
    */
    string BasicMath::evaluateExpression(const string firstOperand, const string anOperator, const string secondOperand) {
        double result;

        if (anOperator == "+") {
            result = stod(firstOperand) + stod(secondOperand);
        } else if (anOperator == "-") {
            result = stod(firstOperand) - stod(secondOperand);
        } else if (anOperator == "/") {
            result = stod(firstOperand) / stod(secondOperand);
        } else if (anOperator == "*") {
            result = stod(firstOperand) * stod(secondOperand);
        } else if (anOperator == "^") {
            result = pow(stod(firstOperand), stod(secondOperand));
        } else if (anOperator == "sqrt") {
            result = sqrt(stod(secondOperand));
        } else if (anOperator == "log10") {
            result = log(10) / log(stod(secondOperand));
        } else if (anOperator == "ln") {
            result = log(stod(secondOperand));
        } else {
            result = 0;
        }

        //add steps (missing)
        return to_string(result);
    }

    vector<string> BasicMath::tokenizeExpression(string expression) {
        vector<string> arrayOfTokens;
        string temp;
        stringstream check(expression);

        while (getline(check, temp, ' '))
        {
            arrayOfTokens.push_back(temp);
        }

        return arrayOfTokens;
    }

    vector<string> BasicMath::convertToReversePolishNotation(const string expression) {
        vector<string> result;
        stack<string> stackOfOperators;

        for (string operandOrOperator : tokenizeExpression(expression)) {
            if (isOperand(operandOrOperator)) {
                result.push_back(operandOrOperator);
            } else if (operandOrOperator == "(") {
                stackOfOperators.push(operandOrOperator);
            } else if (operandOrOperator == ")") {
                addElementsOfStackToArray(result, stackOfOperators);
            } else {
                addElementsOfStackToArray(result, stackOfOperators, operandOrOperator);
            }
        }

        addElementsOfStackToArray(result, stackOfOperators);
        return result;
    }

    void BasicMath::addElementsOfStackToArray(vector<string> result, stack<string> stackOfOperands) {
        while (!(stackOfOperands.empty() || stackOfOperands.top() == "(")) {
            string temp = stackOfOperands.top();
            result.push_back(temp);
        }
        if (!stackOfOperands.empty()) {
            stackOfOperands.pop();
        }
    }

    void BasicMath::addElementsOfStackToArray(vector<string> result, stack<string> stackOfOperands,
                                              const string anOperator) {
        while (!stackOfOperands.empty() && getOrderValue(anOperator) <= getOrderValue(stackOfOperands.top())) {
            string temp = stackOfOperands.top();
            result.push_back(temp);
        }
        stackOfOperands.push(anOperator);
    }

    bool BasicMath::isOperand(const string operandOrOperator) {
        char* nullPointer = nullptr;
        double value = strtod(operandOrOperator.c_str(), &nullPointer);
        return nullPointer != operandOrOperator.c_str() && *nullPointer == '\0' && value != HUGE_VAL;
    }

    int BasicMath::getOrderValue(const string anOperator) {
        map<string, int> operationOrder {
            {"^", 3},
            {"log", 3},
            {"ln", 3},
            {"sqrt", 3},
            {"/", 2},
            {"*", 2},
            {"+", 1},
            {"-", 1},
            {"(", -1}
        };

        auto iterator = operationOrder.find(anOperator);
        return iterator -> second;
    }
