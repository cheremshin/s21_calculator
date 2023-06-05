#include <iostream>
#include <string>
#include <vector>
#include "calculator_service.h"


int main(void) {
    double result = 0;
    std::string expression = "12 + 54 / 7 * cos(1/2)";

    std::vector<char> cstr(expression.c_str(),
                           expression.c_str() + expression.size() + 1u);
    calculate_value(&cstr[0], nullptr, &result);

    std::cout << expression << " = " << result;

    return 0;
}
