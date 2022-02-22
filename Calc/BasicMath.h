//
// Created by Nikolay on 2022-02-03.
//
#pragma once

#include <stack>

class BasicMath {
private:
    std::vector<std::string> buttonValues{
            " ln ", "( ", " )", "DEL", "CLR", " log10 ", "1", "2", "3", " + ", " ln ", "4", "5", "6", " - ", " sqrt ",
            "7", "8", "9", " / ", "pi", "0", ".", "=", " * "
    };

public:
    BasicMath();

public:
    std::string calculateExpression(const std::string userInput);
    std::vector<std::string> getButtonValues();

private:
    std::string evaluateExpression(const std::string firstOperand, const std::string anOperator, const std::string secondOperand);
    std::vector<std::string> tokenizeExpression(std::string expression);
    std::vector<std::string> convertToReversePolishNotation(const std::string expression);
    void addElementsOfStackToArray(std::vector<std::string> result, std::stack<std::string> stackOfOperands);
    void addElementsOfStackToArray(std::vector<std::string> result, std::stack<std::string> stackOfOperands, const std::string anOperator);
    bool isOperand(const std::string operandOrOperator);
    int getOrderValue(const std::string anOperator);
    };