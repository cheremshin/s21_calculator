#pragma once
#include <string>


class SessionModel {
public:
    SessionModel(
        const std::string& expression,
        const double& x_variable,
        const double& result);

    // Getters
    double getResult() const;
    std::string getExpression() const;
private:
    std::string expression;
    double x_variable;
    double result;
};
