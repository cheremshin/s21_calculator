#ifndef SRC_SERVICES_CALULATOR_SERVICE_TRANSLATOR_H_
#define SRC_SERVICES_CALULATOR_SERVICE_TRANSLATOR_H_

#include <stdlib.h>

#include "../utils/stack.h"
#include "../utils/common.h"


#define OPERATIONS_COUNT 19

typedef struct operation_priority {
    char operation;
    int priority;
} operation_priority;

extern operation_priority operations_priority[OPERATIONS_COUNT];


/**
 * @brief Function that translates given string
 * in infix notation to polish notation
 * 
 * @param string String to be translated
 * @return char* Translated string (should be freed)
 */
char *translate_to_polish(char *string);

/**************************
 *   Internal functions   *
  ************************/

void process_number(char *string, int *i, stack_c *out);
void process_x(char *string, int *i, stack_c *out);
void process_prefix_function(char *string, int *i, stack_c *operations);
void process_close_bracket(char *string, int *i, stack_c *operations, stack_c *out);
void process_binary_operation(char *string, int *i, stack_c *operations, stack_c *out);

int is_prefix_function(char symbol);

int get_priority(char symbol);
void set_space(stack_c *out);

#endif // SRC_SERVICES_CALULATOR_SERVICE_TRANSLATOR_H_
