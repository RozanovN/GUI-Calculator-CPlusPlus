//
// Created by Nikolay on 2022-02-03.
//
#pragma once
#include <wx/wx.h>
#include <stack>

namespace math
{
    class BasicMath {
    private:
        const std::array<std::string, 25> buttonValues {
                " ln ", "( ", " )", "DEL", "CLR", " log10 ", "1", "2", "3", " + ", " ln ", "4", "5", "6", " - ", " sqrt ",
                "7", "8", "9", " / ", "pi", "0", ".", "=", " * "
        };

    public:
        /**
         * Constructs a Basic Math calculator.
         */
        BasicMath() = default;

    public:
        /**
        * Calculates expression.
        *
        * @param userInput a string that represents the expression given by the user
        * @return the result of expression as a string
        */
        std::string calculateExpression(const std::string& userInput, const std::unique_ptr<wxListBox>& stepsField);
        /**
        * Gets button values.
        *
        * @return a vector of strings representing button values
        */
        const std::array<std::string, 25>& getButtonValues() const;

    private:
        std::string evaluateExpression(
            const std::string& firstOperand,
            const std::string& anOperator,
            const std::string& secondOperand,
            const std::unique_ptr<wxListBox>& stepsField
        );
        std::vector<std::string> tokenizeExpression(const std::string& expression);
        std::vector<std::string> convertToReversePolishNotation(const std::string& expression);
        void addElementsOfStackToArray(
            std::vector<std::string>& result,
            std::stack<std::string>& stackOfOperators
        );
        void addElementsOfStackToArray(
            std::vector<std::string>& result,
            std::stack<std::string>& stackOfOperators,
            const std::string& anOperator
        );
        bool isOperand(const std::string& operandOrOperator);
        int getOrderValue(const std::string& anOperator);
        void addSteps(
            const std::string& firstOperand,
            const std::string& anOperator,
            const std::string& secondOperand,
            const std::string& result,
            const std::unique_ptr<wxListBox>& stepsField
        );
    };
}
