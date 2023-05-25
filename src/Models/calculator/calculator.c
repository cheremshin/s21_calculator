#include "calculator.h"
#include "../utils/common.h"
#include <stdio.h>

double calculate(char *expression) {
    double result = 0;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (is_digit(expression[i])) {
            push_number();
        } else if (is_x(expression[i])) {
            push_x();
        } else {
            perform_operation();
        }
    }

    return result;
}
