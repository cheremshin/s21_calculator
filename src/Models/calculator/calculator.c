#include "calculator.h"
#include "../utils/common.h"
#include <stdio.h>

double calculate(char *expression, double *x) {
    double result = 0;
    stack_c *stack = init_stack(DOUBLE_TYPE);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (is_digit(expression[i])) {
            push_number(stack, expression, &i);
        } else if (is_x(expression[i])) {
            push_x(stack, x, &i);
        } else {
            perform_operation(stack, expression, &i);
        }
        printf("== %d == ", i + 1);
        for (int j = 0; j < stack->top; j++) {
            printf("%f ", stack->elements[j].data.value_d);
            if (j == stack->top - 1) {
                printf("\n");
            }
        }
    }

    pop(stack, &result);
    delete_stack(&stack);

    printf("%f\n", result);

    return result;
}
