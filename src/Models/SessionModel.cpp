#include "SessionModel.h"


SessionModel::SessionModel(const std::string& expression,
                           const double& x_variable,
                           const double& result) {
    this->expression = expression;
    this->x_variable = x_variable;
    this->result = result;
}

double SessionModel::getResult() const {
    return this->result;
}

std::string SessionModel::getExpression() const {
    return this->expression;
}
