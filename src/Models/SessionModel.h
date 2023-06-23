#pragma once
#include <string>


class SessionModel {
public:
    SessionModel(
        const std::string& expression,
        const std::string& result,
        const double& x_variable);

    // Getters
    std::string getResult() const;
    std::string getExpression() const;
private:
    std::string expression;
    std::string result;
    double x_variable;
};
