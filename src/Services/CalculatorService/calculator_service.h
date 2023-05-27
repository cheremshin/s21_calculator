#ifndef SRC_SERVICES_CALCULATOR_SERVICE_H_
#define SRC_SERVICES_CALCULATOR_SERVICE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>


/**************************
 *       Exit codes       *
 *************************/

#define SUCCESSFUL        0
#define INCORRECT_INPUT   1
#define CALCULATION_ERROR 2

/**
 * @brief Entry point to the algebraic calculator
 * 
 * @param expression Expression to be calculated
 * @param x Optional x variable (can be NULL)
 * @param result Pointer to a variable to store the result
 * @return int Calculation exit code
 */
int calculate_value(char *expression, double *x, double *result);

#ifdef __cplusplus
}
#endif

#endif // SRC_SERVICES_CALCULATOR_SERVICE_H_
