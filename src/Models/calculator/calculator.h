#ifndef SRC_MODELS_CALCULATOR_H_
#define SRC_MODELS_CALCULATOR_H_

#include <math.h>

#include "../utils/common.h"
#include "../utils/stack.h"


/**
 * @brief Function that calculates expression in RPN
 * 
 * @param expression Expression translated via translator
 * @param x Optional variable (must be passed, when expression have x in it)
 * @return double Result of calculation
 */
double calculate(char *expression, double *x);

/**************************
 *   Internal functions   *
  ************************/

void push_number(stack_c *stack, char *expression, int *i);
void push_x(stack_c *stack, double *x, int *i);
void perform_operation(stack_c *stack, char *expression, int *i);
double perform_binary_operation(stack_c *stack, char operation);
double perform_unary_operation(stack_c *stack, char operation);

#endif // SRC_MODELS_CALCULATOR_H_
