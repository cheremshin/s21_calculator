#ifndef SRC_MODELS_TRANSLATOR_H_
#define SRC_MODELS_TRANSLATOR_H_

#include <stdlib.h>
#include "../utils/stack.h"


#define SHORTCUTS_COUNT  10
#define OPERATIONS_COUNT 19

typedef struct operation_shortcut {
    char *operation;
    char shortcut;
} operation_shortcut;

typedef struct operation_priority {
    char operation;
    int priority;
} operation_priority;

extern operation_shortcut operation_shortcuts[SHORTCUTS_COUNT];
extern operation_priority operations_priority[OPERATIONS_COUNT];


/**
 * @brief Function that translates given string
 * in infix notation to polish notation
 * 
 * @param string String to be translated
 * @return stack_t Stack consists of char generic data
 */
stack *translate_to_polish(char *string);

void process_number(char *string, int *i, stack *out);
void process_prefix_function(char *string, int *i, stack *operations);
void process_close_bracket(char *string, int *i, stack *operations, stack *out);
void process_binary_operation(char *string, int *i, stack *operations, stack *out);

int is_digit(char symbol);
int is_prefix_function(char symbol);

int get_priority(char symbol);
void set_space(stack *out);

#endif // SRC_MODELS_TRANSLATOR_H_
