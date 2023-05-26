#include "calculator.h"


void push_number(stack_t *stack, char *expression, int *i) {
    double value = 0;
    int met_dot = 0;
    int numbers_after_dot = 0;

    while (expression[*i] != SEPARATOR) {
        if (!met_dot && is_dot(expression[*i])) {
            met_dot = 1;
        } else if (!met_dot) {
            value *= 10;
            value += expression[(*i)++] - '0';
        } else {
            value += (expression[(*i)++] - '0') * pow(10, -(++numbers_after_dot));
        }
    }

    push(stack, &value);
}

void push_x(stack_t *stack, double *x, int *i) {
    push(stack, x);
    (*i)++;
}

void perform_operation(stack_t *stack, char *expression, int *i) {
    double result = 0;
    char operation = expression[*i];

    if (is_binary_operation(operation)) {
        result = perform_binary_operation(stack, operation);
    } else {
        result = perform_unary_operation(stack, operation);
    }

    push(stack, &result);
    (*i)++;
}

double perform_binary_operation(stack_t *stack, char operation) {
    double result = 0, operand_1 = 0, operand_2 = 0;

    pop(stack, &operand_2);
    pop(stack, &operand_1);
    
    switch (operation)
    {
    case '+':
        result = operand_1 + operand_2;
        break;
    case '-':
        result = operand_1 - operand_2;
        break;
    case '*':
        result = operand_1 * operand_2;
        break;
    case '/':
        result = operand_1 / operand_2;
        break;
    case '^':
        result = pow(operand_1, operand_2);
        break;
    case 'm':
        result = fmod(operand_1, operand_2);
        break;
    }

    return result;
}

double perform_unary_operation(stack_t *stack, char operation) {
    double result = 0, operand = 0;
    pop(stack, &operand);

    switch (operation)
    {
    case '~':
        result = operand * (-1);
        break;
    case '$':
        result = operand;
        break;
    case 'c':
        result = cos(operand);
        break;
    case 's':
        result = sin(operand);
        break;
    case 't':
        result = tan(operand);
        break;
    case 'C':
        result = acos(operand);
        break;
    case 'S':
        result = asin(operand);
        break;
    case 'T':
        result = atan(operand);
        break;
    case 'r':
        result = sqrt(operand);
        break;
    case 'n':
        result = log(operand);
        break;
    case 'g':
        result = log10(operand);
        break;
    }

    return result;
}