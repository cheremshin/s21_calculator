#include "SessionModel.h"


SessionModel::SessionModel(const std::string& expression,
                           const std::string& result,
                           const double& x_variable) {
    this->expression = expression;
    this->result = result;
    this->x_variable = x_variable;
}

std::string SessionModel::getResult() const {
    return this->result;
}

std::string SessionModel::getExpression() const {
    return this->expression;
}
