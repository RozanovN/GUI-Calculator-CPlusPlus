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
#include "wx/wx.h"

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
    string BasicMath::calculateExpression(const string userInput, wxListBox* stepsField) {
        vector<string> expression = convertToReversePolishNotation(userInput);
        int i;

        for (i = 0; i < expression.size(); i++) {
            if (!isOperand(expression[i])) {
                if (i - 2 >= 0) {
                    expression[i] = evaluateExpression(expression[i-2], expression[i], expression[i-1], stepsField);
                    expression.erase(expression.begin() + i - 1);
                    expression.erase(expression.begin() + i - 2);
                    i -= 2;
                } else {
                    expression[i] = evaluateExpression("0", expression[i], expression[i - 1], stepsField);
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
    string BasicMath::evaluateExpression(const string firstOperand, const string anOperator, const string secondOperand, wxListBox* stepsField) {
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

        addSteps(firstOperand, anOperator, secondOperand, to_string(result), stepsField);
        return to_string(result);
    }

    /*
    * Tokenizes the expression into operands and operators.
    * 
    * @param expression a string representing a mathematical expression
    * @return a vector of strings representing the tokenized expression
    */
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

    /*
    * Converts the expression to reverse polish notation form.
    *
    * @param expression a string representing a mathematical expression
    * @return a vector of string representing the expression in the reverse polish notation form
    */
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

    /*
    * Moves the elements of the given stack to the given vector.
    *
    * @param expression a vector of strings representing the tokenized expression
    * @param result a stack of strings representing the operators in the expression
    */
    void BasicMath::addElementsOfStackToArray(vector<string>& result, stack<string>& stackOfOperators) {
        while (!(stackOfOperators.empty() || stackOfOperators.top() == "(")) {
            string temp = stackOfOperators.top();
            stackOfOperators.pop();
            result.push_back(temp);
        }
        if (!stackOfOperators.empty()) {
            stackOfOperators.pop();
        }
    }

    /*
    * Moves the elements of the given stack to the given vector while the last operator in stack of operators has a bigger value than anOperator.
    *
    * @param expression a vector of strings representing the tokenized expression
    * @param result a stack of strings representing the operators in the expression
    * @param anOperator a string representing a mathematical operator
    */
    void BasicMath::addElementsOfStackToArray(vector<string>& result, stack<string>& stackOfOperators, string anOperator) {
        while (!stackOfOperators.empty() && getOrderValue(anOperator) <= getOrderValue(stackOfOperators.top())) {
            string temp = stackOfOperators.top();
            result.push_back(temp);
        }
        stackOfOperators.push(anOperator);
    }

    /*
    * Returns true if the given string an operand, else false.
    *
    * @param operandOrOperator a string representing a potential operand
    * @return true if the given string an operand, otherwise false
    */
    bool BasicMath::isOperand(const string operandOrOperator) {
        char* nullPointer = nullptr;
        double value = strtod(operandOrOperator.c_str(), &nullPointer);
        return nullPointer != operandOrOperator.c_str() && *nullPointer == '\0' && value != HUGE_VAL;
    }

    /*
    * Returns the value of operator representing its order of execution.
    *
    * @param anOperator representing a mathematical operator
    * @return true if the given string an operand, otherwise false
    */
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

    /*
    * Displays a calculation step.
    *
    * @param firstOperand a string representing a mathematical operand
    * @param anOperator a string  representing a mathematical operator
    * @param secondOperand a string representing a mathematical operand
    * @param result a string representing the result of calculations
    * @param stepsField a wxListBox representing a frame to display the calculation step
    */
    void BasicMath::addSteps(const string firstOperand, const string anOperator, const string secondOperand, const string result, wxListBox* stepsField) {
        // 
        if (anOperator == "log10" || anOperator == "ln") {
            stepsField->AppendString(anOperator + "(" + secondOperand + ") =" + result);
        }
        else {
            stepsField->AppendString(firstOperand + " " + anOperator + " " + secondOperand + " = " + result);
        }
    }